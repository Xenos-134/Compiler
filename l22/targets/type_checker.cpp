#include <string>
#include "targets/type_checker.h"
#include ".auto/all_nodes.h"  // automatically generated
#include <cdk/types/primitive_type.h>

#include <cdk/types/types.h>
#include "l22_parser.tab.h"


#define ASSERT_UNSPEC { if (node->type() != nullptr && !node->is_typed(cdk::TYPE_UNSPEC)) return; }


void l22::type_checker::do_BooleanLogicalExpression(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  if (!node->left()->is_typed(cdk::TYPE_INT)) {
    throw std::string("integer expression expected in binary expression");
  }

  node->right()->accept(this, lvl + 2);
  if (!node->right()->is_typed(cdk::TYPE_INT)) {
    throw std::string("integer expression expected in binary expression");
  }

  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

//---------------------------------------------------------------------------

void l22::type_checker::do_sequence_node(cdk::sequence_node *const node, int lvl) {
  for (size_t i = 0; i < node->size(); i++)
    node->node(i)->accept(this, lvl);
}

//---------------------------------------------------------------------------

void l22::type_checker::do_nil_node(cdk::nil_node *const node, int lvl) {
  // EMPTY
}
void l22::type_checker::do_data_node(cdk::data_node *const node, int lvl) {
  // EMPTY
}
void l22::type_checker::do_double_node(cdk::double_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
}
void l22::type_checker::do_not_node(cdk::not_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl + 2);
  if (node->argument()->is_typed(cdk::TYPE_INT)) {
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  } else if (node->argument()->is_typed(cdk::TYPE_UNSPEC)) {
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    node->argument()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  } else {
    throw std::string("wrong type in unary logical expression");
  }
}
void l22::type_checker::do_and_node(cdk::and_node *const node, int lvl) {
  do_BooleanLogicalExpression(node, lvl);

}
void l22::type_checker::do_or_node(cdk::or_node *const node, int lvl) {
  do_BooleanLogicalExpression(node, lvl);
}



// OUR NODES (START) ========================================================================


void l22::type_checker::do_block_node(l22::block_node *const node, int lvl) {
  // EMPTY
}


void l22::type_checker::do_var_declaration_node(l22::var_declaration_node *const node, int lvl) {
  std::cerr << "(TYPE_CHECKER)(VAR_DEC) ENTROU!" << "\n";
  if (node->initializer() != nullptr) {
    
    node->initializer()->accept(this, lvl + 2);
    if(node->type() == nullptr ){
      //É auto
      std::cerr << "(TYPE_CHECKER)(VAR_DEC) É null!" << "\n";
      node->type(node->initializer()->type());
    }
    else if (node->initializer()->type()->name() == cdk::TYPE_FUNCTIONAL){
      auto func_type_return = cdk::functional_type::cast(node->initializer()->type())->output()->component(0);
      if(func_type_return->name() != node->type()->name())
        throw std::string("error id = 10: wrong type for initializer.");
    }
    else if (node->type()->name() == cdk::TYPE_INT) {
      if (!node->initializer()->is_typed(cdk::TYPE_INT)) throw std::string("(VAR_DEC) wrong type for initializer (integer expected).");
    } else if (node->type()->name() == cdk::TYPE_DOUBLE) {
      if (!node->initializer()->is_typed(cdk::TYPE_INT) && !node->initializer()->is_typed(cdk::TYPE_DOUBLE)) {
        throw std::string("wrong type for initializer (integer or double expected).");
      }
    } else if (node->type()->name() == cdk::TYPE_STRING) {
      if (!node->initializer()->is_typed(cdk::TYPE_STRING)) {
        throw std::string("wrong type for initializer (string expected).");
      }
    } else if (node->type()->name() == cdk::TYPE_POINTER) {
      //DAVID: FIXME: trouble!!!
      if (!node->initializer()->is_typed(cdk::TYPE_POINTER)) {
        auto in = (cdk::literal_node<int>*)node->initializer();
        if (in == nullptr || in->value() != 0) throw std::string("wrong type for initializer (pointer expected).");
      }
    } else if(node->type()->name() == cdk::TYPE_FUNCTIONAL){
      std::cerr << "(TYPE_CHECKER)(VAR_DEC) Sou de tipo funcional!" << "\n";
      if (node->initializer()->type() != node->type()) {
        throw std::string("wrong type for initializer (function expected).");
      }

    }
    else {
      throw std::string("(TYPE_CHECKER)(VAR_DEC) unknown type for initializer.");
    }
    std::cerr << "(TYPE_CHECKER)(VAR_DEC) SAIU!" << "\n";
  }

  const std::string &id = node->identifier();
  auto symbol = l22::make_symbol(false, node->qualifier(), node->type(), id, (bool)node->initializer(), false);

  if (_symtab.insert(id, symbol)) {
    _parent->set_new_symbol(symbol);  // advise parent that a symbol has been inserted
  } else {
    throw std::string("variable '" + id + "' redeclared");
  }
  std::cerr << "(TYPE_CHECKER)(var_declaration) SAIU!" << "\n";
}

