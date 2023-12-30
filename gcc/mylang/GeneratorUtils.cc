#include "GeneratorUtils.h"

tree coerce_binary_arithmetic(tree &left, tree &right)
{
    tree left_type = TREE_TYPE(left);
    tree right_type = TREE_TYPE(right);

    if (error_operand_p(left_type) || error_operand_p(right_type))
        return tree(error_mark_node);
    ;

    if (left_type == right_type)
    {
        if (left_type == integer_type_node || left_type == float_type_node)
        {
            return left_type;
        }
    }
    else if ((left_type == integer_type_node && right_type == float_type_node) || (left_type == float_type_node && right_type == integer_type_node))
    {
        if (left_type == integer_type_node)
        {
            left = build1(FLOAT_EXPR, float_type_node,
                          left);
        }
        else
        {
            right = build1(FLOAT_EXPR, float_type_node,
                           right);
        }
        return float_type_node;
    }

    return tree(error_mark_node);
    ;
}

tree GeneratorUtils::generateIntConstant(const std::string &asciiIntStr)
{
    return build_int_cst(integer_type_node,
                         std::stoi(asciiIntStr));
}

tree GeneratorUtils::generateFloatConstant(const std::string &asciiFloatStr)
{
    REAL_VALUE_TYPE real_value;
    real_from_string3(&real_value, asciiFloatStr.c_str(),
                      TYPE_MODE(float_type_node));
    return build_real(float_type_node, real_value);
}

tree GeneratorUtils::generateVariableDeclaration(const std::string &name, tree type)
{
    return build_decl(UNKNOWN_LOCATION, VAR_DECL,
                      get_identifier(name.c_str()),
                      type);
}

tree GeneratorUtils::generateDeclareExpr(tree decl)
{
    return build1(DECL_EXPR, void_type_node, decl);
}

tree GeneratorUtils::generateAssignmentTree(tree decl, tree expr)
{
    if(TREE_TYPE(decl) == boolean_type_node)
    {
        tree casted = build1(FLOAT_EXPR, boolean_type_node,
                          expr);
    return build2(MODIFY_EXPR,
                  void_type_node, decl, casted);
    }
    return build2(MODIFY_EXPR,
                  void_type_node, decl, expr);
}

tree GeneratorUtils::generateArithimaticBinaryOpTree(char x, tree exp1, tree exp2)
{
    tree tree_type = coerce_binary_arithmetic(exp1, exp2);
    tree_code op;
    switch (x)
    {
    case '+':
        op = PLUS_EXPR;
        break;
    case '-':
        op = MINUS_EXPR;
        break;
    case '*':
        op = MULT_EXPR;
        break;
    case '/':
        if (TREE_TYPE(exp1) == integer_type_node)
            op = TRUNC_DIV_EXPR;
        else
            op = RDIV_EXPR;
        break;
    default:
        return tree(error_mark_node);
        break;
    }
    return build2(op,
                  tree_type, exp1, exp2);
}

tree GeneratorUtils::generateBooleanBinaryOpTree(BooleanOpcode opcode, tree exp1, tree exp2)
{
    tree_code op;
    switch (opcode)
    {
    case AND:
        op = TRUTH_ANDIF_EXPR;
        break;
    case OR:
        op = TRUTH_ORIF_EXPR;
        break;
    case EQUAL:
        op = EQ_EXPR;
        break;
    case NOT_EQUAL:
        op = NE_EXPR;
        break;
    case GREATER_THAN:
        op = GT_EXPR;
        break;
    case GREATER_THAN_EQUAL:
        op = GE_EXPR;
        break;
    case LESSER_THAN:
        op = LT_EXPR;
        break;
    case LESSER_THAN_EQUAL:
        op = LE_EXPR;
        break;
    default:
        return tree(error_mark_node);
        break;
    }
    return build2(op,
                  boolean_type_node, exp1, exp2);
}

tree GeneratorUtils::generateArithimaticUnaryMinusOpTree(tree exp1)
{
    return build1(NEGATE_EXPR,
                  TREE_TYPE(exp1), exp1);
}

tree GeneratorUtils::generateBooleanUnaryNotOpTree(tree exp1)
{
    return build1(TRUTH_NOT_EXPR,
                  boolean_type_node, exp1);
}