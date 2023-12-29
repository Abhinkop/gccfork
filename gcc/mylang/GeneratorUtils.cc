#include "GeneratorUtils.h"

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