void l22::type_checker::do_stop_node(l22::stop_node *const node, int lvl) {
  // EMPTY
}

void l22::type_checker::do_again_node(l22::again_node *const node, int lvl) {
  // EMPTY
}

void l22::type_checker::do_return_node(l22::return_node *const node, int lvl) {
  if (node->returnValue()) {
    if (_functionType != nullptr && _functionType->name() == cdk::TYPE_VOID) throw std::string(
        "initializer specified for void function.");
    std::cerr << "(TYPE_CHECKER)(RETURN) entrou!" << "\n";
    node->returnValue()->accept(this, lvl + 2);

    // function is auto: copy type of first return expression
    if (_functionType == nullptr) {
      _function->set_type(node->returnValue()->type());
      return; // simply set the type
    }

    std::cout << "(TYPE_CHECKER)FUNCT TYPE " << (_functionType->name() == cdk::TYPE_FUNCTIONAL ? "functional function" : cdk::to_string(_functionType)) << std::endl;
    std::cout << "(TYPE_CHECKER)RETVAL TYPE " << (node->returnValue()->is_typed(cdk::TYPE_FUNCTIONAL) ? "functional return" : cdk::to_string(node->returnValue()->type())) << std::endl;
    if (_functionType->name() == cdk::TYPE_INT) {
      if (!node->returnValue()->is_typed(cdk::TYPE_INT)) throw std::string("(RETURN) wrong type for initializer (integer expected).");
    } else if (_functionType->name() == cdk::TYPE_DOUBLE) {
      if (!node->returnValue()->is_typed(cdk::TYPE_INT) && !node->returnValue()->is_typed(cdk::TYPE_DOUBLE)) {
        throw std::string("wrong type for initializer (integer or double expected).");
      }
    } else if (_functionType->name() == cdk::TYPE_STRING) {
      if (!node->returnValue()->is_typed(cdk::TYPE_STRING)) {
        throw std::string("wrong type for initializer (string expected).");
      }
    } else if (_functionType->name() == cdk::TYPE_POINTER) {
      //DAVID: FIXME: trouble!!!
      int ft = 0, rt = 0;
      auto ftype = _functionType;
      while (ftype->name() == cdk::TYPE_POINTER) {
        ft++;
        ftype = cdk::reference_type::cast(ftype)->referenced();
      }
      auto rtype = node->returnValue()->type();
      while (rtype != nullptr && rtype->name() == cdk::TYPE_POINTER) {
        rt++;
        rtype = cdk::reference_type::cast(rtype)->referenced();
      }

      std::cout << "(TYPE_CHECKER)FUNCT TYPE " << cdk::to_string(_functionType) << " --- " << ft << " -- " << ftype->name() << std::endl;
      std::cout << "(TYPE_CHECKER)RETVAL TYPE " << cdk::to_string(node->returnValue()->type()) << " --- " << rt << " -- " << cdk::to_string(rtype)
          << std::endl;

      bool compatible = (ft == rt) && (rtype == nullptr || (rtype != nullptr && ftype->name() == rtype->name()));
      if (!compatible) throw std::string("wrong type for return expression (pointer expected).");

    } else if(_functionType->name() == cdk::TYPE_FUNCTIONAL){
      if(node->returnValue()->is_typed(cdk::TYPE_FUNCTIONAL)){
        //Função que retorna o retorno de uma função
        if(cdk::functional_type::cast(node->returnValue()->type())->output()->component(0) != cdk::functional_type::cast(_functionType)->output()->component(0))
            throw std::string("wrong type for initializer (function expected).");
      }
      //Função que retorna typed_node
      else if (node->returnValue()->type() != cdk::functional_type::cast(_functionType)->output()->component(0)) {
        throw std::string("wrong type for initializer (function expected).");
      }
    }
     else {
      throw std::string("(TYPE_CHECKER)(RETURN) unknown type for initializer.");
    }
  }
  std::cerr << "(TYPE_CHECKER)(RETURN) saiu!" << "\n";
}


