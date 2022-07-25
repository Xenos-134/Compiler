%option c++ prefix="l22_scanner_" outfile="l22_scanner.cpp"
%option stack noyywrap yylineno 8bit debug
%{ 
// make relevant includes before including the parser's tab file
#include <string>
#include <vector>
#include <deque>
#include <sstream>
#include <cdk/ast/sequence_node.h>
#include <cdk/ast/expression_node.h>
#include <cdk/ast/lvalue_node.h>
#include "l22_parser.tab.h"


// don't change this
#define yyerror LexerError


static bool restart_functions = false;



static int lLevelsToPop = 0, lIndex = 0;
static std::vector<int> indents;   // known indentation levels
static std::vector<int> deferred;  // deferred tokens

// output stream for building string literals
static std::ostringstream strlit;

static std::deque<int> tokenq;



inline bool valid(int indent) {
    lLevelsToPop = lIndex = -1;
    bool indentOk = false;
    for (size_t ix = 0; ix < indents.size(); ix++) {
        if (indent == indents[ix]) {
            lLevelsToPop = indents.size() - ix - 1;
            lIndex = ix;
            indentOk = true;
        }
    }
    return indentOk;
}


%}

SPACE     [ \t]
INT       [[:digit:]]+

LETTER  [A-Za-z]
IDENTIFIER   {LETTER}({LETTER}|[[:digit:]])*

%x X_COMMENT
%x X_STRING X_BACKSLASH
%x X_NEWLINE
%%
  yydebug=1;
  
  {
        //std::cerr << "################" << std::endl;
        if (restart_functions) {
          std::cerr << "POPPING FUNCTIONS (" << indents.size() << ")" << std::endl;
          indents.pop_back();
          if (indents.size() == 0) restart_functions = false;
          return '}';
        }
        else {
          if (lLevelsToPop > 0) {
            std::cerr << "POPPING LEVELS (" << lLevelsToPop << ")" << std::endl;
            lLevelsToPop--;
            indents.pop_back();
            return '}';
          }
        }  
    }
  {
      std::cerr << "#######################" << std::endl;      
  }

  {
    if (!tokenq.empty()) {
      int token = tokenq.front();
      tokenq.pop_front();
      std::cerr << "Returning " << std::endl;
      return token;
    }
  }

  /* ====================================================================== */
  /* ====[                      2.2 - COMMENTS                        ]==== */
  /* ====================================================================== */

";".*$                std::cerr << "We found a comment" << std::endl;/* match the whole line (it is ignored) */

"(*"                   yy_push_state(X_COMMENT);
<X_COMMENT>"*)"        yy_pop_state();
<X_COMMENT>.|"\n"      ;  /* ignore inside comments */

  /* ====================================================================== */
  /* ====[                      2.2 - INDENTATION                     ]==== */
  /* ====================================================================== */


":"  return *yytext;

\n                   {std::cerr << "new line!" << std::endl; yy_push_state(X_NEWLINE);} /* delay decision */

<X_NEWLINE>^{SPACE}+  {
    yy_pop_state();
    std::cerr << "JOining" << std::endl;
    if (valid(yyleng)) {
      std::cerr << "CASE 1" << std::endl;
      if (lLevelsToPop == 0) {
        // at the same level: ignore index
        // do not return tINDENT;
        std::cerr << "CASE 1a (levels to pop = 0)" << std::endl;
        return ';';
      }
      else {
        // nothing is done here: the scanner will ignore the input while levels > 0
        // and send block-end tokens to the parser
        std::cerr << "CASE 1b (levels to pop = " << lLevelsToPop << ")" << std::endl;
        // at least one has to be returned here...
        if (lLevelsToPop > 0) {
          std::cerr << "POPPING LEVELS (" << lLevelsToPop << ")" << std::endl;
          lLevelsToPop--;
          indents.pop_back();
          tokenq.push_back('}');
          return ';';
        }
      }
    }
    else if (indents.size() == 0) {
          // first block to open
          std::cerr << "CASE 2" << std::endl;
          indents.push_back(yyleng);
          std::cerr << "returning {" << std::endl;
          return '{';
    }
    else if (yyleng > indents.back()) {
          // this is like the one before, but not the first
          std::cerr << "CASE 3" << std::endl;
          indents.push_back(yyleng);
          std::cerr << "returning {" << std::endl;
          return '{';
    }
    else {
          // something wrong: bad indent: communicate to user
          std::cerr << "CASE 4" << std::endl;
          std::cerr << "bad indent at line " << yylineno;
    }

}
<X_NEWLINE>\n      ; // ignore successive newline chars
<X_NEWLINE>.       {
  
  // in this case, we have a new function starting
  // first, return whatever we are seeing to the input
  yyless(0);
  yy_pop_state();
  if (indents.size() > 0) {
    std::cerr << "should restart " << indents.size() << " functions at " << yylineno << std::endl;
  
    indents.pop_back();    
    if (indents.size() > 0) { restart_functions = true; }
    std::cerr << "returning ;" << std::endl;
    tokenq.push_back('}');

    return ';';
  }
  else{
    //std::cerr << "returning ;" << std::endl;
    //return ';'; // top-level declarations
  }
}

  /* ====================================================================== */
  /* ====[                  1.1   - Tipos de dados                    ]==== */
  /* ====[                  1.1   - Null pointers                     ]==== */
  /* ====[                  1.1   - Procedures                        ]==== */
  /* ====================================================================== */

"int"                   return tTYPE_INT;
"double"                return tTYPE_REAL;
"text"                  return tTYPE_STRING;
"void"                  return tTYPE_VOID;       

