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
#define PRINTF 270
#define PLUS 271
#define MINUS 272
#define MUL 273
#define DIV 274
#define MOD 275
#define AMPERSAND 276
#define BREAKPOINT 277
#define TYPE 278
#define ENDTYPE 279
#define TUPLE 280
#define IF 281
#define THEN 282
#define ELSE 283
#define ENDIF 284
#define WHILE 285
#define DO 286
#define ENDWHILE 287
#define BREAK 288
#define CONTINUE 289
#define AND 290
#define OR 291
#define NOT 292
#define FOR 293
#define DECL 294
#define ENDDECL 295
#define INT 296
#define STR 297
#define RETURN 298
#define SELF 299
#define EXTENDS 300
#define CLASS 301
#define ENDCLASS 302
#define EQ 303
#define NEQ 304
#define LT 305
#define LTE 306
#define GT 307
#define GTE 308
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
