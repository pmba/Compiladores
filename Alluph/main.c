#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <ctype.h>
#include "./libs/auxiliar.h"
#include "./libs/list.h"
#include "./libs/stack.h"
#include "./libs/file.h"
#include "./libs/syntactic.h"
#include "./libs/lexical.h"


/****************************

ALLUPH - Analisador Lexico e Sintatico
Phyllipe Matheus Bezerra Alves
Lucas Agra de Omena
Universidade Federal de Alagoas
Ciencia da Computacao

*****************************/
Token* nextToken() {

    if (TokenList == NULL) {

        if(!analyseLine()) {
            return newToken("EOF", catEOF, current_line, _column+1);
        }
    }

    if (TokenList->next == NULL){
        Token* aux = TokenList->token;
        TokenList = NULL;

        return aux;
    } 
     
    else {
        Token* aux = TokenList->token;
        TokenList = TokenList->next;

        return aux;
    }
}

int main(int argc, char const *argv[]) {

    if (argc <= 1) {

        printf("[Error] File path expected as first argument.\n");
        exit(EXIT_FAILURE);
    }

    Boolean file_opened = openFile(argv[1]);

    if (!file_opened) exit(EXIT_FAILURE); 
    if (!initializeLexicalAnalyzer()) exit(EXIT_FAILURE);

    printf("\n          [Row ,  Col] (Cat , %20s) {%s}\n\n", "Category", "Lexeme");

    Token* current_token = nextToken();
    printToken(current_token);

    while(current_token->category != catEOF) {
        current_token = nextToken();
        printToken(current_token);
    }

    // printList(TokenList);

    closeFile();

    return 0;
}