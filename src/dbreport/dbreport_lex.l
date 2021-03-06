

pvname	[a-zA-Z0-9_\-:\.\[\]<>]
value	[a-zA-Z0-9_\,\./\*#\[\]%: ;!|\'\-&\(\)@\?\+<>=\$\{\}\^\~]

%{
%}

%%

\#.*\n	;

"field"	    { return(FIELD); }
"grecord"   { return(RECORD); }
"record"    { return(RECORD); }
"container" { return(CONTAINER); }
"database"  { return(DATABASE); }
"nowhere"   { return(NOWHERE); }
"info"      { return(FIELD); }
"alias"     { return(FIELD); }

\"{value}*\"    { yylval.Str=(char *)malloc(strlen((const char*) yytext)+1); strcpy(yylval.Str,yytext+1); yylval.Str[strlen((const char*) yylval.Str)-1] = '\0'; return(VALUE); }

{pvname}+	{ yylval.Str=(char *)malloc(strlen( (const char*) yytext)+1); strcpy(yylval.Str,yytext); return(WORD);	}

"{"	{ return(O_BRACE);	}
"}"	{ return(C_BRACE);	}
"("	{ return(O_PAREN);	}
")"	{ return(C_PAREN);	}
","	{ return(COMMA);	}

.	;
\n	{ line_num ++;}

%%

