/* Just like UNIX wc*/
%{
int chars = 0;
int words = 0;
int lines = 0;
%}

%%

[^ \t\n\r\f\v]+		{ words++; chars += strlen(yytext); }
\n					{ chars++; lines++; }
.					{ chars++; }

%%

int main( int argc, char **argv ){
	++argv, --argc;
	if ( argc > 0 )
		yyin = fopen( *argv, "r" );
	else
		yyin = stdin;
	yylex();
	printf( "%8d%8d%8d\n",chars,words,lines );
}
