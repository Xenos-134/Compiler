#include <string>
#include "targets/xml_writer.h"
#include "targets/type_checker.h"
#include ".auto/all_nodes.h"  // automatically generated

#include <algorithm>
#include <memory>
#include <cstring>
#include <cdk/compiler.h>
#include <cdk/types/types.h>

#include "l22_parser.tab.h"

static std::string qualifier_name(int qualifier) {
  if (qualifier == tPUBLIC) return "public";
  if (qualifier == tPRIVATE)
    return "private";
  else
    return "unknown qualifier";
}

static std::string type_name(std::shared_ptr<cdk::basic_type> type) {
  if (type == nullptr) return "auto";
  if (type->name() == cdk::TYPE_INT) return "integer";
  if (type->name() == cdk::TYPE_DOUBLE) return "double";
  if (type->name() == cdk::TYPE_STRING) return "string";
  if (type->name() == cdk::TYPE_FUNCTIONAL) return "functional";
  if (type->name() == cdk::TYPE_VOID) return "void";
  else
    return "unknown type";
}


//---------------------------------------------------------------------------

void l22::xml_writer::do_nil_node(cdk::nil_node * const node, int lvl) {
}
void l22::xml_writer::do_data_node(cdk::data_node * const node, int lvl) {
}
void l22::xml_writer::do_double_node(cdk::double_node * const node, int lvl) {
  process_literal(node, lvl);
}
void l22::xml_writer::do_not_node(cdk::not_node * const node, int lvl) {
  do_unary_operation(node, lvl);
}
void l22::xml_writer::do_and_node(cdk::and_node * const node, int lvl) {
  do_binary_operation(node, lvl);
}
void l22::xml_writer::do_or_node(cdk::or_node * const node, int lvl) {
  do_binary_operation(node, lvl);
}



// PUR NODES (START) ==========================================================================


void l22::xml_writer::do_block_node(l22::block_node * const node, int lvl) {
  openTag(node, lvl);
  
  if (node->declarations()) {
    openTag("declarations", lvl);
    node->declarations()->accept(this, lvl + 4);
    closeTag("declarations", lvl);
  }
  
  
  if (node->instructions()) {
    openTag("instructions", lvl);
    node->instructions()->accept(this, lvl + 4);
    closeTag("instructions", lvl);
  }
  
  closeTag(node, lvl);
}


void l22::xml_writer::do_var_declaration_node(l22::var_declaration_node* const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  reset_new_symbol();

  os() << std::string(lvl, ' ') << "<" << node->label() << " name='" << node->identifier() << "' qualifier='"
      << qualifier_name(node->qualifier()) << "' type='" << type_name(node->type()) << "'>" << std::endl;

  if (node->initializer()) {
    openTag("initializer", lvl);
    node->initializer()->accept(this, lvl + 4);
    closeTag("initializer", lvl);
  }

  closeTag(node, lvl);
}

void l22::xml_writer::do_stop_node(l22::stop_node* const node, int lvl) {
  openTag(node, lvl);
  closeTag(node, lvl);
}

void l22::xml_writer::do_return_node(l22::return_node *const node, int lvl) {
  
  _functionType = _functions.top();
  ASSERT_SAFE_EXPRESSIONS;

  openTag(node, lvl);
  if (node->returnValue()) node->returnValue()->accept(this, lvl + 4);
  closeTag(node, lvl);
}
void l22::xml_writer::do_again_node(l22::again_node* const node, int lvl) {
  openTag(node, lvl);
  closeTag(node, lvl);
}


