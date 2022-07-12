#define ID 257
#define NUM 258
#define STRING 259
#define INITIALIZE 260
#define ALLOC 261
#define FREE 262
#define NULL_ 263
#define NEW 264
#define BEGIN_ 265
#define END 266
#define MAIN 267
#define READ 268
#define WRITE 269
#define PLUS 270
#define MINUS 271
#define MUL 272
#define DIV 273
#define MOD 274
#define AMPERSAND 275
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
#define SELF 297
#define CLASS 298
#define ENDCLASS 299
#define EQ 300
#define NEQ 301
#define LT 302
#define LTE 303
#define GT 304
#define GTE 305
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
	struct ClassTable* CTNode;
	struct MemberFuncList* MFLNode;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
