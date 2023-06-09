%option noyywrap
%{
	#include<stdio.h>
	#include<string.h>
%}

%%
#.* {printf("\n%s is a preprocessor", yytext);}
int|float|double|long {printf("\n%s is a keyword", yytext);}
[a-zA-Z][a-zA-Z0-9]* { printf("\n%s is an identifier", yytext);}
[0-9]+ {printf("\n%s is a digit", yytext);}
[=+/*%] {printf("\n%s is an operator", yytext);}
[(){}|,;] {printf("\n%s is an end statement", yytext);}
%%

%%
int main()
{
    yylex();
    return 0;
} 
int yywrap(void)
{
}


	
