/****************************

ALLUPH - Analisador Lexico e Sintatico
Phyllipe Matheus Bezerra Alves
Lucas Agra de Omena
Universidade Federal de Alagoas
Ciencia da Computacao

*****************************/

#define _DEBUG if(True)

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
const char categoryToString[][14] = {

    "catFunction", 
    "catDo", 
    "catEnd", 
    "catMain", 
    "catInt",
    "catFloat", 
    "catString", 
    "catBool", 
    "catChar", 
    "catVoid", 
    "catOpPar",
    "catClsPar", 
    "catComma", 
    "catIf", 
    "catWhile", 
    "catFrom", 
    "catTo", 
    "catElse", 
    "catDoing", 
    "catSemiCol", 
    "catOpBrac", 
    "catClsBrac", 
    "catPrint", 
    "catRead",
    "carReturn", 
    "catOpeConc",
    "catOpeOr",
    "catOpeAnd", 
    "catOpeNeg", 
    "catOpeAtr", 
    "catOpeEq", 
    "catOpeDif", 
    "catCteBool", 
    "catOpeGt", 
    "catOpeGte", 
    "catOpeLt", 
    "catOpeLte", 
    "catOpeSum", 
    "catOpeSub", 
    "catOpeMult", 
    "catOpeDiv", 
    "catOpeMod", 
    "catFunId", 
    "catId", 
    "catCteInt", 
    "catCteFloat", 
    "catCteStr", 
    "catCteChar", 
    "catEOF",
    "_unrecognized"

};

typedef struct token {

    char* lexeme;
    Category category;
    int row, col;

    struct token* next;
} Token;

Token* newToken(char* lex, Category cat, int row, int col) {

    Token* new_token = malloc(sizeof(Token*));

    new_token->lexeme = lex;
    new_token->category = cat;
    new_token->row = row;
    new_token->col = col;

    return new_token;
}