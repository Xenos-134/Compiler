#ifndef __L22_AST_VARIABLE_DECLARATION_H__
#define __L22_AST_VARIABLE_DECLARATION_H__

#include <cdk/ast/basic_node.h>
#include <cdk/ast/expression_node.h>
#include <cdk/types/basic_type.h>

namespace l22 {

  class var_declaration_node: public cdk::basic_node {
    int _qualifier;
    std::shared_ptr<cdk::basic_type> _type;
    std::string _identifier;
    cdk::expression_node *_initializer;
    

  public:
    var_declaration_node(int lineno, int qualifier, std::shared_ptr<cdk::basic_type> varType, const std::string &identifier,
                              cdk::expression_node *initializer) :
        cdk::basic_node(lineno), _qualifier(qualifier), _type(varType), _identifier(identifier), _initializer(initializer) {
    }
    

  public:
    bool constant() {
      return false;
    }
    int qualifier() {
      return _qualifier;
    }
    const std::string& identifier() const {
      return _identifier;
    }
    cdk::expression_node* initializer() {
      return _initializer;
    }

    void type(std::shared_ptr<cdk::basic_type> type) {
      _type = type;
    }

    std::shared_ptr<cdk::basic_type> type() const{
      return _type;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_var_declaration_node(this, level);
    }

  };

} // l22

#endif
