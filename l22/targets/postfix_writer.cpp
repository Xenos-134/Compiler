#include <string>
#include <sstream>
#include "targets/type_checker.h"
#include "targets/postfix_writer.h"
#include ".auto/all_nodes.h"  // all_nodes.h is automatically generated
#include "targets/frame_size_calculator.h"



//---------------------------------------------------------------------------

void l22::postfix_writer::do_nil_node(cdk::nil_node * const node, int lvl) {
  // EMPTY
}
void l22::postfix_writer::do_data_node(cdk::data_node * const node, int lvl) {
  // EMPTY
}
void l22::postfix_writer::do_double_node(cdk::double_node * const node, int lvl) {
  if (_inFunctionBody) {
    _pf.DOUBLE(node->value()); // load number to the stack
  } else {
    _pf.SDOUBLE(node->value());    // double is on the DATA segment
  }
}
void l22::postfix_writer::do_not_node(cdk::not_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl + 2);
  _pf.INT(0);
  _pf.EQ();
}
void l22::postfix_writer::do_and_node(cdk::and_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  int lbl = ++_lbl;
  node->left()->accept(this, lvl + 2);
  _pf.DUP32();
  _pf.JZ(mklbl(lbl));
  node->right()->accept(this, lvl + 2);
  _pf.AND();
  _pf.ALIGN();
  _pf.LABEL(mklbl(lbl));
}
void l22::postfix_writer::do_or_node(cdk::or_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  int lbl = ++_lbl;
  node->left()->accept(this, lvl + 2);
  _pf.DUP32();
  _pf.JNZ(mklbl(lbl));
  node->right()->accept(this, lvl + 2);
  _pf.OR();
  _pf.ALIGN();
  _pf.LABEL(mklbl(lbl));
}


// MY DECLARATIONS (START) =====================================================================

void l22::postfix_writer::do_block_node(l22::block_node * const node, int lvl) {
  _symtab.push(); // for block-local vars
  if (node->declarations()) node->declarations()->accept(this, lvl + 2);
  if (node->instructions()) node->instructions()->accept(this, lvl + 2);
  _symtab.pop();
}