void l22::xml_writer::do_address_of_node(l22::address_of_node * const node, int lvl) {
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void l22::xml_writer::do_input_node(l22::input_node * const node, int lvl) {
  openTag(node, lvl);
  closeTag(node, lvl);
}

void l22::xml_writer::do_index_node(l22::index_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("base", lvl);
  node->base()->accept(this, lvl + 2);
  closeTag("base", lvl);
  openTag("index", lvl);
  node->index()->accept(this, lvl + 2);
  closeTag("index", lvl);
  closeTag(node, lvl);
}

void l22::xml_writer::do_sizeof_node(l22::sizeof_node * const node, int lvl) {
  openTag(node, lvl);
  node->expression()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void l22::xml_writer::do_stack_alloc_node(l22::stack_alloc_node * const node, int lvl) {
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);}

void l22::xml_writer::do_identity_node(l22::identity_node * const node, int lvl) {
  openTag(node, lvl);
  closeTag(node, lvl);}

void l22::xml_writer::do_func_definition_node(l22::func_definition_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  os() << std::string(lvl, ' ') << "<" << node->label() << " type='" << type_name(node->type()) << "'>" << std::endl;
  
  // remember symbol so that args and body know
  _symtab.push(); // scope of args
  _functions.push(node->retType());


  if(node->arguments()){
    openTag("arguments", lvl + 2);
    node->arguments()->accept(this, lvl + 4);
    closeTag("arguments", lvl + 2);
  }
  if(node->arguments()){
    openTag("argument_types", lvl + 2);
    //!TODO
    closeTag("argument_types", lvl + 2);
  }
  openTag("body", lvl);
  if(node->block()){
    node->block()->accept(this, lvl + 2);
  }
  
  closeTag("body", lvl);


  closeTag(node, lvl);

  reset_new_symbol();
  _functions.pop();
  _symtab.pop(); // scope of args

}


void l22::xml_writer::do_function_call_node(l22::function_call_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  if (node->arguments()) node->arguments()->accept(this, lvl + 4);
  closeTag("arguments", lvl);
  closeTag(node, lvl);
}

void l22::xml_writer::do_nullptr_node(l22::nullptr_node * const node, int lvl) {
  openTag(node, lvl);
  closeTag(node, lvl);
}



// PUR NODES (END) ==========================================================================

//---------------------------------------------------------------------------

void l22::xml_writer::do_sequence_node(cdk::sequence_node * const node, int lvl) {
  os() << std::string(lvl, ' ') << "<sequence_node size='" << node->size() << "'>" << std::endl;
  for (size_t i = 0; i < node->size(); i++)
    node->node(i)->accept(this, lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void l22::xml_writer::do_integer_node(cdk::integer_node * const node, int lvl) {
  process_literal(node, lvl);
}

void l22::xml_writer::do_string_node(cdk::string_node * const node, int lvl) {
  process_literal(node, lvl);
}

//---------------------------------------------------------------------------

void l22::xml_writer::do_unary_operation(cdk::unary_operation_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void l22::xml_writer::do_neg_node(cdk::neg_node * const node, int lvl) {
  do_unary_operation(node, lvl);
}

//---------------------------------------------------------------------------

void l22::xml_writer::do_binary_operation(cdk::binary_operation_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void l22::xml_writer::do_add_node(cdk::add_node * const node, int lvl) {
  do_binary_operation(node, lvl);
}
void l22::xml_writer::do_sub_node(cdk::sub_node * const node, int lvl) {
  do_binary_operation(node, lvl);
}
void l22::xml_writer::do_mul_node(cdk::mul_node * const node, int lvl) {
  do_binary_operation(node, lvl);
}
void l22::xml_writer::do_div_node(cdk::div_node * const node, int lvl) {
  do_binary_operation(node, lvl);
}
void l22::xml_writer::do_mod_node(cdk::mod_node * const node, int lvl) {
  do_binary_operation(node, lvl);
}
void l22::xml_writer::do_lt_node(cdk::lt_node * const node, int lvl) {
  do_binary_operation(node, lvl);
}
void l22::xml_writer::do_le_node(cdk::le_node * const node, int lvl) {
  do_binary_operation(node, lvl);
}
void l22::xml_writer::do_ge_node(cdk::ge_node * const node, int lvl) {
  do_binary_operation(node, lvl);
}
void l22::xml_writer::do_gt_node(cdk::gt_node * const node, int lvl) {
  do_binary_operation(node, lvl);
}
void l22::xml_writer::do_ne_node(cdk::ne_node * const node, int lvl) {
  do_binary_operation(node, lvl);
}
void l22::xml_writer::do_eq_node(cdk::eq_node * const node, int lvl) {
  do_binary_operation(node, lvl);
}

//---------------------------------------------------------------------------

void l22::xml_writer::do_variable_node(cdk::variable_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  os() << std::string(lvl, ' ') << "<" << node->label() << ">" << node->name() << "</" << node->label() << ">" << std::endl;
}

void l22::xml_writer::do_rvalue_node(cdk::rvalue_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->lvalue()->accept(this, lvl + 4);
  closeTag(node, lvl);
}

void l22::xml_writer::do_assignment_node(cdk::assignment_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);

  node->lvalue()->accept(this, lvl);
  reset_new_symbol();

  node->rvalue()->accept(this, lvl + 4);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void l22::xml_writer::do_program_node(l22::program_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  // remember symbol so that args and body know 
  _functions.push(cdk::primitive_type::create(4, cdk::TYPE_INT));
  _symtab.push(); // scope of args

  openTag(node, lvl);
  node->statements()->accept(this, lvl + 4);
  closeTag(node, lvl);

  _symtab.pop(); // scope of args
  _functions.pop();

}

//---------------------------------------------------------------------------

void l22::xml_writer::do_evaluation_node(l22::evaluation_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void l22::xml_writer::do_print_node(l22::print_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

//void l22::xml_writer::do_read_node(l22::read_node * const node, int lvl) {
//  ASSERT_SAFE_EXPRESSIONS;
//  openTag(node, lvl);
//  node->argument()->accept(this, lvl + 2);
//  closeTag(node, lvl);
//}

//---------------------------------------------------------------------------

void l22::xml_writer::do_while_node(l22::while_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  openTag("condition", lvl + 2);
  node->condition()->accept(this, lvl + 4);
  closeTag("condition", lvl + 2);
  openTag("block", lvl + 2);
  node->block()->accept(this, lvl + 4);
  closeTag("block", lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void l22::xml_writer::do_if_node(l22::if_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  openTag("condition", lvl + 2);
  node->condition()->accept(this, lvl + 4);
  closeTag("condition", lvl + 2);
  openTag("then", lvl + 2);
  node->block()->accept(this, lvl + 4);
  closeTag("then", lvl + 2);
  closeTag(node, lvl);
}

void l22::xml_writer::do_if_else_node(l22::if_else_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  openTag("condition", lvl + 2);
  node->condition()->accept(this, lvl + 4);
  closeTag("condition", lvl + 2);
  openTag("then", lvl + 2);
  node->thenblock()->accept(this, lvl + 4);
  closeTag("then", lvl + 2);
  openTag("else", lvl + 2);
  node->elseblock()->accept(this, lvl + 4);
  closeTag("else", lvl + 2);
  closeTag(node, lvl);
}



