#define ID 257
#define NUM 258
#define STRING 259
#define BEGIN_ 260
#define END 261
#define MAIN 262
#define READ 263
#define WRITE 264
#define PLUS 265
#define MINUS 266
#define MUL 267
#define DIV 268
#define MOD 269
#define AMPERSAND 270
#define EQUAL 271
#define BREAKPOINT 272
#define IF 273
#define THEN 274
#define ELSE 275
#define ENDIF 276
#define WHILE 277
#define DO 278
#define ENDWHILE 279
#define BREAK 280
#define CONTINUE 281
#define AND 282
#define OR 283
#define NOT 284
#define DECL 285
#define ENDDECL 286
#define INT 287
#define STR 288
#define TUPLE 289
#define RETURN 290
#define SEMICOLON 291
#define COMMA 292
#define DOT 293
#define EQ 294
#define NEQ 295
#define LT 296
#define LTE 297
#define GT 298
#define GTE 299
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	struct ASTNode* node;
	struct LSTNode* lstnode;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
