%{
#include <cstdlib>
#include <string>
#include "MylangParser.h"
using namespace mylang;
%}
 
%option reentrant interactive noyywrap noyylineno nodefault outfile="MylangScanner.cc" header="MylangScanner.h"
 


LINETERMINATOR  \r|\n|\r\n
NUMBER          [0-9]+


%%

{NUMBER} {yylval->emplace<int>(strtoll(yytext, nullptr, 10)); return MylangParser::token::INTLITERAL;}
{NUMBER}\.{NUMBER} {yylval->emplace<std::string>(std::string(yytext)); return MylangParser::token::FLOATLITERAL;}
{LINETERMINATOR} {return MylangParser::token::EOL;}
. { printf("Unexpected character: %s\n", yytext); }

%%