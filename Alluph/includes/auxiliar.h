#ifndef AUXILIAR_H
#define AUXILIAR_H


#define _DEBUG if(False)
#define _LINEREADPRINT if (True)

#define NonTerminalQuant 41
#define TerminalsQuant 49

typedef enum boolean {

    False, True
} Boolean;

typedef enum non_term {

    S, 
    DefFunList, FunId, VarType, FunType, OpClPar, Par,
    ParAux, SentList, SentListAux, Sent, Else, Doing, Decl,
    Id, VecType, Atr, Print, Read, FunCall, Return, Exp,
    ExpRec, BoolExp, BoolExpRec, BoolTerm, BoolTermRec, 
    BoolFac, EqExp, EqExpAux, EqOpe, RelExp, RelExpRec, 
    RelOpe, ArExp, ArExpRec, ArTerm, ArTermRec,ArFac, 
    ArOpe, MultOpe

} NonTerminal;

// DO NOT CHANGE DE ORDER
typedef enum category {

    catFunction, 
    catDo, 
    catEnd, 
    catMain, 
    catInt,
    catFloat, 
    catString, 
    catBool, 
    catChar, 
    catVoid, 
    catOpPar,
    catClsPar, 
    catComma, 
    catIf, 
    catWhile, 
    catFrom, 
    catTo, 
    catElse, 
    catDoing, 
    catSemiCol, 
    catOpBrac, 
    catClsBrac, 
    catPrint, 
    catRead,
    carReturn, 
    catOpeConc,
    catOpeOr,
    catOpeAnd, 
    catOpeNeg, 
    catOpeAtr, 
    catOpeEq, 
    catOpeDif, 
    catCteBool, 
    catOpeGt, 
    catOpeGte, 
    catOpeLt, 
    catOpeLte, 
    catOpeSum, 
    catOpeSub, 
    catOpeMult, 
    catOpeDiv, 
    catOpeMod, 
    catFunId, 
    catId, 
    catCteInt, 
    catCteFloat, 
    catCteStr, 
    catCteChar, 
    catEOF,
    _unrecognized

} Category;

// DO NOT CHANGE DE ORDER
extern const char categoryToString[][14];

typedef struct token {

    char* lexeme;
    Category category;
    int row, col;
    
} Token;

typedef struct list_node {
    Token* token;
    struct list_node* next;

} ListNode;

extern ListNode* TokenList;

Token* newToken(char* lex, Category cat, int row, int col);
Token* newStrChToken(char* lex, int row, int col);
void printToken(Token* token);
void printLine(char* line, int line_number);

#endif // AUXILIAR_H
