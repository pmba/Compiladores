#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../includes/auxiliar.h"

/****************************

ALLUPH - Analisador Lexico e Sintatico
Phyllipe Matheus Bezerra Alves
Lucas Agra de Omena
Universidade Federal de Alagoas
Ciencia da Computacao

*****************************/
const char NonTerminalToString[][14] = {

    "S", 
    "DefFunList", 
    "FunId", 
    "VarType", 
    "FunType", 
    "FunTypeAux", 
    "OpClPar",
    "Par", 
    "ParAux", 
    "SentList", 
    "SentListAux", 
    "Sent", 
    "Else",
    "Doing", 
    "Decl", 
    "Id", 
    "VecType", 
    "Atr", 
    "Print", 
    "Read", 
    "FunCall", 
    "Return", 
    "ReturnRec", 
    "Exp", 
    "ExpRec", 
    "BoolExp", 
    "BoolExpRec", 
    "BoolTerm", 
    "BoolTermRec",
    "BoolFac", 
    "EqExp",
    "EqExpAux",
    "EqOpe", 
    "RelExp", 
    "RelExpRec", 
    "RelOpe", 
    "ArExp", 
    "ArExpRec", 
    "ArTerm", 
    "ArTermRec", 
    "ArFac", 
    "ArOpe", 
    "MultOpe"
};
const char categoryToString[][14] = {

    "catFunction", 
    "catDo", 
    "catEnd", 
    "catFunId", 
    "catMain", 
    "catInt",
    "catFloat", 
    "catString", 
    "catBool", 
    "catChar", 
    "catVoid", 
    "catOpBrac", 
    "catClsBrac", 
    "catOpPar",
    "catClsPar", 
    "catComma", 
    "catId", 
    "catIf", 
    "catWhile", 
    "catFrom", 
    "catTo", 
    "catElse", 
    "catDoing", 
    "catSemiCol", 
    "catOpeAtr", 
    "catPrint", 
    "catRead",
    "catReturn", 
    "catOpeConc",
    "catOpeOr",
    "catOpeAnd", 
    "catOpeNeg", 
    "catOpeEq", 
    "catOpeDif", 
    "catCteBool", 
    "catOpeGt", 
    "catOpeGte", 
    "catOpeLt", 
    "catOpeLte", 
    "catCteInt", 
    "catCteFloat", 
    "catCteStr", 
    "catCteChar",
    "catOpeSum", 
    "catOpeSub", 
    "catOpeMult", 
    "catOpeDiv", 
    "catOpeMod",  
    "catEOF",
    "_unrecognized"

};

Token* newToken(char* lex, Category cat, int row, int col) {

    Token* new_token = (Token*) malloc(sizeof(Token));

    new_token->lexeme = lex;
    new_token->category = cat;
    new_token->row = row;
    new_token->col = col;
    
    return new_token;
}

Token* newStrChToken(char* lex, int row, int col) {

    Category token_cat;
    if (lex[0] == '\'' || lex[0] == '"') {
            
        char* aux = (char*) malloc(strlen(lex));
        for(int j = 0; j < strlen(lex); j++) {
            aux[j] = lex[j];
        }
        aux[strlen(lex)] = '\0';
        
        if (lex[0] == '\'' ) return newToken(aux, catCteChar, row, col);
        if (lex[0] == '"') return newToken(aux, catCteStr, row, col);
    }

    printf("Erro newStrChToken");
    return NULL;
}

void printToken(Token* token) {
    printf("          [%04d, %04d] (%04d, %20s) {%s}\n", token->row, token->col, token->category, categoryToString[token->category], token->lexeme);
}

void printLine(char* line, int line_number) {
    printf("%04d  \"%s\"\n", line_number, line);
}