/* Even more like UNIX wc*/
%option noyywrap
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
	if ( argc > 0 ){
		if ( !( yyin = fopen( *argv, "r" ) ) ){
			perror(*argv);	
			return(1);
		} 
	}else{
		yyin = stdin;
	}
	yylex();
	printf( "C=%8d, W=%8d, L=%8d\n",chars,words,lines );
}
