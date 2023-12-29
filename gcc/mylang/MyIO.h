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

class MyIO
{
private:
    static tree printf_fn;
    /* data */
    MyIO(/* args */);
    static tree get_printf_addr();

public:
    ~MyIO();
    static tree PrintInt(tree expr);
    static tree PrintFloat(tree expr);
    static tree Print(tree expr);
};