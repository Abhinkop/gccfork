%{
#include <iostream>
#include <string>
#include <cmath>
#include <map>
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

std::map<std::string, int> sym;

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
 
%token <std::string> INTLITERAL
%token <std::string> FLOATLITERAL
%token <std::string> ID

%token INT_TYPE IF ELSE WHILE RETURN
%token ADD SUB MUL DIV ASSIGN SEMICOLON
%token LPAREN RPAREN LBRACE RBRACE COMMA
%token LESS_THAN GREATER_THAN LESS_THAN_EQUAL GREATER_THAN_EQUAL EQUAL NOT_EQUAL
%token LOGICAL_AND LOGICAL_OR LOGICAL_NOT
%token READ WRITE

%type <int> expr

%left LOGICAL_NOT
%left LOGICAL_OR
%left LOGICAL_AND
%left EQUAL NOT_EQUAL
%left LESS_THAN GREATER_THAN LESS_THAN_EQUAL GREATER_THAN_EQUAL
%left ADD SUB
%left MUL DIV
%right UNARY_OP /* For unary operators like negation */
 
 
%%
program : function
        | program function
        ; 
function : INT_TYPE ID LPAREN args RPAREN block

args : 
        | INT_TYPE ID
        | args COMMA INT_TYPE ID 
        ;

block : LBRACE statement_list RBRACE
 
statement_list: /* empty */
        | statement_list statement
        ;

statement: expr SEMICOLON
         | INT_TYPE ID SEMICOLON { sym[$2] = 0; }
         | ID ASSIGN expr SEMICOLON { sym[$1] = $3; }
         | IF LPAREN expr RPAREN LBRACE block RBRACE
         | IF LPAREN expr RPAREN LBRACE block RBRACE ELSE LBRACE block RBRACE
         | WHILE LPAREN expr RPAREN LBRACE block RBRACE
         | RETURN expr SEMICOLON                {
                                                   ; 
                                                }
         | WRITE ID SEMICOLON {std::cout <<sym[$2] <<"\n";}
         ;

expr: ID { $$ = sym[$1]; }
    | INTLITERAL { $$ = strtoll($1.c_str(), nullptr, 10);}
    | expr ADD expr { $$ = $1 + $3; }
    | expr SUB expr { $$ = $1 - $3; }
    | expr MUL expr { $$ = $1 * $3; }
    | expr DIV expr { $$ = $1 / $3; }
    | expr LESS_THAN expr { $$ = $1 < $3; }
    | expr GREATER_THAN expr { $$ = $1 > $3; }
    | expr LESS_THAN_EQUAL expr { $$ = $1 <= $3; }
    | expr GREATER_THAN_EQUAL expr { $$ = $1 >= $3; }
    | expr EQUAL expr { $$ = $1 == $3; }
    | expr NOT_EQUAL expr { $$ = $1 != $3; }
    | expr LOGICAL_AND expr { $$ = $1 && $3; }
    | expr LOGICAL_OR expr { $$ = $1 || $3; }
    | LOGICAL_NOT expr { $$ = !$2; }
    | LPAREN expr RPAREN { $$ = $2; }
    ;
 
%%
 
void mylang::MylangParser::error(const std::string& msg) {
    std::cerr << msg << '\n';
}