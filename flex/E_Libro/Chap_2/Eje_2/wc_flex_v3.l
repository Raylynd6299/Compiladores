/* Even more like UNIX wc, several files*/
%option noyywrap
%{
int chars = 0;
int words = 0;
int lines = 0;

int totchars = 0;
int totwords = 0;
int totlines = 0;
%}

%%

[a-zA-Z]+			{ words++; chars += strlen(yytext); }
\n					{ chars++; lines++; }
.					{ chars++; }

%%

int main( int argc, char **argv ){
	int iter;
	argc--, argv++;	
	
	if ( argc < 1){	
		yylex();
		printf( "C=%8d, W=%8d, L=%8d\n",chars,words,lines );
		return 0;
	}
	for( iter = 0; iter < argc; iter++ ){
		FILE *f = fopen( *(argv+iter), "r" );
		
		if( !f ){
			perror( *(argv+iter) );
			return(1);
		}
		
		yyrestart(f);
		yylex();
		fclose(f);	
		printf( "C=%8d, W=%8d, L=%8di  %s\n",chars,words,lines,*(argv+iter) );
		totchars += chars; chars = 0;
		totwords += words; words = 0;
		totlines += lines; lines = 0;
	}
	if(argc > 2)	
		printf( "C=%8d, W=%8d, L=%8d\n",totchars,totwords,totlines );
	return 0;
}
