#ifndef __L22_AST_RETURN_NODE_H__
#define __L22_AST_RETURN_NODE_H__

#include <cdk/ast/lvalue_node.h>

namespace l22 {

  /**
   * RETURN.
   */
  class return_node: public cdk::basic_node {
    cdk::expression_node *_returnValue;

  public:
    inline return_node(int lineno, cdk::expression_node *returnValue = nullptr) :
        cdk::basic_node(lineno), _returnValue(returnValue) {
    }

  public:
    inline cdk::expression_node *returnValue() {
      return _returnValue;
    }


    void accept(basic_ast_visitor *sp, int level) {
      sp->do_return_node(this, level);
    }

  };

} // l22

#endif
