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
extern reg_counter;
extern ret_type;


/*前の値を積んでいくスタックを作るとネストにも対応できそう*/
int tmp;
int tmp1,tmp2, tmp3;

int i = 0;
int var_mode = FALSE;
int arity_mode = FALSE;
int func_mode = FALSE;

int var_num = 0;
int arity_num = 0;

Factor tmp1_element[100];
int tmp1_top = 0;

Factor tmp2_element[100];
int tmp2_top = 0;

#line 45 "parser.y"
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
#line 73 "y.tab.c"

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
    0,    7,    3,    4,    4,    8,    8,   11,    9,    5,
    5,   12,   12,   13,   13,   17,   14,   18,   19,   14,
    1,   20,   15,   21,   22,   15,   23,   16,   24,   24,
    6,    6,    6,    6,    6,    6,    6,    6,    6,   25,
   36,   38,   26,   37,   39,   37,   40,   41,   27,   42,
   43,   28,   29,   45,   29,    2,   31,   32,   33,   30,
   35,   35,   35,   35,   35,   35,   34,   34,   34,   34,
   34,   46,   46,   46,   47,   47,   47,   47,   48,   49,
   44,   44,   10,   10,
};
static const short yylen[] = {                            2,
    5,    0,    4,    0,    2,    3,    1,    0,    3,    0,
    2,    3,    1,    1,    1,    0,    5,    0,    0,    9,
    1,    0,    5,    0,    0,    9,    0,    3,    3,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    3,
    0,    0,    7,    0,    0,    3,    0,    0,    6,    0,
    0,   10,    1,    0,    5,    1,    3,    4,    4,    0,
    3,    3,    3,    3,    3,    3,    1,    2,    2,    3,
    3,    1,    3,    3,    1,    1,    1,    3,    1,    4,
    1,    3,    1,    3,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    8,    0,    0,    0,    7,    0,
    1,    0,    0,    2,    0,   13,   14,   15,    0,   83,
    0,    0,   21,    0,    0,    0,    6,    0,   22,    0,
   16,    0,    0,    0,    0,    0,   47,    0,    0,    0,
    3,   31,   32,   33,   34,   35,   36,   37,   38,   39,
   12,   84,    0,    0,    0,    0,   30,    0,    0,    0,
    0,    0,   76,    0,    0,    0,    0,    0,   72,   75,
   77,    0,    0,    0,    0,    0,   27,   23,    0,   17,
    0,   57,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   41,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   29,    0,
   78,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   73,   74,   58,   48,   59,    0,    0,   28,   25,
   19,    0,   80,   42,    0,    0,   55,    0,    0,    0,
    0,   49,   26,   20,    0,   45,   43,    0,    0,    0,
   46,   52,
};
static const short yydgoto[] = {                          2,
   65,   40,    6,   77,   14,   41,   25,    8,    9,   21,
   10,   15,   16,   17,   18,   78,   55,   32,  139,   53,
   30,  138,  106,   58,   42,   43,   44,   45,   46,   47,
   48,   49,   50,   66,   67,  121,  147,  141,  149,   73,
  135,  132,  148,  105,  128,   68,   69,   70,   71,
};
static const short yysindex[] = {                      -261,
 -273,    0, -250, -224,    0, -213, -259, -201,    0, -185,
    0, -180, -166,    0, -111,    0,    0,    0, -224,    0,
 -143, -106,    0, -105, -254, -259,    0, -102,    0,  -87,
    0,  -79, -254,  -97, -115,  -76,    0,  -75,  -80,  -72,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -224, -185, -224, -185,    0, -240,  -68, -271,
 -271, -115,    0,    0,  -70,   59,  -52, -113,    0,    0,
    0,  -77, -115, -115, -115, -115,    0,    0, -189,    0,
 -150,    0, -254, -115, -113, -113, -265, -115, -271, -271,
 -115, -115, -115, -115, -115, -115,    0, -271, -271,  -58,
  -31, -148, -104, -104,  -57, -254,  -51,  -50,    0, -104,
    0, -144, -113, -113, -104, -104, -104, -104, -104, -104,
 -254,    0,    0,    0,    0,    0, -115,  -53,    0,    0,
    0,  -30,    0,    0, -254, -104,    0, -224, -224, -115,
  -23,    0,    0,    0, -104,    0,    0,  -18, -254, -254,
    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0, -208,    0,    0, -195,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -220,    0,
  -47,  -41,    0,  -38,  -45, -167,    0,    0,    0,    0,
    0,    0, -234,    0,    0,    0,    0,    0, -153, -230,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -149,    0, -149,    0,    0,    0,    0,    0,
    0,    0,    0, -127,    0,    0,    0,  -93,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -234,    0,  -59,  -25,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -178,  -94,  -37,  -28,    0,    0,    0,  -19,
    0,    0,    9,   43, -198, -193, -179, -165, -157, -139,
  -86,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -86,  -81,    0, -149, -149,    0,
 -249,    0,    0,    0,   -7,    0,    0,    0,  -86,  -86,
    0,    0,
};
static const short yygindex[] = {                         0,
  245,    0,    0,  257,    0,  -33,    0,    0,  246,  -29,
    0,    0,  238,    0,    0,  -54,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -60,  197,    0,    0,    0,    0,    0,
    0,    0,    0,  183,    0,   31,   73,    0,    0,
};
#define YYTABLESIZE 341
static const short yytable[] = {                         57,
   80,   87,   33,   12,    1,   13,   34,   89,   90,   35,
   44,   62,   36,  102,  103,  104,   37,   38,  111,   82,
    3,   63,   64,  110,   79,   60,   81,  104,   53,   53,
  115,  116,  117,  118,  119,  120,    5,    4,   44,   39,
    5,   44,    5,    5,    5,    5,    5,   83,    4,  109,
    5,    5,    4,   60,    4,    4,    4,   53,    4,   61,
   53,   10,    4,    4,   62,   10,  136,    5,   10,   61,
    5,   10,  129,    5,   62,   10,   10,   11,   64,  145,
   40,   40,    4,  143,  144,    4,   19,  134,   64,   11,
   85,   86,   63,   11,  107,   10,   11,   28,   10,   11,
   66,  142,   63,   11,   11,   56,   56,    4,   20,   40,
   66,    4,   40,   22,    4,  151,  152,    4,   65,  113,
  114,    4,    4,   11,   89,   90,   11,   23,   65,   56,
   79,   79,   79,  108,   56,  126,   28,   56,    4,  133,
   79,   79,  127,   28,    4,   79,   79,   79,   79,   79,
   79,   79,   79,   79,   79,   21,   79,   60,   61,   79,
   79,   98,   99,   79,   67,   67,   67,   62,   89,   90,
  122,  123,   60,   60,   67,   67,   26,   63,   64,   67,
   67,   29,   31,   67,   67,   67,   67,   67,   67,   81,
   67,   52,   81,   67,   67,   54,   59,   67,   68,   68,
   68,   60,   82,   56,   60,   82,   72,   74,   68,   68,
   76,   75,   88,   68,   68,   97,  100,   68,   68,   68,
   68,   68,   68,   84,   68,  124,  125,   68,   68,  127,
  137,   68,   69,   69,   69,  146,  130,  131,  140,  150,
    9,   24,   69,   69,   18,   60,   54,   69,   69,   50,
   51,   69,   69,   69,   69,   69,   69,   24,   69,   60,
    7,   69,   69,   51,   27,   69,   70,   70,   70,  101,
  112,    0,    0,    0,    0,    0,   70,   70,    0,    0,
    0,   70,   70,    0,    0,   70,   70,   70,   70,   70,
   70,    0,   70,    0,    0,   70,   70,    0,    0,   70,
   71,   71,   71,    0,    0,    0,    0,    0,    0,    0,
   71,   71,    0,    0,    0,   71,   71,    0,    0,   71,
   71,   71,   71,   71,   71,    0,   71,    0,    0,   71,
   71,   89,   90,   71,    0,   91,   92,   93,   94,   95,
   96,
};
static const short yycheck[] = {                         33,
   55,   62,  257,  263,  266,  265,  261,  273,  274,  264,
  260,  283,  267,   74,   75,   76,  271,  272,  284,  260,
  294,  293,  294,   84,   54,  260,   56,   88,  259,  260,
   91,   92,   93,   94,   95,   96,  257,  288,  288,  294,
  261,  291,  263,  264,  265,  270,  267,  288,  257,   83,
  271,  272,  261,  288,  263,  264,  265,  288,  267,  258,
  291,  257,  271,  272,  258,  261,  127,  288,  264,  268,
  291,  267,  106,  294,  268,  271,  272,  291,  258,  140,
  259,  260,  291,  138,  139,  294,  288,  121,  268,  257,
   60,   61,  258,  261,  284,  291,  264,  287,  294,  267,
  258,  135,  268,  271,  272,  259,  260,  257,  294,  288,
  268,  261,  291,  294,  264,  149,  150,  267,  258,   89,
   90,  271,  272,  291,  273,  274,  294,  294,  268,  283,
  258,  259,  260,  284,  288,  284,  287,  291,  288,  284,
  268,  269,  287,  287,  294,  273,  274,  275,  276,  277,
  278,  279,  280,  281,  282,  283,  284,  273,  274,  287,
  288,  275,  276,  291,  258,  259,  260,  283,  273,  274,
   98,   99,  259,  260,  268,  269,  288,  293,  294,  273,
  274,  288,  288,  277,  278,  279,  280,  281,  282,  284,
  284,  294,  287,  287,  288,  283,  294,  291,  258,  259,
  260,  288,  284,  283,  291,  287,  283,  283,  268,  269,
  283,  292,  283,  273,  274,  268,  294,  277,  278,  279,
  280,  281,  282,  292,  284,  284,  258,  287,  288,  287,
  284,  291,  258,  259,  260,  259,  288,  288,  269,  258,
  288,  283,  268,  269,  283,  291,  284,  273,  274,  269,
  258,  277,  278,  279,  280,  281,  282,   13,  284,  288,
    4,  287,  288,   26,   19,  291,  258,  259,  260,   73,
   88,   -1,   -1,   -1,   -1,   -1,  268,  269,   -1,   -1,
   -1,  273,  274,   -1,   -1,  277,  278,  279,  280,  281,
  282,   -1,  284,   -1,   -1,  287,  288,   -1,   -1,  291,
  258,  259,  260,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  268,  269,   -1,   -1,   -1,  273,  274,   -1,   -1,  277,
  278,  279,  280,  281,  282,   -1,  284,   -1,   -1,  287,
  288,  273,  274,  291,   -1,  277,  278,  279,  280,  281,
  282,
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
"$$2 :",
"var_decl : VAR $$2 id_list",
"subprog_decl_part :",
"subprog_decl_part : subprog_decl_list SEMICOLON",
"subprog_decl_list : subprog_decl_list SEMICOLON subprog_decl",
"subprog_decl_list : subprog_decl",
"subprog_decl : proc_decl",
"subprog_decl : func_decl",
"$$3 :",
"proc_decl : PROCEDURE proc_func_name SEMICOLON $$3 inblock",
"$$4 :",
"$$5 :",
"proc_decl : PROCEDURE proc_func_name $$4 LPAREN id_list RPAREN SEMICOLON $$5 inblock",
"proc_func_name : IDENT",
"$$6 :",
"func_decl : FUNCTION IDENT SEMICOLON $$6 inblock",
"$$7 :",
"$$8 :",
"func_decl : FUNCTION IDENT $$7 LPAREN id_list RPAREN SEMICOLON $$8 inblock",
"$$9 :",
"inblock : var_decl_part $$9 statement",
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
"$$10 :",
"$$11 :",
"if_statement : IF condition THEN $$10 statement $$11 else_statement",
"else_statement :",
"$$12 :",
"else_statement : ELSE $$12 statement",
"$$13 :",
"$$14 :",
"while_statement : WHILE $$13 condition DO $$14 statement",
"$$15 :",
"$$16 :",
"for_statement : FOR IDENT ASSIGN expression $$15 TO expression $$16 DO statement",
"proc_call_statement : proc_call_name",
"$$17 :",
"proc_call_statement : proc_call_name LPAREN arg_list $$17 RPAREN",
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
"factor : func_call",
"factor : LPAREN expression RPAREN",
"var_name : IDENT",
"func_call : proc_func_name LPAREN arg_list RPAREN",
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
#line 499 "parser.y"


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
#line 467 "y.tab.c"

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
#line 71 "parser.y"
	{
        if ((fp = fopen(filename, "w")) == NULL) return EXIT_FAILURE;
        display_llvm();
        fclose(fp);
        }
break;
case 2:
#line 79 "parser.y"
	{
        insert_decl("main", 0, NULL, VOID);
        Factor x = {CONSTANT, "1", 0};
        factor_push(x);
        /*mainが引数をとるようになるならここにoverwriteの処理を挟む*/
        reg_counter = 1;
        insert_code(Alloca);
        insert_code(Store);
        }
break;
case 3:
#line 88 "parser.y"
	{
        back_patch();
        }
break;
case 8:
#line 104 "parser.y"
	{
        var_mode = TRUE;
        }
break;
case 9:
#line 106 "parser.y"
	{
        var_mode = FALSE;
        }
break;
case 16:
#line 127 "parser.y"
	{
        scope = LOCAL_VAR;
        count = 0;
        var_num = 0;
        arity_num = 0;
        insert_symbol(PROC_NAME, yystack.l_mark[-1].ident, 0);
        insert_decl(yystack.l_mark[-1].ident, 0, NULL, VOID);
        reg_counter = count + 1;
        count++;
        }
break;
case 17:
#line 137 "parser.y"
	{
        back_patch();
        insert_code(Ret);
        delete_local_symbol();
        scope = GLOBAL_VAR;
        }
break;
case 18:
#line 144 "parser.y"
	{
        scope = LOCAL_VAR;
        count = 0;
        var_num = 0;
        arity_num = 0;
        insert_symbol(PROC_NAME, yystack.l_mark[0].ident, count);
        arity_mode = TRUE;
        }
break;
case 19:
#line 152 "parser.y"
	{
        arity_mode = FALSE;
        /*レジスタの値は返り値分一つ増やしておく*/
        /*reg_counter: 引数(n個),返り値(1個),局所変数(m個), 中身(k個)の順に番号づけされる*/
        overwrite_symbol_arity(yystack.l_mark[-5].ident, arity_num);
        insert_decl(yystack.l_mark[-5].ident, arity_num, NULL, VOID);
        reg_counter = count + 1;
        count++;
        }
break;
case 20:
#line 161 "parser.y"
	{
        back_patch();
        insert_code(Ret);
        delete_local_symbol();
        scope = GLOBAL_VAR;
        }
break;
case 22:
#line 176 "parser.y"
	{
        scope = LOCAL_VAR;
        count = 0;
        var_num = 0;
        arity_num = 0;
        ret_type = INT;
        insert_symbol(FUNC_NAME, yystack.l_mark[-1].ident, count);
        insert_symbol(LOCAL_VAR, yystack.l_mark[-1].ident, count);
        insert_decl(yystack.l_mark[-1].ident, 0, NULL, INT);
        reg_counter = count + 1;
        count++;
        }
break;
case 23:
#line 187 "parser.y"
	{
        back_patch();
        Factor x = create_factor_by_name(yystack.l_mark[-3].ident);
        factor_push(x);
        insert_code(Load);
        insert_code(Ret);
        delete_local_symbol();
        ret_type = VOID;
        scope = GLOBAL_VAR;
        }
break;
case 24:
#line 198 "parser.y"
	{
        scope = LOCAL_VAR;
        count = 0;
        var_num = 0;
        arity_num = 0;
        ret_type = INT;
        insert_symbol(FUNC_NAME, yystack.l_mark[0].ident, count);
        insert_symbol(LOCAL_VAR, yystack.l_mark[0].ident, count);
        func_mode = TRUE;
        arity_mode = TRUE;
        }
break;
case 25:
#line 208 "parser.y"
	{
        arity_mode = FALSE;
        overwrite_symbol_arity(yystack.l_mark[-5].ident, arity_num);
        insert_decl(yystack.l_mark[-5].ident, arity_num, NULL, INT);
        reg_counter = count + 1;
        count++;
        }
break;
case 26:
#line 214 "parser.y"
	{
        func_mode = FALSE;
        back_patch();
        Factor x = create_factor_by_name(yystack.l_mark[-7].ident);
        factor_push(x);
        insert_code(Load);
        insert_code(Ret);
        delete_local_symbol();
        ret_type = VOID;
        scope = GLOBAL_VAR;
        }
break;
case 27:
#line 228 "parser.y"
	{
                for (i = 0; i < var_num + arity_num; i++) {
                        tmp1_element[i] = factor_pop();
                        tmp1_top++;
                }
                for (i = 0; i < var_num + arity_num + func_mode; i++) {
                        insert_code(Alloca);
                }
                for (i = 0; i < var_num + arity_num; i++) {
                        tmp2_element[i] = factor_pop();
                        tmp2_top++;
                }
                for (i = var_num + arity_num ; i > var_num; i--) {
                        factor_push(tmp1_element[i-1]);
                        factor_push(tmp2_element[i-1]);
                        insert_code(Store);
                }
                tmp1_top = 0;
                tmp2_top = 0;
                /*記号表のアドレスの更新,新しいlocal varを突っ込む,引数は全てlocalだから上書きオッケー*/
                /*関数呼び出しの時は、返り値用の変数が事前に宣言されていると考える*/
                overwrite_symbol_val(var_num + func_mode, arity_num);
        }
break;
case 40:
#line 271 "parser.y"
	{
        Factor x = create_factor_by_name(yystack.l_mark[-2].ident);
        factor_push(x);
        insert_code(Store);
        }
break;
case 41:
#line 279 "parser.y"
	{
        insert_code(BrCond);
        insert_code(Label);
        }
break;
case 42:
#line 283 "parser.y"
	{
        insert_code(BrUncond);
        label_push(reg_counter);
        }
break;
case 44:
#line 291 "parser.y"
	{
        label_push(reg_counter);
        insert_code(Label);
        }
break;
case 45:
#line 295 "parser.y"
	{
        insert_code(Label);
        }
break;
case 46:
#line 298 "parser.y"
	{
        insert_code(BrUncond);
        label_push(reg_counter);
        label_push(reg_counter);
        insert_code(Label);
        }
break;
case 47:
#line 307 "parser.y"
	{
        insert_code(BrUncond);
        label_push(reg_counter);
        tmp = reg_counter;
        insert_code(Label);
        }
break;
case 48:
#line 313 "parser.y"
	{
        insert_code(BrCond);
        insert_code(Label);
        }
break;
case 49:
#line 317 "parser.y"
	{
        insert_code(BrUncond);
        label_push(reg_counter);
        label_push(tmp);
        insert_code(Label);
        }
break;
case 50:
#line 326 "parser.y"
	{
        Factor x = create_factor_by_name(yystack.l_mark[-2].ident);
        factor_push(x);
        insert_code(Store);
        insert_code(BrUncond);
        label_push(reg_counter);
        tmp1 = reg_counter;
        insert_code(Label);
        factor_push(x);
        insert_code(Load);
        }
break;
case 51:
#line 337 "parser.y"
	{
        set_cmp_type(SLE);
        insert_code(Icmp);
        insert_code(BrCond);
        insert_code(Label);
        }
break;
case 52:
#line 343 "parser.y"
	{
        insert_code(BrUncond);
        tmp2 = reg_counter;
        insert_code(Label);
        Factor x = create_factor_by_name(yystack.l_mark[-8].ident);
        factor_push(x);
        insert_code(Load);
        Factor for_factor = {CONSTANT, "", 1};
        factor_push(for_factor);
        insert_code(Add);
        factor_push(x);
        insert_code(Store);
        insert_code(BrUncond);
        tmp3 = reg_counter;
        label_push(tmp3);
        label_push(tmp2);
        label_push(tmp1);
        insert_code(Label);
        }
break;
case 53:
#line 365 "parser.y"
	{
        Factor x = create_proc_or_func_factor(yystack.l_mark[0].ident, get_aritystack_top());
        factor_push(x);
        insert_code(Proc);
        }
break;
case 54:
#line 370 "parser.y"
	{
        Factor x = create_proc_or_func_factor(yystack.l_mark[-2].ident, get_aritystack_top());
        factor_push(x);
        insert_code(Proc);
        }
break;
case 58:
#line 386 "parser.y"
	{
        set_read_flag(TRUE);
        Factor x = create_factor_by_name(yystack.l_mark[-1].ident);
        factor_push(x);
        insert_code(Read);
        }
break;
case 59:
#line 395 "parser.y"
	{
        set_write_flag(TRUE);
        insert_code(Write);
        }
break;
case 61:
#line 406 "parser.y"
	{set_cmp_type(EQUAL); insert_code(Icmp);}
break;
case 62:
#line 407 "parser.y"
	{set_cmp_type(NE); insert_code(Icmp);}
break;
case 63:
#line 408 "parser.y"
	{set_cmp_type(SLT); insert_code(Icmp);}
break;
case 64:
#line 409 "parser.y"
	{set_cmp_type(SLE); insert_code(Icmp);}
break;
case 65:
#line 410 "parser.y"
	{set_cmp_type(SGT); insert_code(Icmp);}
break;
case 66:
#line 411 "parser.y"
	{set_cmp_type(SGE); insert_code(Icmp);}
break;
case 70:
#line 418 "parser.y"
	{insert_code(Add);}
break;
case 71:
#line 419 "parser.y"
	{insert_code(Sub);}
break;
case 73:
#line 424 "parser.y"
	{insert_code(Mult);}
break;
case 74:
#line 425 "parser.y"
	{insert_code(Div);}
break;
case 76:
#line 430 "parser.y"
	{
        Factor x = {CONSTANT, "", yystack.l_mark[0].num};
        factor_push(x);
        }
break;
case 79:
#line 439 "parser.y"
	{
        Factor x = create_factor_by_name(yystack.l_mark[0].ident);
        factor_push(x);
        insert_code(Load);
        }
break;
case 80:
#line 447 "parser.y"
	{
                Factor x = create_proc_or_func_factor(yystack.l_mark[-3].ident, get_aritystack_top());
                /*create_factor_by_name()で帰ってくるのはlocal varなので加工してあげる*/
                /*関数名と返り値の名前が一緒なのでこれでオケ*/
                x.type = FUNC_NAME;
                factor_push(x);
                insert_code(Func);
        }
break;
case 81:
#line 459 "parser.y"
	{
        Factor x = factor_pop();
        arity_push(x);
        factor_push(x);
        }
break;
case 82:
#line 464 "parser.y"
	{
        Factor x = factor_pop();
        arity_push(x);
        factor_push(x);
        }
break;
case 83:
#line 472 "parser.y"
	{
        if (var_mode) {
                if (scope == LOCAL_VAR) var_num++;
                insert_symbol(scope, yystack.l_mark[0].ident, count++);
        }
        else if (arity_mode) {
                arity_num++;
                insert_symbol(scope, yystack.l_mark[0].ident, count++);
        }
        Factor x = create_factor_by_name(yystack.l_mark[0].ident);
        factor_push(x);
        }
break;
case 84:
#line 484 "parser.y"
	{
        if (var_mode) {
                if (scope == LOCAL_VAR) var_num++;
                insert_symbol(scope, yystack.l_mark[0].ident, count++);
        }
        else if (arity_mode) {
                arity_num++;
                insert_symbol(scope, yystack.l_mark[0].ident, count++);
        }
        Factor x = create_factor_by_name(yystack.l_mark[0].ident);
        factor_push(x);
        }
break;
#line 1115 "y.tab.c"
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
