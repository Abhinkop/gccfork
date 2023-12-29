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
#include "GenericFunction.h"
#include "GeneratorUtils.h"
#include "GenericBlock.h"
#include "GenericStatementList.h"
#include "MyIO.h"

std::map<std::string, tree> sym;
GenericFunction* currentFunction = NULL;
tree* bind_expr;
GenericStatementList* current_stmt_list = NULL;
%}
 
%require "3.7.4"
%language "C++"
%defines "MylangParser.h"
%output "MylangParser.cc"
 
%define api.parser.class {MylangParser}
%define api.namespace {mylang}
%define api.value.type variant
%param {yyscan_t scanner}
%parse-param { tree  &mainfunc  }
 %code requires{

 typedef union tree_node *tree;
 class GenericStatementList;
 class GenericBlock;

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

%type <tree> expr
%type <tree> statement
%type <GenericStatementList*> statement_list
%type <GenericBlock*> block
%type <std::vector<tree>> args

%left LOGICAL_NOT
%left LOGICAL_OR
%left LOGICAL_AND
%left EQUAL NOT_EQUAL
%left LESS_THAN GREATER_THAN LESS_THAN_EQUAL GREATER_THAN_EQUAL
%left ADD SUB
%left MUL DIV
%right UNARY_OP /* For unary operators like negation */
 
 
%%
program : function          {
                                std::cout << "Matched function" <<std::endl;
                                //std::vector<GenericFunction*> functionList;
                                //functionList.push_back($1);
                                //mainfunc = functionList[1]->getFuncGenericTree();
                            }
        | program function  {
                                std::cout << "Matched program function" <<std::endl;
                            }
        ; 
function : func_decl block {
                                std::cout << "Matched func_decl block" <<std::endl;
                                currentFunction->addBlock($2->getBlockTree(),$2->getBlockBindExpr());                    
                                mainfunc = currentFunction->getFuncGenericTree();
                            }
            ;
    
func_decl : INT_TYPE ID LPAREN args RPAREN {
                                                    std::cout << "Matched INT_TYPE ID LPAREN args RPAREN" <<std::endl;
                                                    currentFunction = new GenericFunction(integer_type_node, $2, $4);
                                                }
                                                ;

args :                  {
                            std::cout << "Matched Empty args" << std::endl;
                            $$.clear();
                        }
        | INT_TYPE ID   {
                            std::cout << "Matched INT_TYPE ID" << std::endl;
                            $$.push_back(integer_type_node);
                        }
        | args COMMA INT_TYPE ID    {
                                        std::cout << "Matched args COMMA INT_TYPE ID" << std::endl;
                                        $$.push_back(integer_type_node);
                                    }      
        ;

block : LBRACE statement_list RBRACE    {
                                            std::cout << "Matched LBRACE statement_list RBRACE" << std::endl;
                                            $$ = new GenericBlock($2->getStmtList());
                                        } 
 
statement_list: /* empty */ {
                                std::cout << "Matched Empty statement_list" << std::endl;
                                $$ = new GenericStatementList();
                                                            }
        | statement_list statement  {
                                        std::cout << "Matched statement_list statement" << std::endl;
                                        $1->addStatement($2);
                                        $$=$1;
                                                                            }
        ;

statement: expr SEMICOLON
         | INT_TYPE ID SEMICOLON    { 
                                        std::cout << "Matched INT_TYPE ID SEMICOLON" << std::endl;
                                        tree varDecl = GeneratorUtils::generateVariableDeclaration("$2", integer_type_node);
                                        sym[$2] = varDecl;
                                        $$ = GeneratorUtils::generateDeclareExpr(sym[$2]);
                                    }
         | ID ASSIGN expr SEMICOLON { 
                                        std::cout << "Matched ID ASSIGN expr SEMICOLON" << std::endl;
                                        $$ = GeneratorUtils::generateAssignmentTree(sym[$1], $3);
                                    }
         | RETURN expr SEMICOLON    {
                                        std::cout << "Matched RETURN expr SEMICOLON" << std::endl; 
                                        // return value
                                        tree retval = currentFunction->getFuncRetval();
                                        tree modify_retval = build2(MODIFY_EXPR,
                                                                    TREE_TYPE (retval),
                                                                    retval,
                                                                    $2);
                                        $$ = build1(RETURN_EXPR,
                                                    TREE_TYPE (retval),
                                                    modify_retval);
                                    }
         | WRITE ID SEMICOLON       {
                                        std::cout << "Matched WRITE ID SEMICOLON" << std::endl;
                                        $$ = MyIO::Print(sym[$2]);
                                    }
         ;

expr: ID            { 
                        std::cout << "Matched ID" << std::endl;
                        $$ = sym[$1]; 
                    }
    | INTLITERAL    { 
                        std::cout << "Matched INTLITERAL" << std::endl;
                        $$ = GeneratorUtils::generateIntConstant(std::string($1));
                    }
                ;
 
%%
 
void mylang::MylangParser::error(const std::string& msg) {
    std::cerr << msg << '\n';
}