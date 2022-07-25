#ifndef __L22_AST_FUNCTION_CALL_H__
#define __L22_AST_FUNCTION_CALL_H__

#include <string>
#include <cdk/ast/basic_node.h>
#include <cdk/ast/sequence_node.h>
#include <cdk/ast/nil_node.h>
#include <cdk/ast/expression_node.h>
#include "targets/basic_ast_visitor.h"

namespace l22 {

  /**
   * Class for describing function call nodes.
   *
   * If _arguments is null, them the node is either a call to a function with
   * no arguments (or in which none of the default arguments is present) or
   * an access to a variable.
   */
  class function_call_node: public cdk::expression_node {
    cdk::expression_node *_expr;
    cdk::sequence_node *_arguments;


  public:
    /**
     * Constructor for a function call without arguments.
     * An empty sequence is automatically inserted to represent
     * the missing arguments.
     */
    function_call_node(int lineno) :
        cdk::expression_node(lineno), _arguments(new cdk::sequence_node(lineno)) {
    }

    /**
     * Constructor for a function call with arguments.
     */
    function_call_node(int lineno, cdk::sequence_node *arguments) :
      cdk::expression_node(lineno), _expr(nullptr), _arguments(arguments) {
    }

    function_call_node(int lineno, cdk::expression_node *expr) :
      cdk::expression_node(lineno), _expr(expr) {
    }

    function_call_node(int lineno, cdk::expression_node *expr, cdk::sequence_node *arguments) :
      cdk::expression_node(lineno), _expr(expr), _arguments(arguments) {
    }

  public:
    cdk::expression_node *pointer() {
      return _expr;
    }
    cdk::sequence_node *arguments() {
      return _arguments;
    }

    void setPointer(cdk::expression_node *expr){
      _expr = expr;
    }

    cdk::typed_node* argument(size_t ax) {
      return dynamic_cast<cdk::typed_node*>(_arguments->node(ax));
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_function_call_node(this, level);
    }

  };

} // l22

#endif
