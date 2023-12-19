%{
#include <iostream>
#include <string>
#include <cmath>
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
#include "MylangScanner.h"
%}
 
%require "3.7.4"
%language "C++"
%defines "MylangParser.h"
%output "MylangParser.cc"
 
%define api.parser.class {MylangParser}
%define api.namespace {mylang}
%define api.value.type variant
%param {yyscan_t scanner}
%parse-param { tree  &myroot  }
 %code requires{

 typedef union tree_node *tree;

}
%code provides
{
    #define YY_DECL \
        int yylex(mylang::MylangParser::semantic_type *yylval, yyscan_t yyscanner)
    YY_DECL;
}
 
%token <int> INTLITERAL
%token <std::string> FLOATLITERAL

%token EOL
%left '+' '-'
%left '*' '/'
 
 
%%
 
input: /* empty */ 
    | INTLITERAL EOL {myroot = build_int_cst(integer_type_node,
                            $1);
                        std::cout << $1 << '\n';}
    | FLOATLITERAL EOL {printf("%s",$1.c_str());
    REAL_VALUE_TYPE real_value;
	real_from_string3 (&real_value, $1.c_str(),
			   TYPE_MODE (float_type_node));

	myroot = build_real (float_type_node, real_value);
    }
    ;
 
%%
 
void mylang::MylangParser::error(const std::string& msg) {
    std::cerr << msg << '\n';
}