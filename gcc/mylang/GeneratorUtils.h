#pragma once
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
#include "stringpool.h"

enum BooleanOpcode{
    NOT,
    AND,
    OR,
    EQUAL,
    NOT_EQUAL,
    GREATER_THAN,
    GREATER_THAN_EQUAL,
    LESSER_THAN,
    LESSER_THAN_EQUAL,
};

class GeneratorUtils
{
public:
    static tree generateIntConstant(const std::string &asciiIntStr);
    static tree generateFloatConstant(const std::string &asciiFloatStr);
    static tree generateVariableDeclaration(const std::string &name, tree type);
    static tree generateDeclareExpr(tree decl);
    static tree generateAssignmentTree(tree decl, tree expr);
    static tree generateArithimaticBinaryOpTree(char x,tree exp1, tree exp2);
    static tree generateBooleanBinaryOpTree(BooleanOpcode opcode,tree exp1, tree exp2);
    static tree generateArithimaticUnaryMinusOpTree(tree exp1);
    static tree generateBooleanUnaryNotOpTree(tree exp1);
};
