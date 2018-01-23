%{
#include <stdio.h>
#include <math.h>
//int yydebug = 1;
int yylex(void);
void yyerror(const char* msg) {
	fprintf(stderr, "\x1b[31m[ ERROR ] Error occured: %s\n\x1b[0m", msg);
}
int yywrap(void) { return 1; }
int yyparse(void);
int main() {
	while(1) {
		printf(">>> "); fflush(stdout);
		yyparse();
	}
	return 0;
}
%}
%define api.value.type {double}
%left TOK_MINUS TOK_PLUS
%left TOK_STAR TOK_SLASH
%right TOK_POW
%token NUMBER TOK_OPEN_BRACKET TOK_CLOSE_BRACKET TOK_SINUS TOK_COSINUS TOK_TANGENS TOK_COTANGENS TOK_EXP
%%
input: expr
{
	printf("[ RESULT ]	%lf\n",$1);
}
expr: expr TOK_MINUS expr
{
	$$ = $1 - $3;
}
expr: expr TOK_PLUS expr
{
	$$ = $1 + $3;
}
expr: expr TOK_STAR expr
{
	$$ = $1 * $3;
}
expr: expr TOK_SLASH expr
{
	$$ = $1 / $3;
}
expr: TOK_OPEN_BRACKET expr TOK_CLOSE_BRACKET
{
	$$ = $2;
}
expr: expr TOK_POW expr
{
	$$ = pow($1,$3);
}
expr: NUMBER
{
	$$ = $1;
}
expr: TOK_SINUS TOK_OPEN_BRACKET expr TOK_CLOSE_BRACKET
{
	$$ = sin($3);
}
expr: TOK_COSINUS TOK_OPEN_BRACKET expr TOK_CLOSE_BRACKET
{
	$$ = cos($3);
}
expr: TOK_TANGENS TOK_OPEN_BRACKET expr TOK_CLOSE_BRACKET
{
	$$ = tan($3);
}
expr: TOK_COTANGENS TOK_OPEN_BRACKET expr TOK_CLOSE_BRACKET
{
	$$ = cos($3)/sin($3);
}
expr: TOK_EXP TOK_OPEN_BRACKET expr TOK_CLOSE_BRACKET
{
	$$ = exp($3);
}
