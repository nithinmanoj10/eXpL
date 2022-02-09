#define ID 257
#define NUM 258
#define STRING 259
#define INITIALIZE 260
#define ALLOC 261
#define FREE 262
#define NULL_ 263
#define BEGIN_ 264
#define END 265
#define MAIN 266
#define READ 267
#define WRITE 268
#define PLUS 269
#define MINUS 270
#define MUL 271
#define DIV 272
#define MOD 273
#define AMPERSAND 274
#define EQUAL 275
#define BREAKPOINT 276
#define TYPE 277
#define ENDTYPE 278
#define TUPLE 279
#define IF 280
#define THEN 281
#define ELSE 282
#define ENDIF 283
#define WHILE 284
#define DO 285
#define ENDWHILE 286
#define BREAK 287
#define CONTINUE 288
#define AND 289
#define OR 290
#define NOT 291
#define DECL 292
#define ENDDECL 293
#define INT 294
#define STR 295
#define RETURN 296
#define EQ 297
#define NEQ 298
#define LT 299
#define LTE 300
#define GT 301
#define GTE 302
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	struct ASTNode* node;
	struct LSTNode* lstnode;
	struct TypeTable* TTNode;
	struct FieldList* FLNode;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
