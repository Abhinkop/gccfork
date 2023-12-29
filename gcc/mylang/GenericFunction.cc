#include "GenericFunction.h"

GenericFunction::GenericFunction(tree returnType, std::string name, std::vector<tree> &args)
{
    tree *fndecl_type_param = NULL;
    if(args.size() != 0)
        fndecl_type_param = new tree[args.size()];
    
    for (size_t i = 0; i < args.size(); i++)
    {
        fndecl_type_param[i] = args[i];
    }
    tree fndecl_type = build_function_type_array(integer_type_node, args.size(), fndecl_type_param);
    function = build_fn_decl(name.c_str(), fndecl_type);

    retval = build_decl(UNKNOWN_LOCATION, RESULT_DECL,
                             NULL_TREE, returnType);

    DECL_ARTIFICIAL(retval) = 1;
    DECL_IGNORED_P(retval) = 1;
    DECL_CONTEXT(retval) = function;
    DECL_RESULT(function) = retval;
    DECL_EXTERNAL(function) = 0;
    DECL_PRESERVE_P(function) = 1;
}

GenericFunction::~GenericFunction()
{
}

void GenericFunction::addBlock(tree block, tree bind_expr)
{

    DECL_SAVED_TREE(function) = bind_expr;
    DECL_INITIAL(function) = block;
    BLOCK_SUPERCONTEXT(block) = function;
    BLOCK_VARS(block) = BIND_EXPR_VARS(bind_expr);
}