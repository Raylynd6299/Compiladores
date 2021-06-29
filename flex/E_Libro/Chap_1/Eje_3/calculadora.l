/* recognize the token for the calculator and print then out */
%{
	enum yytokentype{
		NUMBER = 258,
		ADD = 259,
		SUB = 260,
		MUL = 261,
		DIV = 262,
		ABS = 263,
		EOL = 264
	};
	int yylval;
%}

%%
"+"			{ return ADD; }
"-"			{ return SUB; }
"*"			{ return MUL; }	
"/"			{ return DIV; }
"|"			{ return ABS; }
[0-9]+		{ yylval = atoi( yytext ); return NUMBER; }
\n			{ return EOL; }	
[ \t]		{/* ignore whitespace */}
.			{ printf("Mystery character %c\n", *yytext); }
%%
int main( int argc, char **argv ){
	argv++, argc--;
	int token;

	while(token = yylex()) {
		printf("%d",token);
		if( token == NUMBER ) 
			printf(" = %d\n",yylval);
		else 	
			printf("\n");
	}
}
