%{
//-- don't change *any* of these: if you do, you'll break the compiler.
#include <algorithm>
#include <memory>
#include <cstring>
#include <cdk/compiler.h>
#include <cdk/types/types.h>
#include ".auto/all_nodes.h"
#define LINE                         compiler->scanner()->lineno()
#define yylex()                      compiler->scanner()->scan()
#define yyerror(compiler, s)         compiler->scanner()->error(s)
//-- don't change *any* of these --- END!

#define NIL (new cdk::nil_node(LINE))
%}

%parse-param {std::shared_ptr<cdk::compiler> compiler}

%union {
  //--- don't change *any* of these: if you do, you'll break the compiler.
  YYSTYPE() : type(cdk::primitive_type::create(0, cdk::TYPE_VOID)) {}
  ~YYSTYPE() {}
  YYSTYPE(const YYSTYPE &other) { *this = other; }
  YYSTYPE& operator=(const YYSTYPE &other) { type = other.type; return *this; }

  std::shared_ptr<cdk::basic_type> type;        /* expression type */
  //-- don't change *any* of these --- END!

  int                   i;	/* integer value */
  double                d;  /* integer value */
  std::string          *s;	/* symbol name or string literal */

  cdk::basic_node      *node;	/* node pointer */
  cdk::sequence_node   *sequence;
  cdk::expression_node *expression; /* expression nodes */
  cdk::basic_type      *expr_type; /* expression nodes */
  cdk::lvalue_node     *lvalue;
  l22::block_node      *block;

  std::vector<std::shared_ptr<cdk::basic_type>> *types;
};

%token <i> tINTEGER

%token <d> tREAL
%token tAND tOR tNE tLE tGE tSIZEOF tNOT
%token tWHILE tREAD tBEGIN tEND
%token tTYPE_STRING tTYPE_INT tTYPE_REAL tTYPE_POINTER tTYPE_AUTO tTYPE_VOID
%token tRETURN
%token tPUBLIC tUSE tFOREIGN tPRIVATE
%token tVAR
%token tDO tSTOP tAGAIN
%token tIF tTHEN tELIF tELSE
%token tINPUT tWRITE tWRITELN

%token <s> tIDENTIFIER tSTRING


%token<expression> tNULLPTR;



%nonassoc tIF
%nonassoc tTHEN
%nonassoc tELIF tELSE

%right '='
%left tOR
%left tAND
%right tNOT
%left tNE tEQ
%left '<' tLE tGE '>'
%left '+' '-'
%left '*' '/' '%'
%left '{' '[' '('
%right '}' ']' ')'
%right tUNARY


%type <node> stmt fundef argdec program elif fundec
%type <sequence> argdecs opt_vardecs opt_instructions instructions vardecs expressions file funcal_exr
%type <expression> expr opt_initializer integer real rec_fun_cal fundeff
%type <lvalue> lval
%type <block> block
%type <type> data_type function_type basic_type
%type <node> declaration vardec
%type <sequence> declarations
%type <types> data_types
%type<s> string
%type<i> identifiers

%{
//-- The rules below will be included in yyparse, the main parsing function.
%}
%%

file         : /* empty */  { compiler->ast($$ = new cdk::sequence_node(LINE)); }
             | declarations { compiler->ast($$ = $1); }
             ;

declarations :              declaration { $$ = new cdk::sequence_node(LINE, $1);     }
             | declarations declaration { $$ = new cdk::sequence_node(LINE, $2, $1); }

declaration : vardec     { $$ = $1;}
            | fundef     { $$ = $1;}
            | fundec     { $$ = $1;}
            | program    { $$ = $1;}
            ;


fundec   : tFOREIGN data_type tIDENTIFIER     { $$ = new l22::var_declaration_node(LINE, tPRIVATE,  $2, *$3, nullptr);}
         |          data_type tIDENTIFIER     { $$ = new l22::var_declaration_node(LINE, tPRIVATE,  $1, *$2, nullptr);}
         | tUSE     data_type tIDENTIFIER     { $$ = new l22::var_declaration_node(LINE, tPRIVATE,  $2, *$3, nullptr);}
         ;

fundeff : '(' argdecs ')' '-' '>' data_type ':' block      { $$ = new l22::func_definition_node(LINE, $2, $8, $6); }
        ;

fundef   : identifiers tIDENTIFIER '=' fundeff              { $$ = new l22::var_declaration_node(LINE, $1,  nullptr, *$2, $4);}
         ;


vardec :  identifiers data_type tIDENTIFIER  opt_initializer           { $$ = new l22::var_declaration_node(LINE, $1,  $2, *$3, $4); }
       |         data_type tIDENTIFIER  opt_initializer               { $$ = new l22::var_declaration_node(LINE, tPRIVATE,  $1, *$2, $3); }
       | identifiers             tIDENTIFIER  opt_initializer         { $$ = new l22::var_declaration_node(LINE, $1,  nullptr, *$2, $3); }
       ;

