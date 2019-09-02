#ifndef AUXILIAR_H
#define AUXILIAR_H


#define _DEBUG if(False)
#define _LINEREADPRINT if (True)

#define NonTerminalQuant 43
#define TerminalsQuant 49

typedef enum boolean {

    False, True
} Boolean;

typedef enum non_term {

    S,          // 0
    DefFunList, // 1
    FunId,      // 2
    VarType,    // 3
    FunType,    // 4
    FunTypeAux, // 5
    OpClPar,    // 6
    Par,        // 7
    ParAux,     // 8
    SentList,   // 9
    SentListAux,// 10
    Sent,       // 11
    Else,       // 12
    Doing,      // 13
    Decl,       // 14
    Id,         // 15
    VecType,    // 16
    Atr,        // 17
    Print,      // 18
    Read,       // 19
    FunCall,    // 20
    Return,     // 21
    ReturnRec,  // 22
    Exp,        // 23
    ExpRec,     // 24
    BoolExp,    // 25
    BoolExpRec, // 26
    BoolTerm,   // 27
    BoolTermRec,// 28
    BoolFac,    // 29
    EqExp,      // 30
    EqExpAux,   // 31
    EqOpe,      // 32
    RelExp,     // 33 
    RelExpRec,  // 34
    RelOpe,     // 35
    ArExp,      // 36
    ArExpRec,   // 37
    ArTerm,     // 38
    ArTermRec,  // 39
    ArFac,      // 40
    ArOpe,      // 41
    MultOpe     // 42

} NonTerminal;

// DO NOT CHANGE DE ORDER
typedef enum category {

    catFunction,// 0
    catDo,      // 1
    catEnd,     // 2
    catFunId,   // 3
    catMain,    // 4
    catInt,     // 5
    catFloat,   // 6
    catString,  // 7
    catBool,    // 8
    catChar,    // 9
    catVoid,    // 10    
    catOpBrac,  // 11
    catClsBrac, // 12
    catOpPar,   // 13
    catClsPar,  // 14
    catComma,   // 15
    catId,      // 16
    catIf,      // 17
    catWhile,   // 18
    catFrom,    // 19
    catTo,      // 20
    catSemiCol, // 21
    catElse,    // 22
    catDoing,   // 23
    catOpeAtr,  // 24
    catPrint,   // 25
    catRead,    // 26
    catReturn,  // 27
    catOpeConc, // 28
    catOpeOr,   // 29
    catOpeAnd,  // 30
    catOpeNeg,  // 31
    catOpeEq,   // 32
    catOpeDif,  // 33
    catCteBool, // 34
    catOpeGt,   // 35
    catOpeGte,  // 36
    catOpeLt,   // 37
    catOpeLte,  // 38
    catCteInt,  // 39
    catCteFloat,// 40
    catCteStr,  // 41
    catCteChar, // 42
    catOpeSum,  // 43
    catOpeSub,  // 44
    catOpeMult, // 45
    catOpeDiv,  // 46
    catOpeMod,  // 47
    catEOF,     // 48
    _unrecognized // 49

} Category;

// DO NOT CHANGE DE ORDER
extern const char categoryToString[][14];
extern const char NonTerminalToString[][14];

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
