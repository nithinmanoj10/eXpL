#define ID 257
#define NUM 258
#define STRING 259
#define INITIALIZE 260
#define ALLOC 261
#define FREE 262
#define BEGIN_ 263
#define END 264
#define MAIN 265
#define READ 266
#define WRITE 267
#define PLUS 268
#define MINUS 269
#define MUL 270
#define DIV 271
#define MOD 272
#define AMPERSAND 273
#define EQUAL 274
#define BREAKPOINT 275
#define TYPE 276
#define ENDTYPE 277
#define IF 278
#define THEN 279
#define ELSE 280
#define ENDIF 281
#define WHILE 282
#define DO 283
#define ENDWHILE 284
#define BREAK 285
#define CONTINUE 286
#define AND 287
#define OR 288
#define NOT 289
#define DECL 290
#define ENDDECL 291
#define INT 292
#define STR 293
#define RETURN 294
#define EQ 295
#define NEQ 296
#define LT 297
#define LTE 298
#define GT 299
#define GTE 300
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
