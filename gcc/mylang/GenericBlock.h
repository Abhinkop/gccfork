#pragma once
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

class GenericBlock
{
private:
    tree current_block;
    tree bind_expr;
    void copy(const GenericBlock &other);
public:
    GenericBlock(tree stmtList);
    GenericBlock(const GenericBlock &other);
    GenericBlock& operator=(const GenericBlock &other);
    ~GenericBlock();

    tree getBlockTree()
    {
        return current_block;
    }
    tree getBlockBindExpr()
    {
        return bind_expr;
    }
};
