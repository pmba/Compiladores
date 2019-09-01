#include <stdio.h>
#include <stdlib.h>

#include "./includes/auxiliar.h"
#include "./includes/list.h"
#include "./includes/stack.h"
#include "./includes/file.h"
#include "./includes/syntactic.h"
#include "./includes/lexical.h"


/****************************

ALLUPH - Analisador Lexico e Sintatico
Phyllipe Matheus Bezerra Alves
Lucas Agra de Omena
Universidade Federal de Alagoas
Ciencia da Computacao

*****************************/

Token* current_token = NULL;

ListNode* nextToken(ListNode* TokenList) {
   

    if (TokenList == NULL) {

        TokenList = analyseLine(TokenList);

        if (TokenList == NULL) {
            current_token = newToken("EOF", catEOF, current_line, _column+1);
        } else {
            current_token = TokenList->token;
            TokenList = TokenList->next;
        }

    } else {
        current_token = TokenList->token;
        TokenList = TokenList->next;
    }
    return TokenList;
}

int main(int argc, char const *argv[]) {

    if (argc <= 1) {

        printf("[Error] File path expected as first argument.\n");
        exit(EXIT_FAILURE);
    }

    Boolean file_opened = openFile(argv[1]);

    if (!file_opened) exit(EXIT_FAILURE); 
    if (!initializeLexicalAnalyzer()) exit(EXIT_FAILURE);

    Stack* stk = createStack();

    ListNode* TokenList = NULL;
    do {
        TokenList = nextToken(TokenList);
        printToken(current_token);

    } while(current_token->category != catEOF);

    closeFile();

    return 0;
}