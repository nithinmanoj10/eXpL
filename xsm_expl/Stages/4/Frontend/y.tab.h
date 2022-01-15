#define ID 257
#define NUM 258
#define STRING 259
#define BEGIN_ 260
#define END 261
#define READ 262
#define WRITE 263
#define PLUS 264
#define MINUS 265
#define MUL 266
#define DIV 267
#define MOD 268
#define EQUAL 269
#define BREAKPOINT 270
#define IF 271
#define THEN 272
#define ELSE 273
#define ENDIF 274
#define WHILE 275
#define DO 276
#define ENDWHILE 277
#define BREAK 278
#define CONTINUE 279
#define DECL 280
#define ENDDECL 281
#define INT 282
#define STR 283
#define SEMICOLON 284
#define COMMA 285
#define EQ 286
#define NEQ 287
#define LT 288
#define LTE 289
#define GT 290
#define GTE 291
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	struct ASTNode* node;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
