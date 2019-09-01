#ifndef AUXILIAR_H
#define AUXILIAR_H


#define _DEBUG if(False)
#define _LINEREADPRINT if (True)

#define NonTerminalQuant 42
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
    OpClPar,    // 5
    Par,        // 6
    ParAux,     // 7
    SentList,   // 8
    SentListAux,// 9
    Sent,       // 10
    Else,       // 11
    Doing,      // 12
    Decl,       // 13
    Id,         // 14
    VecType,    // 15
    Atr,        // 16
    Print,      // 17
    Read,       // 18
    FunCall,    // 19
    Return,     // 20
    ReturnRec,  // 21
    Exp,        // 22
    ExpRec,     // 23
    BoolExp,    // 24
    BoolExpRec, // 25
    BoolTerm,   // 26
    BoolTermRec,// 27
    BoolFac,    // 28
    EqExp,      // 29
    EqExpAux,   // 30
    EqOpe,      // 31
    RelExp,     // 32 
    RelExpRec,  // 33
    RelOpe,     // 34
    ArExp,      // 35
    ArExpRec,   // 36
    ArTerm,     // 37
    ArTermRec,  // 38
    ArFac,      // 39
    ArOpe,      // 40
    MultOpe     // 41

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
    catOpPar,   // 11
    catClsPar,  // 12
    catComma,   // 13
    catId,      // 14
    catIf,      // 15
    catWhile,   // 16
    catFrom,    // 17
    catTo,      // 18
    catElse,    // 19
    catDoing,   // 20
    catSemiCol, // 21
    catOpBrac,  // 22
    catClsBrac, // 23
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
