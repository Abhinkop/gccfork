
#include <vector>
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
#include "MyIO.h"
#include "GenericFunction.h"
#include "GeneratorUtils.h"
#include "GenericBlock.h"
#include "GenericStatementList.h"

#include "MylangScanner.h"
#include "MylangParser.h"

/* Language-dependent contents of a type.  */
int yyparse(void);
extern FILE *yyin;

struct GTY(()) lang_type
{
  char dummy;
};

/* Language-dependent contents of a decl.  */

struct GTY(()) lang_decl
{
  char dummy;
};

/* Language-dependent contents of an identifier.  This must include a
   tree_identifier.  */

struct GTY(()) lang_identifier
{
  struct tree_identifier common;
};

/* The resulting tree type.  */

union GTY((desc("TREE_CODE (&%h.generic) == IDENTIFIER_NODE"),
           chain_next("CODE_CONTAINS_STRUCT (TREE_CODE (&%h.generic), "
                      "TS_COMMON) ? ((union lang_tree_node *) TREE_CHAIN "
                      "(&%h.generic)) : NULL"))) lang_tree_node
{
  union tree_node GTY((tag("0"), desc("tree_node_structure (&%h)"))) generic;
  struct lang_identifier GTY((tag("1"))) identifier;
};

/* We don't use language_function.  */

struct GTY(()) language_function
{
  int dummy;
};

/* Language hooks.  */

static bool
mylang_langhook_init(void)
{
  /* NOTE: Newer versions of GCC use only:
           build_common_tree_nodes (false);
     See Eugene's comment in the comments section. */
  build_common_tree_nodes(false);

  /* I don't know why this has to be done explicitly.  */
  void_list_node = build_tree_list(NULL_TREE, void_type_node);

  build_common_builtin_nodes();

  return true;
}

static tree getDummyMain()
{

  std::vector<tree> args;
  // args.push_back(integer_type_node);
  // args.push_back(build_pointer_type(build_pointer_type(char_type_node)));
  GenericFunction mainFunc(integer_type_node, std::string("main"), args);
  GenericStatementList stmtList;
  tree var1 = GeneratorUtils::generateVariableDeclaration("a", integer_type_node);
  stmtList.addStatement(GeneratorUtils::generateDeclareExpr(var1));
  tree intConst = GeneratorUtils::generateIntConstant("1111");
  stmtList.addStatement(GeneratorUtils::generateAssignmentTree(var1, intConst));
  tree var2 = GeneratorUtils::generateVariableDeclaration("b", float_type_node);
  stmtList.addStatement(GeneratorUtils::generateDeclareExpr(var2));
  tree floatConst = GeneratorUtils::generateFloatConstant("1111.1");
  stmtList.addStatement(GeneratorUtils::generateAssignmentTree(var2, floatConst));

  tree add = GeneratorUtils::generateArithimaticBinaryOpTree('+',var1,var2);
  // printf
  tree t = MyIO::Print(add);
  stmtList.addStatement(t);

  t = MyIO::Print(var1);
  stmtList.addStatement(t);

  // return value
  tree retval = mainFunc.getFuncRetval();
  tree modify_retval = build2(MODIFY_EXPR,
                              integer_type_node,
                              retval,
                              build_int_cst(integer_type_node, 100));
  tree return_stmt = build1(RETURN_EXPR,
                            integer_type_node,
                            modify_retval);
  stmtList.addStatement(return_stmt);

  GenericBlock block(stmtList.getStmtList());

  mainFunc.addBlock(block.getBlockTree(),block.getBlockBindExpr());

  return mainFunc.getFuncGenericTree();
}

static void
mylang_langhook_parse_file(void)
{
  std::cout << "parsing starts"
            << "\n";

  gcc_assert(num_in_fnames == 1);
  FILE *file = fopen(in_fnames[0], "r");
  if (file == NULL)
  {
    fatal_error(UNKNOWN_LOCATION, "cannot open filename %s: %m", in_fnames[0]);
  }

  yyscan_t scanner;
  yylex_init(&scanner);
  yyset_in(file, scanner);
  tree function;
  mylang::MylangParser parser{scanner, function};
  std::cout.precision(10);
  parser.parse();

  std::cout << "parsing ends"
            << "\n";
  yylex_destroy(scanner);
  fclose(file);

  // auto dumps = g->get_dumps();

  // dumps->dump_start(TDI_original, &dump_flags);

  // dump_node(fndecl, dump_flags, dumps->get_dump_file_info(TDI_original)->pstream);
  // dump_function(TDI_original,fndecl);
  // dumps->dump_finish(TDI_original);
  // dump_tree_statistics();

  // Convert from GENERIC to GIMPLE
  tree fndecl = function;//getDummyMain();
  gimplify_function_tree(fndecl);

  // Insert it into the graph
  cgraph_node::finalize_function(fndecl, true);
}

