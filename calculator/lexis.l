%{
#include "grammar.tab.h"
#include <stdlib.h>
#define DEBUG(o)
%}
%%
-?[0-9]+([\.\,]?[0-9]*)?		DEBUG(fprintf(stderr, "[ FLEX ] token NUMBER: %s token value: %lf\n",yytext,yylval);) yylval = atof(yytext); return NUMBER;
\(					return TOK_OPEN_BRACKET;
\)					return TOK_CLOSE_BRACKET;
\+					return TOK_PLUS;
-					return TOK_MINUS;
\*					return TOK_STAR;
\/					return TOK_SLASH;
\^					return TOK_POW;
sin					return TOK_SINUS;
cos					return TOK_COSINUS;
tan					return TOK_TANGENS;
ctg					return TOK_COTANGENS;
exp					return TOK_EXP;
[ \t]+					;
\n					return 0;
exit					exit(0);
%%