void l22::postfix_writer::do_var_declaration_node(l22::var_declaration_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  
  auto id = node->identifier();
  int offset = 0, typesize = node->type()->size(); // in bytes
  std::cout << "ARG: " << id << ", " << typesize << std::endl;

  if (_inFunctionBody) {
    std::cout << "IN BODY" << std::endl;
    _offset -= typesize;
    offset = _offset;
  } else if (_inFunctionArgs) {
    std::cout << "IN ARGS" << std::endl;
    offset = _offset;
    _offset += typesize;
  } else {
    std::cout << "GLOBAL!" << std::endl;
    offset = 0; // global variable
  }
  std::cout << "OFFSET: " << id << ", " << offset << std::endl;

  auto symbol = new_symbol();
  if (symbol) {
    symbol->set_offset(offset);
    reset_new_symbol();
  }

  if (_inFunctionBody) {
      // if we are dealing with local variables, then no action is needed
      // unless an initializer exists
      if (node->initializer()) {
        node->initializer()->accept(this, lvl);
        if (node->type()->name() == (cdk::TYPE_INT) || node->type()->name() ==(cdk::TYPE_STRING) || node->type()->name() == (cdk::TYPE_POINTER)) {
          _pf.LOCAL(symbol->offset());
          _pf.STINT();
        } else if (node->type()->name() == (cdk::TYPE_DOUBLE)) {
          if (node->initializer()->is_typed(cdk::TYPE_INT))
            _pf.I2D();
          _pf.LOCAL(symbol->offset());
          _pf.STDOUBLE();
        } else {
          std::cerr << "cannot initialize" << std::endl;
        }
      } else {
        std::cerr << "(POSTFIX) (VAR_DEC) (VAR_DEC) (BSS) (INSIDE)" << "\n";
        _pf.LOCAL(symbol->offset());
        _pf.SALLOC(typesize);
      }
    } else {
    if (!_function) {
      if (node->initializer() == nullptr) {
        std::cerr << "(POSTFIX) (VAR_DEC) (BSS) (OUTSIDE)" << "\n";
        _pf.BSS();
        _pf.ALIGN();
        _pf.LABEL(id);
        _pf.SALLOC(typesize);
      } else {
        std::cerr << "(POSTFIX) (VAR_DEC) (BSS) (OUTSIDE 2)" << "\n";
        if (node->type()->name() == (cdk::TYPE_INT) || node->type()->name() == (cdk::TYPE_DOUBLE) || node->type()->name() == (cdk::TYPE_POINTER)) {
          if (node->constant()) {
            _pf.RODATA();
          } else {
            _pf.DATA();
          }
          _pf.ALIGN();
          _pf.GLOBAL(id, _pf.OBJ());
          _pf.LABEL(id);
          

          if (node->type()->name() == (cdk::TYPE_INT)) {
            node->initializer()->accept(this, lvl);
          } else if (node->type()->name() == (cdk::TYPE_POINTER)) {
            node->initializer()->accept(this, lvl);
          } else if (node->type()->name() == (cdk::TYPE_DOUBLE)) {
            if (node->initializer()->is_typed(cdk::TYPE_DOUBLE)) {
              node->initializer()->accept(this, lvl);
            } else if (node->initializer()->is_typed(cdk::TYPE_INT)) {
              cdk::integer_node *dclini = dynamic_cast<cdk::integer_node*>(node->initializer());
              cdk::double_node ddi(dclini->lineno(), dclini->value());
              ddi.accept(this, lvl);
            } else {
              std::cerr << node->lineno() << ": '" << id << "' has bad initializer for real value\n";
              _errors = true;
            }
          }
        } else if (node->type()->name() == (cdk::TYPE_STRING)) {
          if (node->constant()) {
            int litlbl;
            // HACK!!! string literal initializers must be emitted before the string identifier
            _pf.RODATA();
            _pf.ALIGN();
            _pf.LABEL(mklbl(litlbl = ++_lbl));
            _pf.SSTRING(dynamic_cast<cdk::string_node*>(node->initializer())->value());
            _pf.ALIGN();
            _pf.LABEL(id);
            _pf.SADDR(mklbl(litlbl));
          } else {
            _pf.DATA();
            _pf.ALIGN();
            _pf.LABEL(id);
            node->initializer()->accept(this, lvl);
          }
        } else if(node->type()->name() == (cdk::TYPE_FUNCTIONAL)){
          std::cerr << "(POSTFIX) (VAR_DEC) (FUN_TYPE)" << "\n";
            _currentFunctionName = id;
           _pf.DATA();
           _pf.ALIGN();
           _pf.GLOBAL(id, _pf.OBJ());
           _pf.LABEL(id);
           int fun_lbl = ++_lbl;
           _pf.SADDR(mklbl(fun_lbl));   
           node->initializer()->accept(this, lvl);
        }
          else {
          std::cerr << node->lineno() << ": '" << id << "' has unexpected initializer\n";
          _errors = true;
        }
      }

    }
  }
}


void l22::postfix_writer::do_stop_node(l22::stop_node * const node, int lvl) {
  if (_forIni.size() != 0) {
    _pf.JMP(mklbl(_forEnd.top())); // jump to for end
  } else {
    error(node->lineno(), "'break' outside 'for'");
  }
    
}


void l22::postfix_writer::do_again_node(l22::again_node * const node, int lvl) {
    if (_forIni.size() != 0) {
      _pf.JMP(mklbl(_forStep.top())); // jump to next cycle
    } else {
      error(node->lineno(), "'restart' outside 'for'");
    }
}


void l22::postfix_writer::do_return_node(l22::return_node * const node, int lvl) {
  std::cerr << "(POSTFIX) (RETURN) (ENTROU)" << "\n";
  _functionType = _functions.top();
  ASSERT_SAFE_EXPRESSIONS;
  //int lbl = ++_lbl;
  std::shared_ptr<cdk::basic_type> funType = _functions.top();
  std::cerr << "(POSTFIX) (RETURN) (ENTROU) (2)" <<  funType->name()  << "\n";
  // should not reach here without returning a value (if not void)
  //FIXE ME: VER se isto nao da uma excepcao
  if (funType->name() != cdk::TYPE_VOID) {

    node->returnValue()->accept(this, lvl + 2);
    
    if ( funType->name() == cdk::TYPE_INT ||  funType->name() == cdk::TYPE_STRING
        ||  funType->name() == cdk::TYPE_POINTER) {
        std::cerr << "(POSTFIX) (RETURN) (ENTROU) (5)" << "\n";
      _pf.STFVAL32();
    } else if (funType->name() == cdk::TYPE_DOUBLE) {
      std::cerr << "(POSTFIX) (RETURN) (ENTROU) (6)" << "\n";
      if (node->returnValue()->type()->name() == cdk::TYPE_INT)
        _pf.I2D();
      _pf.STFVAL64();
    } else {
      std::cerr << node->lineno() << ": should not happen: unknown return type" << std::endl;
    }
  }

  std::cerr << "(POSTFIX) (RETURN) (SAIU)" << "\n";
  //_pf.JMP(_currentBodyRetLabel);
}


