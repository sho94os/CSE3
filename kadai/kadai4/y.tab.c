#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20130304

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
/*
 * parser; Parser for PL-*
 */

#define MAXLENGTH 16

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "data-structures.h"
#include "symbol-table.h"

FILE *fp;
static const char *filename = "result.ll";

static int scope = GLOBAL_VAR;
static int count = 0;


#line 25 "parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
    int num;
    char ident[MAXLENGTH+1];
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 53 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define SBEGIN 257
#define DO 258
#define ELSE 259
#define SEND 260
#define FOR 261
#define FORWARD 262
#define FUNCTION 263
#define IF 264
#define PROCEDURE 265
#define PROGRAM 266
#define READ 267
#define THEN 268
#define TO 269
#define VAR 270
#define WHILE 271
#define WRITE 272
#define PLUS 273
#define MINUS 274
#define MULT 275
#define DIV 276
#define EQ 277
#define NEQ 278
#define LE 279
#define LT 280
#define GE 281
#define GT 282
#define LPAREN 283
#define RPAREN 284
#define LBRACKET 285
#define RBRACKET 286
#define COMMA 287
#define SEMICOLON 288
#define COLON 289
#define INTERVAL 290
#define PERIOD 291
#define ASSIGN 292
#define NUMBER 293
#define IDENT 294
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    5,    1,    2,    2,    6,    6,    7,    3,    3,
    9,    9,   10,   14,   11,   12,   13,   15,   15,    4,
    4,    4,    4,    4,    4,    4,    4,    4,   16,   17,
   27,   27,   28,   18,   19,   20,   29,   22,   23,   24,
   21,   26,   26,   26,   26,   26,   26,   25,   25,   25,
   25,   25,   30,   30,   30,   31,   31,   31,   32,   33,
   33,    8,    8,
};
static const short yylen[] = {                            2,
    5,    0,    4,    0,    2,    3,    1,    2,    0,    2,
    3,    1,    1,    0,    5,    1,    2,    3,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    3,    5,
    0,    2,    0,    5,    8,    1,    1,    3,    4,    4,
    0,    3,    3,    3,    3,    3,    3,    1,    2,    2,
    3,    3,    1,    3,    3,    1,    1,    3,    1,    1,
    3,    1,    3,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    7,   62,
    0,    1,    0,    2,    0,   12,   13,    0,    0,   16,
    0,    0,    0,    6,   63,   14,    0,    0,    0,    0,
   33,    0,    0,    3,   20,   21,   22,   23,   24,   25,
   26,   27,   28,   36,   11,    0,   19,    0,    0,    0,
    0,    0,   57,   59,    0,    0,    0,   53,   56,    0,
    0,    0,    0,    0,   15,   38,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   17,   18,    0,   58,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   54,
   55,   39,    0,   40,    0,    0,   30,   34,    0,   32,
    0,   35,
};
static const short yydgoto[] = {                          2,
    6,    7,   14,   34,   22,    8,    9,   11,   15,   16,
   17,   21,   65,   46,   48,   35,   36,   37,   38,   39,
   40,   41,   42,   43,   55,   56,  107,   61,   44,   57,
   58,   59,    0,
};
static const short yysindex[] = {                      -264,
 -285,    0, -273, -215, -260, -222, -198, -214,    0,    0,
 -209,    0, -213,    0, -188,    0,    0, -215, -191,    0,
 -177, -251, -198,    0,    0,    0, -251, -165,  -62, -151,
    0, -148, -152,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -215,    0, -246, -137, -181,
 -181,  -62,    0,    0,   -4, -132, -224,    0,    0, -153,
  -62,  -62,  -62, -251,    0,    0, -251,  -62, -224, -224,
 -225, -181, -181,  -62,  -62,  -62,  -62,  -62,  -62, -251,
 -181, -181, -125,  -96, -147, -156,    0,    0, -266,    0,
 -224, -224, -156, -156, -156, -156, -156, -156,  -91,    0,
    0,    0, -251,    0,  -62, -251,    0,    0, -159,    0,
 -251,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0, -201,    0,    0, -184,    0,    0,    0,
 -107,    0,    0,    0,    0,    0,    0, -226,    0,    0,
    0, -128, -175,    0,    0,    0, -203,    0,    0,    0,
    0,    0, -255,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -166,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -135,    0,    0,    0,
    0,    0,    0, -106,    0,    0, -203,    0, -108,  -81,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -241,
    0,    0,    0,    0,    0, -230,    0,    0,    0,    0,
  -54,  -20, -236, -164, -110, -104, -101,  -83, -216,    0,
    0,    0, -241,    0,    0, -241,    0,    0,    0,    0,
 -241,    0,
};
static const short yygindex[] = {                         0,
    0,  138,    0,  -27,    0,    0,  168,    0,    0,  166,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -51,  129,    0,    0,    0,   58,
   39,    0,    0,
};
#define YYTABLESIZE 278
static const short yytable[] = {                         47,
   71,    1,  105,   37,   37,   27,   72,   73,    3,   28,
   85,   86,   29,   66,    4,   30,   89,   41,   41,   31,
   32,   42,   93,   94,   95,   96,   97,   98,   29,   29,
    5,   42,   37,   10,    5,   37,   87,    5,    5,   88,
    5,   67,   33,   31,    5,    5,   41,   72,   73,   41,
   81,   82,   99,  109,    5,    4,   41,   29,   90,    4,
   29,    5,    4,    4,    5,    4,   13,    5,   12,    4,
    4,   31,    9,   18,   31,  108,    9,   19,  110,    9,
   20,   10,    9,  112,   41,   10,    9,    9,   10,    4,
    4,   10,    4,   43,    4,   10,   10,    4,  111,   23,
    4,   52,   25,   43,    4,    4,    9,   69,   70,    9,
   26,   53,   54,   72,   73,   10,   72,   73,   10,  100,
  101,    4,   48,   48,   48,   72,   73,    4,   49,   91,
   92,   60,   48,   48,   62,   80,  104,   48,   48,   63,
   83,   48,   48,   48,   48,   48,   48,   45,   48,   49,
   49,   49,   48,   44,   68,   48,   47,   45,  102,   49,
   49,  103,   41,   44,   49,   49,   47,  106,   49,   49,
   49,   49,   49,   49,   46,   49,   50,   50,   50,   49,
    8,   41,   49,   64,   46,   24,   50,   50,   45,   84,
    0,   50,   50,    0,    0,   50,   50,   50,   50,   50,
   50,    0,   50,   51,   51,   51,   50,    0,    0,   50,
   50,   51,    0,   51,   51,    0,    0,    0,   51,   51,
   52,    0,   51,   51,   51,   51,   51,   51,    0,   51,
   53,   54,    0,   51,    0,    0,   51,   52,   52,   52,
    0,    0,    0,    0,    0,    0,    0,   52,   52,    0,
    0,    0,   52,   52,    0,    0,   52,   52,   52,   52,
   52,   52,    0,   52,    0,    0,    0,   52,   72,   73,
   52,    0,   74,   75,   76,   77,   78,   79,
};
static const short yycheck[] = {                         27,
   52,  266,  269,  259,  260,  257,  273,  274,  294,  261,
   62,   63,  264,  260,  288,  267,   68,  259,  260,  271,
  272,  258,   74,   75,   76,   77,   78,   79,  259,  260,
  257,  268,  288,  294,  261,  291,   64,  264,  265,   67,
  267,  288,  294,  260,  271,  272,  288,  273,  274,  291,
  275,  276,   80,  105,  270,  257,  260,  288,  284,  261,
  291,  288,  264,  265,  291,  267,  265,  294,  291,  271,
  272,  288,  257,  288,  291,  103,  261,  287,  106,  264,
  294,  257,  267,  111,  288,  261,  271,  272,  264,  291,
  257,  267,  294,  258,  261,  271,  272,  264,  258,  288,
  267,  283,  294,  268,  271,  272,  291,   50,   51,  294,
  288,  293,  294,  273,  274,  291,  273,  274,  294,   81,
   82,  288,  258,  259,  260,  273,  274,  294,  294,   72,
   73,  283,  268,  269,  283,  268,  284,  273,  274,  292,
  294,  277,  278,  279,  280,  281,  282,  258,  284,  258,
  259,  260,  288,  258,  292,  291,  258,  268,  284,  268,
  269,  258,  291,  268,  273,  274,  268,  259,  277,  278,
  279,  280,  281,  282,  258,  284,  258,  259,  260,  288,
  288,  288,  291,   46,  268,   18,  268,  269,   23,   61,
   -1,  273,  274,   -1,   -1,  277,  278,  279,  280,  281,
  282,   -1,  284,  258,  259,  260,  288,   -1,   -1,  291,
  273,  274,   -1,  268,  269,   -1,   -1,   -1,  273,  274,
  283,   -1,  277,  278,  279,  280,  281,  282,   -1,  284,
  293,  294,   -1,  288,   -1,   -1,  291,  258,  259,  260,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  268,  269,   -1,
   -1,   -1,  273,  274,   -1,   -1,  277,  278,  279,  280,
  281,  282,   -1,  284,   -1,   -1,   -1,  288,  273,  274,
  291,   -1,  277,  278,  279,  280,  281,  282,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 294
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"SBEGIN","DO","ELSE","SEND","FOR",
"FORWARD","FUNCTION","IF","PROCEDURE","PROGRAM","READ","THEN","TO","VAR",
"WHILE","WRITE","PLUS","MINUS","MULT","DIV","EQ","NEQ","LE","LT","GE","GT",
"LPAREN","RPAREN","LBRACKET","RBRACKET","COMMA","SEMICOLON","COLON","INTERVAL",
"PERIOD","ASSIGN","NUMBER","IDENT",
};
static const char *yyrule[] = {
"$accept : program",
"program : PROGRAM IDENT SEMICOLON outblock PERIOD",
"$$1 :",
"outblock : var_decl_part subprog_decl_part $$1 statement",
"var_decl_part :",
"var_decl_part : var_decl_list SEMICOLON",
"var_decl_list : var_decl_list SEMICOLON var_decl",
"var_decl_list : var_decl",
"var_decl : VAR id_list",
"subprog_decl_part :",
"subprog_decl_part : subprog_decl_list SEMICOLON",
"subprog_decl_list : subprog_decl_list SEMICOLON subprog_decl",
"subprog_decl_list : subprog_decl",
"subprog_decl : proc_decl",
"$$2 :",
"proc_decl : PROCEDURE proc_name SEMICOLON $$2 inblock",
"proc_name : IDENT",
"inblock : var_decl_part statement",
"statement_list : statement_list SEMICOLON statement",
"statement_list : statement",
"statement : assignment_statement",
"statement : if_statement",
"statement : while_statement",
"statement : for_statement",
"statement : proc_call_statement",
"statement : null_statement",
"statement : block_statement",
"statement : read_statement",
"statement : write_statement",
"assignment_statement : IDENT ASSIGN expression",
"if_statement : IF condition THEN statement else_statement",
"else_statement :",
"else_statement : ELSE statement",
"$$3 :",
"while_statement : WHILE $$3 condition DO statement",
"for_statement : FOR IDENT ASSIGN expression TO expression DO statement",
"proc_call_statement : proc_call_name",
"proc_call_name : IDENT",
"block_statement : SBEGIN statement_list SEND",
"read_statement : READ LPAREN IDENT RPAREN",
"write_statement : WRITE LPAREN expression RPAREN",
"null_statement :",
"condition : expression EQ expression",
"condition : expression NEQ expression",
"condition : expression LT expression",
"condition : expression LE expression",
"condition : expression GT expression",
"condition : expression GE expression",
"expression : term",
"expression : PLUS term",
"expression : MINUS term",
"expression : expression PLUS term",
"expression : expression MINUS term",
"term : factor",
"term : term MULT factor",
"term : term DIV factor",
"factor : var_name",
"factor : NUMBER",
"factor : LPAREN expression RPAREN",
"var_name : IDENT",
"arg_list : expression",
"arg_list : arg_list COMMA expression",
"id_list : IDENT",
"id_list : id_list COMMA IDENT",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 264 "parser.y"


yyerror(char *s)
{
        extern int yylineno;
        extern char *yytext;

        fprintf(
                stderr,
                "%s\nline number: %d\nmessage:\n%s\n",
                s, yylineno, yytext
        );
}
#line 394 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
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
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
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

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
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
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 49 "parser.y"
	{
                if ((fp = fopen(filename, "w")) == NULL) {
                        fprintf(stderr, "ファイルのオープンに失敗しました．\n");
                return EXIT_FAILURE;
                }
                display_llvm();
                fclose(fp);
        }
break;
case 2:
#line 60 "parser.y"
	{
                insert_decl("main", 0, NULL);
                Factor x = {CONSTANT, "1", 0};
                factor_push(x);
                insert_code(Alloca);
                insert_code(Store);
        }
break;
case 14:
#line 99 "parser.y"
	{
        scope = LOCAL_VAR;
        count = 1;
        }
break;
case 15:
#line 104 "parser.y"
	{
        delete_local_symbol();
        scope = GLOBAL_VAR;
        }
break;
case 16:
#line 112 "parser.y"
	{
        insert_symbol(PROC_NAME, yystack.l_mark[0].ident, 1);
        insert_decl(yystack.l_mark[0].ident, 0, NULL);
        }
break;
case 29:
#line 141 "parser.y"
	{
        Factor x = create_factor_by_name(yystack.l_mark[-2].ident);
        factor_push(x);
        insert_code(Store);
        }
break;
case 33:
#line 158 "parser.y"
	{
                insert_code(Label);
        }
break;
case 35:
#line 165 "parser.y"
	{lookup_symbol(yystack.l_mark[-6].ident);}
break;
case 37:
#line 174 "parser.y"
	{lookup_symbol(yystack.l_mark[0].ident);}
break;
case 39:
#line 183 "parser.y"
	{lookup_symbol(yystack.l_mark[-1].ident);}
break;
case 51:
#line 208 "parser.y"
	{insert_code(Add);}
break;
case 52:
#line 210 "parser.y"
	{insert_code(Sub);
        }
break;
case 54:
#line 217 "parser.y"
	{insert_code(Mult);}
break;
case 55:
#line 219 "parser.y"
	{insert_code(Div);}
break;
case 57:
#line 224 "parser.y"
	{
        Factor x = {CONSTANT, "", yystack.l_mark[0].num};
        factor_push(x);}
break;
case 59:
#line 232 "parser.y"
	{
        Factor x = create_factor_by_name(yystack.l_mark[0].ident);
        factor_push(x);
        insert_code(Load);
        }
break;
case 62:
#line 246 "parser.y"
	{
                insert_symbol(scope, yystack.l_mark[0].ident, count);
                if (scope == LOCAL_VAR) {
                        insert_code(Alloca);
                };
                count++;
        }
break;
case 63:
#line 254 "parser.y"
	{
                insert_symbol(scope, yystack.l_mark[0].ident, count);
                if (scope == LOCAL_VAR) {
                        insert_code(Alloca);
                };
                count++;
        }
break;
#line 719 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
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
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
