#include "MyIO.h"


tree MyIO::printf_fn(NULL_TREE);

tree MyIO::get_printf_addr()
{
  if (MyIO::printf_fn == NULL_TREE)
  {
    tree fndecl_type_param[] = {
        build_pointer_type(
            build_qualified_type(char_type_node,
                                 TYPE_QUAL_CONST)) /* const char* */
    };
    tree fndecl_type = build_varargs_function_type_array(integer_type_node, 1,
                                                         fndecl_type_param);

    tree printf_fn_decl = build_fn_decl("printf", fndecl_type);
    DECL_EXTERNAL(printf_fn_decl) = 1;

    MyIO::printf_fn = (tree)build1(ADDR_EXPR, build_pointer_type(fndecl_type), printf_fn_decl);
  }

  return (tree)MyIO::printf_fn;
}

tree MyIO::PrintInt(tree expr)
{
  const char *format_integer = "%d\n";
  tree args[] = {build_string_literal(strlen(format_integer) + 1, format_integer),
                 expr};

  tree stmt = build_call_array(integer_type_node,
                               get_printf_addr(), 2, args);

  return stmt;
}

tree MyIO::PrintFloat(tree expr)
{
  const char *format_float = "%f\n";
  tree args[] = {build_string_literal(strlen(format_float) + 1, format_float),
                 convert (double_type_node, expr)};

  tree stmt = build_call_array(integer_type_node,
                               get_printf_addr(), 2, args);

  return stmt;
}

MyIO::MyIO(/* args */)
{
}

MyIO::~MyIO()
{
}
