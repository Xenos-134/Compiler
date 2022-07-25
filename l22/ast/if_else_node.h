#ifndef __L22_AST_IF_ELSE_NODE_H__
#define __L22_AST_IF_ELSE_NODE_H__

#include <cdk/ast/expression_node.h>

namespace l22 {

  /**
   * Class for describing if-then-else nodes.
   */
  class if_else_node: public cdk::basic_node {
    cdk::expression_node *_condition;
    cdk::basic_node *_thenblock, *_elseblock;
    cdk::sequence_node *_elifblocks;

  public:
    inline if_else_node(int lineno, cdk::expression_node *condition, cdk::basic_node *thenblock, cdk::basic_node *elseblock, cdk::sequence_node *elifblocks = NULL) :
        cdk::basic_node(lineno), _condition(condition), _thenblock(thenblock), _elseblock(elseblock), _elifblocks(elifblocks) {
    }

  public:
    inline cdk::expression_node *condition() {
      return _condition;
    }
    inline cdk::basic_node *thenblock() {
      return _thenblock;
    }
    inline cdk::basic_node *elseblock() {
      return _elseblock;
    }

    cdk::sequence_node *elifblocks() {
      return _elifblocks;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_if_else_node(this, level);
    }

  };

} // l22

#endif
