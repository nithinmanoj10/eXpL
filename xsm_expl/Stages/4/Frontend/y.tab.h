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
#define AMPERSAND 269
#define EQUAL 270
#define BREAKPOINT 271
#define IF 272
#define THEN 273
#define ELSE 274
#define ENDIF 275
#define WHILE 276
#define DO 277
#define ENDWHILE 278
#define BREAK 279
#define CONTINUE 280
#define DECL 281
#define ENDDECL 282
#define INT 283
#define STR 284
#define SEMICOLON 285
#define COMMA 286
#define EQ 287
#define NEQ 288
#define LT 289
#define LTE 290
#define GT 291
#define GTE 292
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