void l22::type_checker::do_address_of_node(l22::address_of_node *const node, int lvl) {
  //BY ARTEM
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl + 2);
  if (node->argument()->type()->name() == cdk::TYPE_DOUBLE) {
    node->type(cdk::primitive_type::create(4, cdk::TYPE_POINTER));
  } else {
    throw std::string("wrong type in unary logical expression");
  }

}

void l22::type_checker::do_input_node(l22::input_node *const node, int lvl) {
  //BY ARTEM
   node->type(cdk::primitive_type::create(0, cdk::TYPE_UNSPEC));
}

void l22::type_checker::do_index_node(l22::index_node *const node, int lvl) {
  ASSERT_UNSPEC;
  std::shared_ptr < cdk::reference_type > btype;

  if (node->base()) {
    node->base()->accept(this, lvl + 2);
    btype = cdk::reference_type::cast(node->base()->type());
    if (!node->base()->is_typed(cdk::TYPE_POINTER)) throw std::string("pointer expression expected in index left-value");
  } else {
    btype = cdk::reference_type::cast(_functionType);
    if (!(_functionType->name() == cdk::TYPE_POINTER)) throw std::string("return pointer expression expected in index left-value");
  }

  node->index()->accept(this, lvl + 2);
  if (!node->index()->is_typed(cdk::TYPE_INT)) throw std::string("integer expression expected in left-value index");

  node->type(btype->referenced());
}

void l22::type_checker::do_sizeof_node(l22::sizeof_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->expression()->accept(this, lvl + 2);
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void l22::type_checker::do_stack_alloc_node(l22::stack_alloc_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl + 2);
  if (!node->argument()->is_typed(cdk::TYPE_INT)) {
    throw std::string("integer expression expected in allocation expression");
  }
  auto mytype = cdk::reference_type::create(4, cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  node->type(mytype);
}

void l22::type_checker::do_identity_node(l22::identity_node *const node, int lvl) {
  //EMPTY
}

void l22::type_checker::do_func_definition_node(l22::func_definition_node *const node, int lvl) {

  std::shared_ptr<cdk::basic_type> output;
  std::vector < std::shared_ptr < cdk::basic_type >> argtypes;

  for (size_t ax = 0; ax < node->arguments()->size(); ax++)
    argtypes.push_back(node->argument(ax)->type());

  output = node->retType();
  node->type(cdk::functional_type::create(argtypes, output));

  if(output->name() == cdk::TYPE_FUNCTIONAL)
      std::cerr << "(TYPE_CHECKER)FUNCDEF return type = " << "FUNCTIONAL" << "\n";
  else
    std::cerr << "(TYPE_CHECKER)FUNCDEF return type = " << cdk::to_string(output) << "\n";

}


void l22::type_checker::do_function_call_node(l22::function_call_node *const node, int lvl) {
  ASSERT_UNSPEC;

  std::cerr << "(func_cal) Entrou numa funcall" << "\n";
  if(node->pointer() == nullptr){
    std::cerr << "(func_cal) Recursive funcall" << "\n";
    //! To Check, what to do on recursive function?
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  }
  else{
    node->pointer()->accept(this, lvl);
    
    auto function = node->pointer();
    if (!function->is_typed(cdk::TYPE_FUNCTIONAL)) {
      // declare return variable for passing to function call
      throw std::string("Not a function.");
    }
    auto ft = cdk::functional_type::cast(node->pointer()->type());
    std::cerr << cdk::to_string(ft->output()->component(0)) << "\n";
    node->type(ft->output()->component(0));
    
    if(ft->input_length() != 0){
      if (node->arguments()->size() == ft->input()->components().size()) {
        node->arguments()->accept(this, lvl + 4);
        for (size_t ax = 0; ax < node->arguments()->size(); ax++) {
          std::cerr << "(TYPE_CHECKER)(func_cal) Argument " << std::to_string(ax + 1) << "\n";
          if(node->argument(ax)->is_typed(cdk::TYPE_FUNCTIONAL)){
            auto call_arg = cdk::functional_type::cast(node->argument(ax)->type());
            if(call_arg->output()->component(0) == ft->input()->component(ax)) continue;
          }
          if (node->argument(ax)->type() == ft->input()->component(ax)) continue;
          if ((ft->input()->component(ax)->name() == cdk::TYPE_DOUBLE) && node->argument(ax)->is_typed(cdk::TYPE_INT)) continue;
          
          throw std::string("type mismatch for argument " + std::to_string(ax + 1) + ".");
        }
      } else {
        throw std::string(
            "number of arguments in call (" + std::to_string(node->arguments()->size()) + ") must match declaration ("
                + std::to_string(ft->input()->length()) + ").");
      }
    }
  }
  std::cerr << "(TYPE_CHECKER)(func_cal) Saiu de uma funcall" << "\n";
  
}


void l22::type_checker::do_nullptr_node(l22::nullptr_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::reference_type::create(4, nullptr));
}
// OUR NODES (END) ========================================================================