void l22::postfix_writer::do_address_of_node(l22::address_of_node * const node, int lvl) {
//EMPTY
}

void l22::postfix_writer::do_input_node(l22::input_node * const node, int lvl) {
//EMPTY
}

void l22::postfix_writer::do_index_node(l22::index_node * const node, int lvl) {
//EMPTY
}

void l22::postfix_writer::do_sizeof_node(l22::sizeof_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;

  _pf.INT(node->expression()->type()->size());
}

void l22::postfix_writer::do_stack_alloc_node(l22::stack_alloc_node * const node, int lvl) {
//EMPTY
}
void l22::postfix_writer::do_identity_node(l22::identity_node * const node, int lvl) {
//EMPTY
}

/*
  SUPONDO QUE ESTAMOS A DEFENIR UMA FUNCAO, HOUVE DECLARACAO DE UMA VARIAVEL, LOGO PODEMOS ACEDER 
  SEU NOME PARA O LABEL
*/
void l22::postfix_writer::do_func_definition_node(l22::func_definition_node * const node, int lvl) {
  if (_inFunctionBody || _inFunctionArgs) {
    error(node->lineno(), "cannot define function in body or in arguments");
    return;
  }

  ASSERT_SAFE_EXPRESSIONS;

  std::cerr << "(FUNC_DEF) entrou!" << "\n";
  //_inFunction = true; 
  _inFunctionBody = true;
  _functions.push(node->retType());
  _function = new_symbol();
  reset_new_symbol();
  _symtab.push();
  _currentBodyRetLabel = mklbl(++_lbl); //Para saber onde retornar

  //POR ENQUANTO ESTOU A TESTAR SEM ARGUMENTOS
  if (node->arguments()->size() > 0) {
    for (size_t ix = 0; ix < node->arguments()->size(); ix++) {
      cdk::basic_node *arg = node->arguments()->node(ix);
      if (arg == nullptr) break;
      arg->accept(this, 0); //
    }
    _inFunctionArgs = false;
  }
  
  _pf.TEXT();
  std::cerr << "(FUNC_DEF) (LABEL)" << mklbl(_lbl - 1) << "\n";
  _pf.ALIGN();
  _pf.LABEL(mklbl(_lbl - 1));  

  //CALCULO DE FRAME_SIZE DEVE SER AQUI
  frame_size_calculator lsc(_compiler, _symtab, _function);
  node->accept(&lsc, lvl);
  _pf.ENTER(lsc.localsize()); // total stack size reserved for local variables



  //INICIALIZACAO DE VARIAVEIS LOCAIS
  if(node->block()->declarations() != nullptr)
    for (size_t ix = 0; ix < node->block()->declarations()->size(); ix++) { 
      node->block()->declarations()->node(ix)->accept(this, 0);
    }


  ///  INICIALIZACAO DE instrucoes LOCAIS 
  if(node->block()->instructions() != nullptr)
    for (size_t ix = 0; ix < node->block()->instructions()->size(); ix++) { 
      node->block()->instructions()->node(ix)->accept(this, 0);
    }
  

  //FAZER AQUI O RET
  _pf.LEAVE();
  _pf.RET();
  _symtab.pop(); // scope of args
  _functions.pop();
  _inFunctionBody = false;


  std::cerr << "(FUNC_DEF) saiu!" << _lbl <<"\n";
}


void l22::postfix_writer::do_function_call_node(l22::function_call_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  std::cerr << "(FUNC_CALL) entrou!" << "\n";

  node->pointer()->accept(this, 0);
  std::cerr << "(FUNC_CALL) NOME DA FUNCAO:" << _currentFunctionName << "\n";
  _pf.BRANCH();
  _pf.LDFVAL32();

  //node->pointer();
  // size_t argsSize = 0;
  // if (node->arguments()->size() > 0) {
  //   for (int ax = node->arguments()->size() - 1; ax >= 0; ax--) {
  //     cdk::expression_node *arg = dynamic_cast<cdk::expression_node*>(node->arguments()->node(ax));
  //     arg->accept(this, lvl + 2);
  //     // if (symbol->argument_is_typed(ax, cdk::TYPE_DOUBLE) && arg->is_typed(cdk::TYPE_INT)) {
  //     //   _pf.I2D();
  //     // }
  //     //argsSize += symbol->argument_size(ax);
  //   }
  // }
  // _pf.CALL(node->identifier());
  // if (argsSize != 0) {
  //   _pf.TRASH(argsSize);
  // }

  // if (symbol->is_typed(cdk::TYPE_INT) || symbol->is_typed(cdk::TYPE_POINTER) || symbol->is_typed(cdk::TYPE_STRING)) {
  //   _pf.LDFVAL32();
  // } else if (symbol->is_typed(cdk::TYPE_DOUBLE)) {
  //   _pf.LDFVAL64();
  // } else {
  //   // cannot happer!
  // }
   std::cerr << "(FUNC_CALL) saiu!" << "\n";

}