opt_initializer  : /* empty */          { $$ = nullptr; }
                 | '=' expr             { $$ = $2; }
                 ;

                 
identifiers: tVAR   { $$ = tPRIVATE;}
          | tPUBLIC { $$ = tPUBLIC; }
          ;


program	: tBEGIN block tEND { $$ = new l22::program_node(LINE, $2); }
	     ;


block: '{'            opt_instructions '}' {
         $$ = new l22::block_node(LINE, nullptr, $2);
     }
     | '{' opt_vardecs opt_instructions '}' {
         $$ = new l22::block_node(LINE, $2, $3);
     }
     ;

opt_vardecs  : /* empty */ { $$ = NULL; }
             | vardecs     { $$ = $1; }
             ;

opt_instructions: /* empty */           { $$ = NULL; }      /* | stmt { $$ = $1; }*/
                | instructions          { $$ = $1; }
                ;

vardecs      : vardec  ';'              { $$ = new cdk::sequence_node(LINE, $1);     }
             | vardec                   { $$ = new cdk::sequence_node(LINE, $1);     }
             | fundef                   { $$ = new cdk::sequence_node(LINE, $1);     }
             | fundec ';'               { $$ = new cdk::sequence_node(LINE, $1);     }
             | vardecs vardec ';'       { $$ = new cdk::sequence_node(LINE, $2, $1); }
             | vardecs fundec ';'       { $$ = new cdk::sequence_node(LINE, $2, $1); }
             | vardecs vardec           { $$ = new cdk::sequence_node(LINE, $2, $1); }
             | vardecs fundef           { $$ = new cdk::sequence_node(LINE, $2, $1); }
             | vardecs fundec           { $$ = new cdk::sequence_node(LINE, $2, $1); }
             ;


instructions    : stmt                  { $$ = new cdk::sequence_node(LINE, $1);}
                | instructions stmt     { $$ = new cdk::sequence_node(LINE, $2, $1);}
                ;



argdecs  : /* empty */         { $$ = new cdk::sequence_node(LINE);  }
         |             argdec  { $$ = new cdk::sequence_node(LINE, $1);}
         | argdecs ',' argdec  { $$ = new cdk::sequence_node(LINE, $3, $1); } 
         ;


argdec   : data_type tIDENTIFIER    { $$ = new l22::var_declaration_node(LINE, tPRIVATE, $1, *$2, nullptr);}
         ;                              


data_type                : basic_type                                                  { $$ = $1; }
                         | function_type                                               { $$ = $1; }
                         ;


basic_type   : tTYPE_STRING                     { $$ = cdk::primitive_type::create(4, cdk::TYPE_STRING);  }
             | tTYPE_INT                        { $$ = cdk::primitive_type::create(4, cdk::TYPE_INT);     }
             | tTYPE_REAL                       { $$ = cdk::primitive_type::create(8, cdk::TYPE_DOUBLE);  }
             | tTYPE_VOID                       { $$ = cdk::primitive_type::create(4, cdk::TYPE_VOID);  }
             | '[' data_type ']'                { $$ = cdk::reference_type::create(4, $2); }
             ;

function_type            : data_type '<' data_types '>'               { $$ = cdk::functional_type::create(*$3, $1); }
                         | data_type '<' '>'                          { $$ = cdk::functional_type::create($1); }
                         ;

data_types               : data_type                                  { $$ = new std::vector<std::shared_ptr<cdk::basic_type>>(); $$->push_back($1); }
                         | data_types ',' data_type                   { $$ = $1; $$->push_back($3);}
                         ;


stmt : expr ';'                                               { $$ = new l22::evaluation_node(LINE, $1); }
     | expr                                                   { $$ = new l22::evaluation_node(LINE, $1); }
     | tIF expr tTHEN block                                   { $$ = new l22::if_node(LINE, $2, $4); }
     | tIF expr tTHEN block elif                              { $$ = new l22::if_else_node(LINE, $2, $4, $5); }
     | tWHILE '(' expr ')' tDO block                          { $$ = new l22::while_node(LINE, $3, $6); }
     | tSTOP ';'                                              { $$ = new l22::stop_node(LINE); }
     | tAGAIN ';'                                             { $$ = new l22::again_node(LINE); }
     | tINPUT ';'                                             { $$ = new l22::input_node(LINE);}
     | tRETURN expr ';'                                       { $$ = new l22::return_node(LINE, $2); }
     | tRETURN expr                                           { $$ = new l22::return_node(LINE, $2); }
     | tELSE stmt                                             { $$ = $2; }
     | tWRITE expressions ';'                                 { $$ = new l22::print_node(LINE, $2, false);}
     | tWRITELN expressions ';'                               { $$ = new l22::print_node(LINE, $2, true);}
     | rec_fun_cal ';'                                        { $$ = $1; }
     ;