//---------------------------------------------------------------------------

void l22::type_checker::do_integer_node(cdk::integer_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void l22::type_checker::do_string_node(cdk::string_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::primitive_type::create(4, cdk::TYPE_STRING));
}

//---------------------------------------------------------------------------

void l22::type_checker::processUnaryExpression(cdk::unary_operation_node *const node, int lvl) {
  node->argument()->accept(this, lvl + 2);
  if (!node->argument()->is_typed(cdk::TYPE_INT)) throw std::string("wrong type in argument of unary expression");

  // in Simple, expressions are always int
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void l22::type_checker::do_neg_node(cdk::neg_node *const node, int lvl) {
  processUnaryExpression(node, lvl);
}

//---------------------------------------------------------------------------

void l22::type_checker::processBinaryExpression(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  if(node->left()->is_typed(cdk::TYPE_FUNCTIONAL)){
    if((cdk::functional_type::cast(node->left()->type()))->output()->component(0)->name() != cdk::TYPE_INT){
          throw std::string("wrong type in left argument of binary expression");
    }
  }
  else if (!node->left()->is_typed(cdk::TYPE_INT)) throw std::string("wrong type in left argument of binary expression");

  node->right()->accept(this, lvl + 2);
  if(node->right()->is_typed(cdk::TYPE_FUNCTIONAL)){
    if((cdk::functional_type::cast(node->right()->type()))->output()->component(0)->name() != cdk::TYPE_INT){
          throw std::string("wrong type in right argument of binary expression");
    }
  }
  else if (!node->right()->is_typed(cdk::TYPE_INT)) throw std::string("wrong type in right argument of binary expression");

  // in Simple, expressions are always int
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void l22::type_checker::do_add_node(cdk::add_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void l22::type_checker::do_sub_node(cdk::sub_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void l22::type_checker::do_mul_node(cdk::mul_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void l22::type_checker::do_div_node(cdk::div_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void l22::type_checker::do_mod_node(cdk::mod_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void l22::type_checker::do_lt_node(cdk::lt_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void l22::type_checker::do_le_node(cdk::le_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void l22::type_checker::do_ge_node(cdk::ge_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void l22::type_checker::do_gt_node(cdk::gt_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void l22::type_checker::do_ne_node(cdk::ne_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void l22::type_checker::do_eq_node(cdk::eq_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}

//---------------------------------------------------------------------------

void l22::type_checker::do_variable_node(cdk::variable_node *const node, int lvl) {
  ASSERT_UNSPEC;
  std::cerr << "(TYPE_CHECKER)(variable_node) Entrou" << "\n";
  const std::string &id = node->name();

  std::cerr << "(TYPE_CHECKER)(variable_node) YOYO I am " << id << "\n";
  
  std::shared_ptr<l22::symbol> symbol = _symtab.find(id);

  if (symbol != nullptr) {
    node->type(symbol->type());
  } else {
    throw id;
  }
  std::cerr << "(TYPE_CHECKER)(variable_node) Saiu" << "\n";
}

void l22::type_checker::do_rvalue_node(cdk::rvalue_node *const node, int lvl) {
  ASSERT_UNSPEC;
  try {
    std::cerr << "(TYPE_CHECKER)(r_value_node) Tentou aceitar lvalue" << "\n";
    if(node->lvalue() == nullptr){
      std::cerr << "(TYPE_CHECKER)(r_value_node) lvalue é null :O" << "\n";
    }
    node->lvalue()->accept(this, lvl);
    std::cerr << "(TYPE_CHECKER)(r_value_node) Aceitou lvalue corretamente" << "\n";
    node->type(node->lvalue()->type());
  } catch (const std::string &id) {
    throw "undeclared variable '" + id + "'";
  }
}

void l22::type_checker::do_assignment_node(cdk::assignment_node *const node, int lvl) {
  ASSERT_UNSPEC;
  std::cerr << "(TYPE_CHECKER)(ASS_NODE) entrou!" << "\n";
  node->lvalue()->accept(this, lvl + 4);
  node->rvalue()->accept(this, lvl + 4);

  if (node->lvalue()->is_typed(cdk::TYPE_INT)) {
    if (node->rvalue()->is_typed(cdk::TYPE_INT)) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    } else if (node->rvalue()->is_typed(cdk::TYPE_UNSPEC)) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
      node->rvalue()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    } else {
      throw std::string("wrong assignment to integer");
    }
  } else if (node->lvalue()->is_typed(cdk::TYPE_POINTER)) {

    if (node->rvalue()->is_typed(cdk::TYPE_POINTER)) {
      node->type(node->rvalue()->type());
    } else if (node->rvalue()->is_typed(cdk::TYPE_INT)) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_POINTER));
    } else if (node->rvalue()->is_typed(cdk::TYPE_UNSPEC)) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_ERROR));
      node->rvalue()->type(cdk::primitive_type::create(4, cdk::TYPE_ERROR));
    } else {
      throw std::string("wrong assignment to pointer");
    }

  } else if (node->lvalue()->is_typed(cdk::TYPE_DOUBLE)) {

    if (node->rvalue()->is_typed(cdk::TYPE_DOUBLE) || node->rvalue()->is_typed(cdk::TYPE_INT)) {
      node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
    } else if (node->rvalue()->is_typed(cdk::TYPE_UNSPEC)) {
      node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
      node->rvalue()->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
    } else {
      throw std::string("wrong assignment to real");
    }

  } else if (node->lvalue()->is_typed(cdk::TYPE_STRING)) {

    if (node->rvalue()->is_typed(cdk::TYPE_STRING)) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_STRING));
    } else if (node->rvalue()->is_typed(cdk::TYPE_UNSPEC)) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_STRING));
      node->rvalue()->type(cdk::primitive_type::create(4, cdk::TYPE_STRING));
    } else {
      throw std::string("wrong assignment to string");
    }

  }
  else if(node->lvalue()->is_typed(cdk::TYPE_FUNCTIONAL)){
    if(node->lvalue()->type() == node->rvalue()->type()){
      node->type(node->lvalue()->type());
    }
  } 
  else {
    throw std::string("wrong types in assignment");
  }

  std::cerr << "(TYPE_CHECKER)(ASS_NODE) saiu!" << "\n";

}