void l22::postfix_writer::do_nullptr_node(l22::nullptr_node * const node, int lvl) {
//EMPTY
}



//MY DECLARATIONS (STOP)--------------------------------------------------------------------

void l22::postfix_writer::do_sequence_node(cdk::sequence_node * const node, int lvl) {
  for (size_t i = 0; i < node->size(); i++) {
    node->node(i)->accept(this, lvl);
  }
}

//---------------------------------------------------------------------------

void l22::postfix_writer::do_integer_node(cdk::integer_node * const node, int lvl) {
  if (_inFunctionBody) {
    _pf.INT(node->value()); // integer literal is on the stack: push an integer
  } else {
    _pf.SINT(node->value()); // integer literal is on the DATA segment
  }
}

void l22::postfix_writer::do_string_node(cdk::string_node * const node, int lvl) {
  int lbl1;
  

  /* generate the string literal */
  _pf.RODATA(); // strings are readonly DATA
  _pf.ALIGN(); // make sure the address is aligned
  _pf.LABEL(mklbl(lbl1 = ++_lbl)); // give the string a name
  _pf.SSTRING(node->value()); // output string characters
  if (_inFunctionBody) {
    // local variable initializer
    _pf.TEXT();
    _pf.ADDR(mklbl(lbl1));
    std::cerr << "<<<<<<<<<<<<<<(STRING_NODE)I BELIVE I CAN FLY, I BELIVE I CAN TOUCH THE FRY!" << "\n";
  } else {
    // global variable initializer
    _pf.DATA();
    _pf.SADDR(mklbl(lbl1));
    // _pf.TEXT();
    // _pf.ADDR(mklbl(lbl1));
    std::cerr << ">>>>>>>>>> (STRING_NODE)I BELIVE I CAN FLY, I BELIVE I CAN TOUCH THE FRY!" << "\n";
  }
}

//---------------------------------------------------------------------------

void l22::postfix_writer::do_neg_node(cdk::neg_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl); // determine the value
  _pf.NEG(); // 2-complement
}

//---------------------------------------------------------------------------

void l22::postfix_writer::do_add_node(cdk::add_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.ADD();
}
void l22::postfix_writer::do_sub_node(cdk::sub_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.SUB();
}
void l22::postfix_writer::do_mul_node(cdk::mul_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.MUL();
}
void l22::postfix_writer::do_div_node(cdk::div_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.DIV();
}
void l22::postfix_writer::do_mod_node(cdk::mod_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.MOD();
}
void l22::postfix_writer::do_lt_node(cdk::lt_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.LT();
}
void l22::postfix_writer::do_le_node(cdk::le_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.LE();
}
void l22::postfix_writer::do_ge_node(cdk::ge_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.GE();
}
void l22::postfix_writer::do_gt_node(cdk::gt_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.GT();
}
void l22::postfix_writer::do_ne_node(cdk::ne_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.NE();
}
void l22::postfix_writer::do_eq_node(cdk::eq_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.EQ();
}

//---------------------------------------------------------------------------

void l22::postfix_writer::do_variable_node(cdk::variable_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  const std::string &id = node->name();
  auto symbol = _symtab.find(id);

  if (symbol->global()) {
    _pf.ADDR(symbol->name());
    _currentFunctionName = id;
  } else {
    _pf.LOCAL(symbol->offset());
    //std::cerr << "LVAL " << symbol->name() << ":" << symbol->type()->size() << ":" << symbol->offset() << std::endl;
  }
}

void l22::postfix_writer::do_rvalue_node(cdk::rvalue_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->lvalue()->accept(this, lvl);
  if (node->type()->name() == cdk::TYPE_DOUBLE) {
    _pf.LDDOUBLE();
  } else {
    // integers, pointers, and strings
    _pf.LDINT();
  }
}

