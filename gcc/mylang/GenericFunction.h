#pragma once

#include <vector>
#include <string>
#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "target.h"
#include "tree.h"
#include "gimple-expr.h"
#include "c-family/c-common.h"
#include "diagnostic.h"
#include "opts.h"
#include "fold-const.h"
#include "gimplify.h"
#include "stor-layout.h"
#include "debug.h"
#include "convert.h"
#include "langhooks.h"
#include "langhooks-def.h"
#include "common/common-target.h"
#include "tree-iterator.h"
#include "cgraph.h"
#include "context.h"
#include "tree-dump.h"

class GenericFunction
{
private:
    tree function;
    tree_stmt_iterator current_stmt_iter;
    tree current_block;
    tree retval;

    GenericFunction(const GenericFunction &other)
    {
        this->function = other.function;
        this->current_stmt_iter = other.current_stmt_iter;
        this->current_block = other.current_block;
        this->function = other.function;
        this->retval = other.retval;
    }
    GenericFunction& operator=(const GenericFunction &&other)
    {
        this->function = other.function;
        this->current_stmt_iter = other.current_stmt_iter;
        this->current_block = other.current_block;
        this->function = other.function;
        this->retval = other.retval;
        return *this;
    }

public:
    GenericFunction(tree returnType, std::string name, std::vector<tree> &args);
    ~GenericFunction();
    void addBlock(tree block, tree bind_expr);
    tree getFuncGenericTree()
    {
        return function;
    }
    tree getFuncRetval()
    {
        return retval;
    }
};