static tree
mylang_langhook_type_for_mode(enum machine_mode mode, int unsignedp)
{
  if (mode == TYPE_MODE(float_type_node))
    return float_type_node;

  if (mode == TYPE_MODE(double_type_node))
    return double_type_node;

  if (mode == TYPE_MODE(intQI_type_node))
    return unsignedp ? unsigned_intQI_type_node : intQI_type_node;
  if (mode == TYPE_MODE(intHI_type_node))
    return unsignedp ? unsigned_intHI_type_node : intHI_type_node;
  if (mode == TYPE_MODE(intSI_type_node))
    return unsignedp ? unsigned_intSI_type_node : intSI_type_node;
  if (mode == TYPE_MODE(intDI_type_node))
    return unsignedp ? unsigned_intDI_type_node : intDI_type_node;
  if (mode == TYPE_MODE(intTI_type_node))
    return unsignedp ? unsigned_intTI_type_node : intTI_type_node;

  if (mode == TYPE_MODE(integer_type_node))
    return unsignedp ? unsigned_type_node : integer_type_node;

  if (mode == TYPE_MODE(long_integer_type_node))
    return unsignedp ? long_unsigned_type_node : long_integer_type_node;

  if (mode == TYPE_MODE(long_long_integer_type_node))
    return unsignedp ? long_long_unsigned_type_node
                     : long_long_integer_type_node;

  if (COMPLEX_MODE_P(mode))
  {
    if (mode == TYPE_MODE(complex_float_type_node))
      return complex_float_type_node;
    if (mode == TYPE_MODE(complex_double_type_node))
      return complex_double_type_node;
    if (mode == TYPE_MODE(complex_long_double_type_node))
      return complex_long_double_type_node;
    if (mode == TYPE_MODE(complex_integer_type_node) && !unsignedp)
      return complex_integer_type_node;
  }

  /* gcc_unreachable */
  return NULL;
}

static tree
mylang_langhook_type_for_size(unsigned int bits ATTRIBUTE_UNUSED,
                              int unsignedp ATTRIBUTE_UNUSED)
{
  gcc_unreachable();
  return NULL;
}

/* Record a builtin function.  We just ignore builtin functions.  */

static tree
mylang_langhook_builtin_function(tree decl)
{
  return decl;
}

static bool
mylang_langhook_global_bindings_p(void)
{
  gcc_unreachable();
  return true;
}

static tree
mylang_langhook_pushdecl(tree decl ATTRIBUTE_UNUSED)
{
  gcc_unreachable();
}

static tree
mylang_langhook_getdecls(void)
{
  return NULL;
}

#undef LANG_HOOKS_NAME
#define LANG_HOOKS_NAME "mylang"

#undef LANG_HOOKS_INIT
#define LANG_HOOKS_INIT mylang_langhook_init

#undef LANG_HOOKS_PARSE_FILE
#define LANG_HOOKS_PARSE_FILE mylang_langhook_parse_file

#undef LANG_HOOKS_TYPE_FOR_MODE
#define LANG_HOOKS_TYPE_FOR_MODE mylang_langhook_type_for_mode

#undef LANG_HOOKS_TYPE_FOR_SIZE
#define LANG_HOOKS_TYPE_FOR_SIZE mylang_langhook_type_for_size

#undef LANG_HOOKS_BUILTIN_FUNCTION
#define LANG_HOOKS_BUILTIN_FUNCTION mylang_langhook_builtin_function

#undef LANG_HOOKS_GLOBAL_BINDINGS_P
#define LANG_HOOKS_GLOBAL_BINDINGS_P mylang_langhook_global_bindings_p

#undef LANG_HOOKS_PUSHDECL
#define LANG_HOOKS_PUSHDECL mylang_langhook_pushdecl

#undef LANG_HOOKS_GETDECLS
#define LANG_HOOKS_GETDECLS mylang_langhook_getdecls

#undef LANG_HOOKS_TREE_DUMP_DUMP_TREE_FN
#define LANG_HOOKS_TREE_DUMP_DUMP_TREE_FN c_dump_tree

struct lang_hooks lang_hooks = LANG_HOOKS_INITIALIZER;

#include "gt-mylang-mylang.h"
#include "gtype-mylang.h"