void l22::postfix_writer::do_assignment_node(cdk::assignment_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  
  std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>> DO_ASSIGNMENT NODE" << std::endl;
  
  node->rvalue()->accept(this, lvl + 2);
  if (node->type()->name() == cdk::TYPE_DOUBLE) {
    if (node->rvalue()->type()->name() == cdk::TYPE_INT) _pf.I2D();
    _pf.DUP64();
  } else {
    _pf.DUP32();
  }

  node->lvalue()->accept(this, lvl);
  if (node->type()->name() == cdk::TYPE_DOUBLE) {
    _pf.STDOUBLE();
  } else {
    _pf.STINT();
  }
}

//---------------------------------------------------------------------------

void l22::postfix_writer::do_program_node(l22::program_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  // Note that Simple doesn't have functions. Thus, it doesn't need
  // a function node. However, it must start in the main function.
  // The ProgramNode (representing the whole program) doubles as a
  // main function node.
  std::cerr << "(PROGRAM) entrou!" << "\n";
  _functions.push(cdk::primitive_type::create(4, cdk::TYPE_INT));
  _function = new_symbol();
  _inFunctionBody = true;
  reset_new_symbol();
  _symtab.push(); // scope of args
  
  // generate the main function (RTS mandates that its name be "_main")
  _pf.TEXT();
  _pf.ALIGN();
  _pf.GLOBAL("_main", _pf.FUNC());
  _pf.LABEL("_main");

  frame_size_calculator lsc(_compiler, _symtab, _function);
  node->accept(&lsc, lvl);
  _pf.ENTER(lsc.localsize()); // total stack size reserved for local variables
  
  node->statements()->accept(this, lvl);

  // end the main function
  _pf.LEAVE();
  _pf.RET();

  // these are just a few library function imports
  _pf.EXTERN("prints");
  _pf.EXTERN("println");
  _pf.EXTERN("printi");
  _pf.EXTERN("printd");

  _symtab.pop(); // scope of args
  _functions.pop();
  _inFunctionBody = false;

  std::cerr << "(PROGRAM) saiu!" << "\n";
}

//---------------------------------------------------------------------------

void l22::postfix_writer::do_evaluation_node(l22::evaluation_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl);
  //_pf.TRASH(node->argument()->type()->size());
}

void l22::postfix_writer::do_print_node(l22::print_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  std::cerr << "(print) entrou!" << "\n";
  for (size_t ix = 0; ix < node->argument()->size(); ix++) {
    auto child = dynamic_cast<cdk::expression_node*>(node->argument()->node(ix));
    std::shared_ptr<cdk::basic_type> etype = child->type();
    child->accept(this, lvl); // expression to print
    if (etype->name() == cdk::TYPE_INT) {
      _functions_to_declare.insert("printi");
      _pf.CALL("printi");
      _pf.TRASH(4); // trash int
    } else if (etype->name() == cdk::TYPE_DOUBLE) {
      _functions_to_declare.insert("printd");
      _pf.CALL("printd");
      _pf.TRASH(8); // trash double
    } else if (etype->name() == cdk::TYPE_STRING) {
      _functions_to_declare.insert("prints");
      _pf.CALL("prints");
      _pf.TRASH(4); // trash char pointer
    } else {
      std::cerr << "cannot print expression of unknown type" << std::endl;
      return;
    }
  }

  if (node->newline()) {
    _functions_to_declare.insert("println");
    _pf.CALL("println");
  }

  std::cerr << "(PRINT) saiu!" << _lbl <<"\n";
}

//---------------------------------------------------------------------------

void l22::postfix_writer::do_while_node(l22::while_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  std::cout<<"YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY____WHILE:";

  int lbl1, lbl2;
  _pf.LABEL(mklbl(lbl1 = ++_lbl));
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(lbl2 = ++_lbl));
  node->block()->accept(this, lvl + 2);
  _pf.JMP(mklbl(lbl1));
  _pf.LABEL(mklbl(lbl2));
  std::cout<<"YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY____WHILE:"<<lbl1<<lbl2;
}

//---------------------------------------------------------------------------

void l22::postfix_writer::do_if_node(l22::if_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  int lbl1;
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(lbl1 = ++_lbl));
  node->block()->accept(this, lvl + 2);
  _pf.LABEL(mklbl(lbl1));
}

//---------------------------------------------------------------------------

void l22::postfix_writer::do_if_else_node(l22::if_else_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  int lbl1, lbl2;
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(lbl1 = ++_lbl));
  node->thenblock()->accept(this, lvl + 2);
  _pf.JMP(mklbl(lbl2 = ++_lbl));
  _pf.LABEL(mklbl(lbl1));
  node->elseblock()->accept(this, lvl + 2);
  _pf.LABEL(mklbl(lbl1 = lbl2));
}