#ifndef __L22_AST_FUNCTION_DEFINITION_H__
#define __L22_AST_FUNCTION_DEFINITION_H__

#include <string>
#include <cdk/ast/basic_node.h>
#include <cdk/ast/sequence_node.h>
#include <cdk/ast/expression_node.h>
#include <vector>
#include <cdk/types/basic_type.h>
#include <ast/var_declaration_node.h>
#include "ast/block_node.h"


namespace l22 {

  /**
   * Class for describing function definitions.
   */
  class func_definition_node: public cdk::expression_node {
    cdk::sequence_node *_arguments;
    l22::block_node *_block;
    std::shared_ptr<cdk::basic_type> _rettype;
    
  public:

    func_definition_node(int lineno, cdk::sequence_node *arguments, l22::block_node *block,  std::shared_ptr<cdk::basic_type> funType) :
                    cdk::expression_node(lineno), _arguments(arguments), _block(block), _rettype(funType) {
      //type(cdk::primitive_type::create(0, cdk::TYPE_VOID));
    }

  public:

    cdk::sequence_node* arguments() {
      return _arguments;
    }

    l22::var_declaration_node* argument(size_t ax) {
      return dynamic_cast<l22::var_declaration_node*>(_arguments->node(ax));
    }

    l22::block_node* block() {
      return _block;
    }
    std::shared_ptr<cdk::basic_type> retType(){
      return _rettype;
    }

    

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_func_definition_node(this, level);
    }

  };

} // l22

#endif