[<>]                    return *yytext;

"null"                  return tNULLPTR;
"sizeof"                return tSIZEOF;

  /* ====================================================================== */
  /* ====[                  3.4.2 - Símbolos globais                  ]==== */
  /* ====================================================================== */

"public"                return tPUBLIC;
"use"                   return tUSE;
"foreign"               return tFOREIGN;
"var"                   return tVAR;

  /* ====================================================================== */
  /* ====[                 5.5 - Instrução condicional                ]==== */
  /* ====================================================================== */

"if"                    return tIF;
"then:"                 return tTHEN;
"elif"                  return tELIF;
"else:"                 return tELSE;

  /* ====================================================================== */
  /* ====[                 5.5 - Instrução de iteração                ]==== */
  /* ====[                 5.5 - Instrução de terminação              ]==== */
  /* ====[                 5.4 - Instrução de continuação             ]==== */
  /* ====================================================================== */

"while"                 return tWHILE;
"do:"                   return tDO;
"stop"                  return tSTOP;
"again"                 return tAGAIN;

  /* ====================================================================== */
  /* ====[                 6 - Operadores de expressões               ]==== */
  /* ====================================================================== */

[\[\](),?]              return *yytext;
[-+*/%<>@?=]            return *yytext;
"not"                   return tNOT;
"=="                    return tEQ;
"!="                    return tNE;
"<="                    return tLE;
">="                    return tGE;
"and"                   return tAND;
"or"                    return tOR;
"input"                 return tINPUT;

  /* ====================================================================== */
  /* ====[              3   - Delimitadores e separadores             ]==== */
  /* ====[              4.3 - Corpo (de função)                       ]==== */
  /* ====[                 5.3 - Instrução de retorno                 ]==== */
  /* ====================================================================== */

"return"                return tRETURN;
"write"                 return tWRITE;
"writeln"               return tWRITELN;

"begin"                 std::cerr << "This is a beggining to the new age!" << std::endl; return tBEGIN; 
"end"                   return tEND; 


  /* ====================================================================== */
  /* ====[                   2.7.1 - inteiros                         ]==== */
  /* ====================================================================== */

0[0-6]+                 yylval.i = strtoul(yytext, NULL, 7); if(errno == ERANGE) yyerror("Invalid number range, overflow occurred"); return tINTEGER;;
0[0-9]+                 yyerror("Invalid base 7 number.");

0|[1-9][0-9]*           yylval.i = strtoul(yytext, NULL, 10); if(errno == ERANGE) yyerror("Invalid number range, overflow occurred"); return tINTEGER;;


  /* ====================================================================== */
  /* ====[                   2.7.2 - reais                            ]==== */
  /* ====================================================================== */

[0-9]+"."[0-9]+  { try { yylval.d = std::strtod(yytext, NULL); 
                         return tREAL; 
                       } catch (std::out_of_range& e) { yyerror("Real out of range."); }
                 }

[0-9]+"."        { try { yylval.d = std::strtod(yytext, NULL); 
                         return tREAL; 
                       } catch (std::out_of_range& e) { yyerror("Real out of range."); }
                 }

"."[0-9]+        { try { yylval.d = std::strtod(yytext, NULL); 
                         return tREAL; 
                       } catch (std::out_of_range& e) { yyerror("Real out of range."); }
                 }

[0-9]+("."[0-9]+)?[Ee][-+]?[0-9]+  { try { yylval.d = std::strtod(yytext, NULL); 
                                           return tREAL; 
                                         } catch (std::out_of_range& e) { yyerror("Real out of range."); }
                                   }

  /* ====================================================================== */
  /* ====[                2.6 - Identificadores (nomes)               ]==== */
  /* ====================================================================== */

{IDENTIFIER}  {std::cerr << "New identifier: " << yytext << std::endl; yylval.s = new std::string(yytext); return tIDENTIFIER;}

  /* ====================================================================== */
  /* ====[              2.7.3 - Cadeias de caracteres                 ]==== */
  /* ====================================================================== */

"\""                    yy_push_state(X_STRING);
<X_STRING>\\            yy_push_state(X_BACKSLASH);
<X_STRING>"\""         {
                         yylval.s = new std::string(strlit.str());
                         strlit.str("");
                         yy_pop_state();
                         return tSTRING;
                       }
<X_STRING>.             strlit << *yytext;

<X_BACKSLASH>n          strlit << '\n'; yy_pop_state();
<X_BACKSLASH>r          strlit << '\r'; yy_pop_state();
<X_BACKSLASH>t          strlit << '\t'; yy_pop_state();
<X_BACKSLASH>\\         strlit << '\\'; yy_pop_state();

<X_BACKSLASH>[0-6]{1,3} {
                                 strlit << (char)(unsigned char)strtoul(yytext, NULL, 7);
                                 yy_pop_state();
                               }
<X_BACKSLASH>.          strlit << *yytext; yy_pop_state();


  /* ====================================================================== */
  /* ====[                    (other characters)                      ]==== */
  /* ====================================================================== */

<<EOF>>                {
  std::cout << "AT <<EOF>> OPEN INDENTS ARE " << indents.size() << std::endl;
  if (indents.size() > 0) {
    indents.pop_back();
    return '}';
  }
  return 0;  // nothing left to do: tell parser to proceed
}

[[:space:]]         /* ignore remaining white space inside the program */
.                      yyerror(yytext);    /* all other chars: error! */


  /* ====================================================================== */
  /* ====[                           THE END                          ]==== */
  /* ====================================================================== */
  

%%
