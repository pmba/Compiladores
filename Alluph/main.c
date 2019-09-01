#include <stdio.h>
#include <stdlib.h>

#include "./includes/auxiliar.h"
#include "./includes/list.h"
#include "./includes/stack.h"
#include "./includes/file.h"
#include "./includes/syntactic.h"
#include "./includes/lexical.h"
#include "./includes/grammar.h"


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
            printToken(current_token);
        } else {
            current_token = TokenList->token;
            printToken(current_token);
            TokenList = TokenList->next;
        }

    } else {
        current_token = TokenList->token;
        printToken(current_token);
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

    ListNode* TokenList = NULL;
    Stack* stack = createStack();
    GenericToken* current_Gtoken = NULL;

    // nao-terminal categoria S
    push(stack, createGenericToken(False, S));

    while(!isEmpty(stack)) {
        
        if(current_token == NULL) {
            TokenList = nextToken(TokenList);
        }
        current_Gtoken = pop(stack);
        
        if(current_Gtoken->isTerminal) {
            if(current_Gtoken->catNum == current_token->category) {
                current_token = NULL;
            }

            else {
                printf("Expected token: %s\n", categoryToString[current_Gtoken->catNum]);
                printf("Found: %s at line: %d \t col: %d\n", categoryToString[current_token->category], current_token->row, current_token->col);
                return 0;
            }
        }

        else {
           
            int rule = preditive_table[current_Gtoken->catNum][current_token->category];

            if(rule == -1 || rule == -2) {
                printf("Error: %d\n", rule);
                return 0;
            } 

            stack = stackProduction(stack, rule);

            printf("Rule: %d\n", rule);
        }
    }

    closeFile();

    return 0;
}