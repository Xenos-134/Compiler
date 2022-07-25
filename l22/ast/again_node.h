#ifndef __L22_AST_AGAIN_NODE_H__
#define __L22_AST_AGAIN_NODE_H__

#include <cdk/ast/expression_node.h>

namespace l22 {

  /**
   * SAME AS CONTINUE.
   */
  class again_node: public cdk::basic_node {
    int _lvl;

  public:
    inline again_node(int lineno, int level = 1) :
        cdk::basic_node(lineno), _lvl(level) {
    }

  public:
    int level() const {
      return _lvl;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_again_node(this, level);
    }

  };

} // l22

#endif
