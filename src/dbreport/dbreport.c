#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define yyclearin (yychar=(-1))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING (yyerrflag!=0)
static int yyparse(void);
#define YYPREFIX "yy"
#line 3 "../dbreport.y"

/**************************************************************************
 *
 *     Author:	Jim Kowalkowski
 *
 *      Experimental Physics and Industrial Control System (EPICS)
 *
 *      Copyright 1991, the Regents of the University of California,
 *      and the University of Chicago Board of Governors.
 *
 *      This software was produced under  U.S. Government contracts:
 *      (W-7405-ENG-36) at the Los Alamos National Laboratory,
 *      and (W-31-109-ENG-38) at Argonne National Laboratory.
 *
 *      Initial development by:
 *              The Controls and Automation Group (AT-8)
 *              Ground Test Accelerator
 *              Accelerator Technology Division
 *              Los Alamos National Laboratory
 *
 *      Co-developed with
 *              The Controls and Computing Group
 *              Accelerator Systems Division
 *              Advanced Photon Source
 *              Argonne National Laboratory
 *
 * Modification Log:
 * -----------------
 * .01	10-29-93	jbk	initial version
 *
 ***********************************************************************/

#include <stdio.h>
#include <string.h>

static int line_num;
static int yyerror();

/* one of these per report column */
struct fields
{
	char *name;
	int size;
};

extern char *optarg;
extern int optind;

#define DEFAULT_TOTAL 3
struct fields default_fields[] =
 { {"DESC",30},{"DTYP",30},{"OUT.INP",30},{NULL,0} };

struct fields* the_fields;
char** the_values;
int total_fields,type_len,name_len;
char form[2000];
char curr_rec[50];
char curr_type[50];

