%{
#include "TypeToken.h"    
int32_t yycolumno = 0;
%}

%option c++
%option yywrap
%option yylineno

%%

"{" { yycolumno++; return L_BRACE; }
"}" { yycolumno++; return R_BRACE; }
"(" { yycolumno++; return L_PAREN; }
")" { yycolumno++; return R_PAREN; }

"[" { yycolumno++; return L_SQUARE; }
"]" { yycolumno++; return R_SQUARE; }


"int" { yycolumno += yyleng; return INT; }
"char" { yycolumno += yyleng; return CHAR; }
"string" { yycolumno += yyleng; return STRING; }
"void" { yycolumno += yyleng; return VOID; }

";" { yycolumno++; return SEMICOLON; }
":" { yycolumno++; return COLON; }
"," { yycolumno++; return COMMA; }
"." { yycolumno++; return DOT; }

"+" { yycolumno++; return PLUS; }
"-" { yycolumno++; return MINUS; }
"*" { yycolumno++; return STAR; }
"/" { yycolumno++; return SLASH; }
"%" { yycolumno++; return PERCENT; }

"=" { yycolumno++; return EQUAL; }
"==" { yycolumno += yyleng; return EQUALEQUAL; }
"<" { yycolumno++; return LESS; }
">" { yycolumno++; return GREATER; }
"!=" { yycolumno += yyleng; return EXCLAIMEQUAL; }

"&&" { yycolumno += yyleng; return AMPAMP; }
"||" { yycolumno += yyleng; return PIPEPIPE; }

"while" { yycolumno += yyleng; return WHILE; }
"if" { yycolumno += yyleng; return IF; }
"else" { yycolumno += yyleng; return ELSE; }

"static" { yycolumno += yyleng; return STATIC; }
"id" { yycolumno += yyleng; return ID; }
"new" { yycolumno += yyleng; return NEW; }

"print" { yycolumno += yyleng; return PRINT; }
"input" { yycolumno += yyleng; return INPUT; }

[/][/].*\n ; // comment
[ ] { yycolumno++; } // ignore space
[\t] { printf("tab = %d\n", yyleng); yycolumno += yyleng; }
[\n] { yycolumno = 0; }

([_]|[a-zA-Z])+[a-zA-Z0-9_]+ { yycolumno += yyleng; return ID; }
[1-9][0-9]* { yycolumno += yyleng; return INTEGER; }
\".*\" { yycolumno += yyleng; return CONST_STRING; }
\'.*\' { yycolumno += yyleng; return CONST_CHAR; }

. { yycolumno += yyleng; return UNKNOWN; }

%%

int yyFlexLexer::yywrap() {
    return 1;
}