//---------------------------------------------------------------------------

void l22::type_checker::do_program_node(l22::program_node *const node, int lvl) {
  std::string id = "_main";

  _inBlockReturnType = nullptr;
  
  // remember symbol so that args know
  auto function = l22::make_symbol(false, tPUBLIC, cdk::primitive_type::create(4, cdk::TYPE_INT), id, false, true);

  std::shared_ptr<l22::symbol> previous = _symtab.find(function->name());


  _symtab.insert(function->name(), function);
  _parent->set_new_symbol(function);
  
}

void l22::type_checker::do_evaluation_node(l22::evaluation_node *const node, int lvl) {
  node->argument()->accept(this, lvl + 2);
}

void l22::type_checker::do_print_node(l22::print_node *const node, int lvl) {
  node->argument()->accept(this, lvl + 2);
}

//---------------------------------------------------------------------------

//void l22::type_checker::do_read_node(l22::read_node *const node, int lvl) {
//  try {
//    node->argument()->accept(this, lvl);
//  } catch (const std::string &id) {
//    throw "undeclared variable '" + id + "'";
//  }
//}

//---------------------------------------------------------------------------

void l22::type_checker::do_while_node(l22::while_node *const node, int lvl) {
  node->condition()->accept(this, lvl + 4);
}

//---------------------------------------------------------------------------

void l22::type_checker::do_if_node(l22::if_node *const node, int lvl) {
  node->condition()->accept(this, lvl + 4);
}

void l22::type_checker::do_if_else_node(l22::if_else_node *const node, int lvl) {
  node->condition()->accept(this, lvl + 4);
}


