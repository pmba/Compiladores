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
#define RegularExpressionsQuant 60

typedef enum boolean {

    False, True
} Boolean;

typedef enum non_term {

    S = 0, 
    DefFunList, FunId, VarType, FunType, OpClPar, Par,
    ParAux, SentList, SentListAux, Sent, Else, Doing, Decl,
    Id, VecType, Atr, Print, Read, FunCall, Return, Exp,
    ExpRec, BoolExp, BoolExpRec, BoolTerm, BoolTermRec, 
    BoolFac, EqExp, EqExpAux, EqOpe, RelExp, RelExpRec, 
    RelOpe, ArExp, ArExpRec, ArTerm, ArTermRec,ArFac, 
    ArOpe, MultOpe

} NonTerminal;

typedef enum category {

    catFunction = NonTerminalQuant, 
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
    catEOF

} Category;