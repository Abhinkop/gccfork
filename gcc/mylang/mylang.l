%{
#include <cstdlib>
#include <string>
#include "MylangParser.h"
using namespace mylang;
%}
 
%option reentrant interactive noyywrap noyylineno nodefault outfile="MylangScanner.cc" header="MylangScanner.h"
 


DIGIT       [0-9]+
IDENTIFIER  [a-zA-Z][a-zA-Z0-9]*
WS          [ \t\n]


%%

"if"        { return MylangParser::token::IF; }
"else"      { return MylangParser::token::ELSE; }
"while"     { return MylangParser::token::WHILE; }
"int"       { return MylangParser::token::INT_TYPE; }
"return"    { return MylangParser::token::RETURN; }
"read"    { return MylangParser::token::READ; }
"write"    { return MylangParser::token::WRITE; }

{DIGIT}             {
                        yylval->emplace<std::string>(std::string(yytext));
                        return MylangParser::token::INTLITERAL;
                    }
{DIGIT}\.{DIGIT}    {
                        yylval->emplace<std::string>(std::string(yytext));
                        return MylangParser::token::FLOATLITERAL;
                    }
{IDENTIFIER}        {
                        yylval->emplace<std::string>(std::string(yytext));
                        return MylangParser::token::ID;
                    }

"+"         { return MylangParser::token::ADD; }
"-"         { return MylangParser::token::MINUS; }
"*"         { return MylangParser::token::MUL; }
"/"         { return MylangParser::token::DIV; }
"="         { return MylangParser::token::ASSIGN; }
";"         { return MylangParser::token::SEMICOLON; }
"("         { return MylangParser::token::LPAREN; }
")"         { return MylangParser::token::RPAREN; }
"{"         { return MylangParser::token::LBRACE; }
"}"         { return MylangParser::token::RBRACE; }
"<"         { return MylangParser::token::LESS_THAN; }
">"         { return MylangParser::token::GREATER_THAN; }
"<="        { return MylangParser::token::LESS_THAN_EQUAL; }
">="        { return MylangParser::token::GREATER_THAN_EQUAL; }
"=="        { return MylangParser::token::EQUAL; }
"!="        { return MylangParser::token::NOT_EQUAL; }
"&&"        { return MylangParser::token::LOGICAL_AND; }
"||"        { return MylangParser::token::LOGICAL_OR; }
"!"         { return MylangParser::token::LOGICAL_NOT; }
","         { return MylangParser::token::COMMA; }

{WS}        ; /* ignore whitespace */

.           {
                fprintf(stderr, "Invalid character: %s\n", yytext);
            }

%%