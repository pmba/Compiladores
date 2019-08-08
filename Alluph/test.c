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

int main(int argc, char const *argv[]) {

    ListNode* list = NULL;

    printList(list);

    Token* tk1 = newToken("tk1", catBool, 0, 0);
    Token* tk2 = newToken("tk2", catChar, 0, 0);
    Token* tk3 = newToken("tk3", catClsBrac, 0, 0);
    Token* tk4 = newToken("tk4", catClsPar, 0, 0);

    list = pushList(list, tk1);
    list = pushList(list, tk2);
    list = pushList(list, tk3);

    printToken(nextToken(list));
    printToken(nextToken(list));
    printToken(nextToken(list));

    return 0;
}