#line 73 "../dbreport.y"
typedef union
{
    int	Int;
	char Char;
	char *Str;
	double Real;
} YYSTYPE;
#line 78 "dbreport.tab.c"
#define COMMA 257
#define WORD 258
#define VALUE 259
#define FIELD 260
#define O_BRACE 261
#define C_BRACE 262
#define O_PAREN 263
#define C_PAREN 264
#define DATABASE 265
#define CONTAINER 266
#define RECORD 267
#define NOWHERE 268
#define YYERRCODE 256
static short yylhs[] = {                                        -1,
    0,    0,    0,    1,    1,    2,    4,    4,    5,    6,
    3,    3,    3,    8,   10,   11,    7,    7,    9,   12,
   12,   13,   13,   14,   14,   15,
};
static short yylen[] = {                                         2,
    3,    2,    1,    3,    5,    4,    0,    3,    2,    3,
    0,    2,    2,    3,    3,    3,    0,    2,    3,    5,
    5,    0,    3,    0,    2,    6,
};
static short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,   12,   13,    0,
    0,    1,    0,    0,    0,    0,    0,    4,    0,   11,
    0,   11,   14,    0,   24,   19,    0,    0,    0,    0,
   15,    0,    0,    0,    5,    9,   17,    8,    6,   16,
    0,    0,    0,   23,   25,    0,   20,   21,    0,   10,
   18,    0,    0,    0,   26,
};
static short yydgoto[] = {                                       2,
    5,   12,    3,   20,   29,   38,   46,    8,    9,   14,
   23,   16,   26,   34,   45,
};
static short yysindex[] = {                                   -263,
 -243,    0, -252, -253, -238, -236, -235,    0,    0, -257,
 -239,    0, -228, -230, -226, -227, -224,    0, -225,    0,
 -231,    0,    0, -221,    0,    0, -223, -222, -218, -258,
    0, -256, -233, -241,    0,    0,    0,    0,    0,    0,
 -220, -219, -217,    0,    0, -249,    0,    0, -211,    0,
    0, -209, -210, -214,    0,
};
static short yyrindex[] = {                                      3,
    0,    0,   37,    0,   39,    0,    0,    0,    0,    0,
 -250,    0,    0,    0,    0,    1,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
static short yygindex[] = {                                      0,
    0,    0,    2,    0,    0,    0,    0,    0,   -6,    0,
    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 270
static short yytable[] = {                                      17,
   22,    1,   11,   39,   10,   40,   18,    6,    7,    6,
    7,    7,   50,    6,    7,    7,    7,    7,   43,    4,
   44,   30,   11,   32,   41,   42,   13,   15,   19,   21,
   22,   24,   31,   25,   27,   33,    3,   28,    2,   51,
   35,   36,   37,   47,   48,   49,   52,   53,   54,   55,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   22,    0,    0,    0,   22,   22,   11,   11,
};
static short yycheck[] = {                                     257,
    0,  265,    0,  262,  258,  262,  264,  266,  267,  266,
  267,  262,  262,  266,  267,  266,  267,  267,  260,  263,
  262,   20,  261,   22,  258,  259,  263,  263,  268,  258,
  261,  258,  264,  261,  259,  257,    0,  263,    0,   46,
  264,  264,  261,  264,  264,  263,  258,  257,  259,  264,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  262,   -1,   -1,   -1,  266,  267,  266,  267,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 268
#if YYDEBUG
static char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"COMMA","WORD","VALUE","FIELD",
"O_BRACE","C_BRACE","O_PAREN","C_PAREN","DATABASE","CONTAINER","RECORD",
"NOWHERE",
};
static char *yyrule[] = {
"$accept : database",
"database : DATABASE d_head d_body",
"database : DATABASE d_head",
"database : db_components",
"d_head : O_PAREN WORD C_PAREN",
"d_head : O_PAREN WORD COMMA VALUE C_PAREN",
"d_body : O_BRACE nowhere_records db_components C_BRACE",
"nowhere_records :",
"nowhere_records : NOWHERE n_head n_body",
"n_head : O_PAREN C_PAREN",
"n_body : O_BRACE records C_BRACE",
"db_components :",
"db_components : db_components container",
"db_components : db_components record",
"container : CONTAINER c_head c_body",
"c_head : O_PAREN WORD C_PAREN",
"c_body : O_BRACE db_components C_BRACE",
"records :",
"records : records record",
"record : RECORD r_head r_body",
"r_head : O_PAREN WORD COMMA WORD C_PAREN",
"r_head : O_PAREN WORD COMMA VALUE C_PAREN",
"r_body :",
"r_body : O_BRACE fields C_BRACE",
"fields :",
"fields : fields field",
"field : FIELD O_PAREN WORD COMMA VALUE C_PAREN",
};
#endif
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH 500
#endif
#endif
#if YYDEBUG
static int yydebug;
#endif
static int yynerrs;
static int yyerrflag;
static int yychar;
static short *yyssp;
static YYSTYPE *yyvsp;
static YYSTYPE yyval;
static YYSTYPE yylval;
static short yyss[YYSTACKSIZE];
static YYSTYPE yyvs[YYSTACKSIZE];
#define yystacksize YYSTACKSIZE
#line 196 "../dbreport.y"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include "dbreport_lex.c"
#include <dbStaticLib.h> 
static int yyerror(str)
char  *str;
{ fprintf(stderr,"db file parse, Error line %d : %s\n",line_num, yytext); return 0; }

/*********************************************************************/
 
int main(int argc, char** argv)
{
	int i,c;
	int e=0;
	char* dbname = NULL;
	char* pc;
	char hold[20],thing[50];
	FILE* get_from_here = stdin;

	type_len=15;
	name_len=30;

	while(e==0 && (c=getopt(argc,argv,"f:t:n:"))!=-1)
	{
		switch(c)
		{
		case 'f': dbname = (char*)strdup(optarg); break; /* db name */
		case 't':
			/* type field length max */
			if(sscanf(optarg,"%d",&type_len)!=1)
			{
				fprintf(stderr,"illegal type field size --> %s\n",argv[optind]);
				return -1;
			}
			break;
		case 'n':
			if(sscanf(optarg,"%d",&name_len)!=1)
			{
				fprintf(stderr,"illegal name field size --> %s\n",argv[optind]);
				return -1;
			}
			break;
		default: e=1; break;
		}
	}

	if(e==1)
	{
		fprintf(stderr,
			"usage: %s [-t type_length] [-n name_length] [-f dbname.db] field.size field.size ...\n",argv[0]);
		fprintf(stderr,
			"\nWhere dbname.db is the name of a db file to report,\n");
		fprintf(stderr,
			"if no -f specified, then db file read from standard in.\n");
		fprintf(stderr,
			"\nfield.size is the actual name of the field to print\n");
		fprintf(stderr,
			"size is the max size allowed for the value in the report\n");
		fprintf(stderr,
			"you can have more than one field used in a line on the report\n");
		fprintf(stderr, "by specifying field.field.size (ex: OUT.INP.23 )\n");
		fprintf(stderr,
			"\nname_length is max length of the name field in the report\n");
		fprintf(stderr,
			"\ntype_length is max length of the type field in the report\n");
		return -1;
	}

	if(dbname)
	{
		if((get_from_here=fopen(dbname,"r"))==NULL)
		{
			fprintf(stderr,"cannot open db file %s\n",dbname);
			return -1;
		}
	}

	if(optind<argc)
	{
		/* the user specified fields (argc-optind) */
		the_fields=
			(struct fields*)malloc(1+sizeof(struct fields)*(argc-optind));
		the_values= (char**)malloc(sizeof(char*)*(argc-optind));

		for(i=0;optind<argc;i++,optind++)
		{
			strcpy(hold,argv[optind]);
			if((pc=strrchr(hold,'.'))==NULL)
			{
				fprintf(stderr,"illegal field --> %s\n",argv[optind]);
				return -1;
			}

			*pc++='\0';
			the_fields[i].name=strdup(hold);

			if(sscanf(pc,"%d",&the_fields[i].size)!=1)
			{
				fprintf(stderr,"illegal field size --> %s\n",argv[optind]);
				return -1;
			}
			the_values[i]=(char*)malloc(the_fields[i].size+1);
		}
		the_fields[i].name=NULL;
		the_fields[i].size=0;
		total_fields=i;
	}
	else
	{
		/* the user wants the default report */
		the_fields=default_fields;
		the_values=(char**)malloc(sizeof(char*)*DEFAULT_TOTAL);
		for(i=0;i<DEFAULT_TOTAL;i++)
		{
			the_values[i]=(char*)malloc(the_fields[i].size+1);
		}
		total_fields=DEFAULT_TOTAL;
	}

	sprintf(thing,"%%-%ds%%-%ds",type_len,name_len);
	printf(thing,"TYPE","NAME"); /* printf("%-15s%-30s","TYPE","NAME"); */

	for(i=0;i<total_fields;i++)
	{
		/* printf("%s:%d\n",the_fields[i].name,the_fields[i].size); */
		memset(the_values[i],' ',the_fields[i].size);
		the_values[i][the_fields[i].size]='\0';
		strncpy(the_values[i],the_fields[i].name,strlen(the_fields[i].name));
		printf("%s",the_values[i]);
	}
	printf("\n\n");

	yyin=get_from_here;
	yyparse();

            /*fclose(get_from_here);*/

	return 0;
}

#line 407 "dbreport.tab.c"
#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
static int
yyparse(void)
{
    int yym, yyn, yystate;
#if YYDEBUG
    char *yys;
    extern char *getenv();

    if ((yys = getenv("YYDEBUG")))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if ((yyn = yydefred[yystate])) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yyss + yystacksize - 1)
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
    yyerror("syntax error");
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yyss + yystacksize - 1)
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 4:
#line 89 "../dbreport.y"
{ free(yyvsp[-1].Str); }
break;
case 5:
#line 91 "../dbreport.y"
{ free(yyvsp[-3].Str); free(yyvsp[-1].Str); }
break;
case 15:
#line 118 "../dbreport.y"
{ free(yyvsp[-1].Str); }
break;
case 19:
#line 129 "../dbreport.y"
{
		int i;
		char temp[50];

		sprintf(temp,"%%-%ds%%-%ds",type_len,name_len);
		printf(temp,curr_type,curr_rec);
		/* printf("%-15s%-30s",curr_type,curr_rec); */
		for(i=0;i<total_fields;i++) printf("%s",the_values[i]);
		printf("\n");
	}
break;
case 20:
#line 142 "../dbreport.y"
{
		int i;
		for(i=0;i<total_fields;i++)
		{
			memset(the_values[i],' ',the_fields[i].size);
			the_values[i][the_fields[i].size]='\0';
		}
		strcpy(curr_type,yyvsp[-3].Str);
		strcpy(curr_rec,yyvsp[-1].Str);
		free(yyvsp[-3].Str); free(yyvsp[-1].Str);
	}
break;
case 21:
#line 154 "../dbreport.y"
{
		int i;
		for(i=0;i<total_fields;i++)
		{
			memset(the_values[i],' ',the_fields[i].size);
			the_values[i][the_fields[i].size]='\0';
		}
		strcpy(curr_type,yyvsp[-3].Str);
		strcpy(curr_rec,yyvsp[-1].Str);
		free(yyvsp[-3].Str); free(yyvsp[-1].Str);
	}
break;
case 26:
#line 176 "../dbreport.y"
{
		int i;
		char puken[50];
		char* pc;

		for(i=0;i<total_fields;i++)
		{
			strcpy(puken,the_fields[i].name);

			for(pc=strtok(puken,".");pc;pc=strtok(NULL,"."))
			{
				if( !strcmp(pc,yyvsp[-3].Str) )
					strncpy(the_values[i],yyvsp[-1].Str,strlen(yyvsp[-1].Str)<the_fields[i].size?strlen(yyvsp[-1].Str):the_fields[i].size-1);
			}
		}
		free(yyvsp[-3].Str); free(yyvsp[-1].Str);
	}
break;
#line 613 "dbreport.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yyss + yystacksize - 1)
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