funcal_exr : expr                                 { $$ = new cdk::sequence_node(LINE, $1);     }
           | fundef                               { $$ = new cdk::sequence_node(LINE, $1); }
           | '(' expr ')'                         { $$ = new cdk::sequence_node(LINE, $2);     }
           | '(' fundef ')'                       { $$ = new cdk::sequence_node(LINE, $2); }
           | funcal_exr ',' fundef                { $$ = new cdk::sequence_node(LINE, $3, $1); }
           | funcal_exr ',' expr                  { $$ = new cdk::sequence_node(LINE, $3, $1); }
           | funcal_exr ',' '(' fundef ')'        { $$ = new cdk::sequence_node(LINE, $4, $1); }
           | funcal_exr ',' '(' expr ')'          { $$ = new cdk::sequence_node(LINE, $4, $1); }
           | funcal_exr '(' expr ')'              { $$ = new cdk::sequence_node(LINE, $3, $1); }
           ;

rec_fun_cal  : '@' '(' funcal_exr ')' { $$ = new l22::function_call_node(LINE, $3);}
             | '@' '(' ')'            { $$ = new l22::function_call_node(LINE);}
             ;  


elif            : tELSE block                      { $$ = $2; }
                | tELIF expr tTHEN block           { $$ = new l22::if_node(LINE, $2, $4); }
                | tELIF expr tTHEN block elif      { $$ = new l22::if_else_node(LINE, $2, $4, $5); }
                ;


expressions     : expr                            { $$ = new cdk::sequence_node(LINE, $1);     }
                | expressions ',' expr            { $$ = new cdk::sequence_node(LINE, $3, $1); }
                ;



expr : integer                          { $$ = $1; }
     | real                             { $$ = $1; }
	| string                           { $$ = new cdk::string_node(LINE, $1); }
     | tNULLPTR                         { $$ = new l22::nullptr_node(LINE); }
     | tNOT expr                        { $$ = new cdk::not_node(LINE, $2); }
     | tSIZEOF '(' expr ')'             { $$ = new l22::sizeof_node(LINE, $3); }
     | '[' expr ']'                     { $$ = new l22::stack_alloc_node(LINE, $2); }
     | lval '=' expr                    { $$ = new cdk::assignment_node(LINE, $1, $3); }
     | '-' '-' expr %prec tUNARY        { $$ = $3; }
     | '-' expr %prec tUNARY            { $$ = new cdk::neg_node(LINE, $2); }
     | '+' expr %prec tUNARY            { $$ = $2; }
     | expr '+' expr	               { $$ = new cdk::add_node(LINE, $1, $3); }
     //! Provavelmente está errado, n faço nada com o (expr) final
     | '(' fundeff ')' expr	          { $$ = $2; }
     | fundeff	                         { $$ = $1; }
     | expr '-' expr	               { $$ = new cdk::sub_node(LINE, $1, $3); }
     | expr '*' expr	               { $$ = new cdk::mul_node(LINE, $1, $3); }
     | expr '/' expr	               { $$ = new cdk::div_node(LINE, $1, $3); }
     | expr '%' expr	               { $$ = new cdk::mod_node(LINE, $1, $3); }
     | expr '<' expr	               { $$ = new cdk::lt_node(LINE, $1, $3); }
     | expr '>' expr	               { $$ = new cdk::gt_node(LINE, $1, $3); }
     | expr tGE expr	               { $$ = new cdk::ge_node(LINE, $1, $3); }
     | expr tLE expr                    { $$ = new cdk::le_node(LINE, $1, $3); }
     | expr tNE expr	               { $$ = new cdk::ne_node(LINE, $1, $3); }
     | expr tEQ expr	               { $$ = new cdk::eq_node(LINE, $1, $3); }
     | expr tAND expr	               { $$ = new cdk::and_node(LINE, $1, $3); }
     | expr tOR expr	               { $$ = new cdk::or_node(LINE, $1, $3); }
     | '(' expr ')'                     { $$ = $2; }
     | lval                             { $$ = new cdk::rvalue_node(LINE, $1); }
     | lval '?'                         { $$ = new l22::address_of_node(LINE, $1); }
     | lval '(' funcal_exr ')'          { $$ = new l22::function_call_node(LINE, new cdk::rvalue_node(LINE, $1), $3);}
     | lval '(' ')'                     { $$ = new l22::function_call_node(LINE, new cdk::rvalue_node(LINE, $1));}
     | rec_fun_cal                      { $$ = $1; }
     ;

lval : tIDENTIFIER                 { $$ = new cdk::variable_node(LINE, $1); }
     | expr '[' expr ']'           { $$ = new l22::index_node(LINE, $1, $3); }
     ;


integer         : tINTEGER                      { $$ = new cdk::integer_node(LINE, $1); };
real            : tREAL                         { $$ = new cdk::double_node(LINE, $1); };
string          : tSTRING                       { $$ = $1; }
                | string tSTRING                { $$ = $1; $$->append(*$2); delete $2; }
                ;
%%






