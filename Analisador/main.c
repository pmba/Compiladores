#include <stdio.h>
#include <stdlib.h>
#include "./libs/stack.h"
#include "./libs/syntactic.h"
#include "./libs/lexic.h"

/****************************

ALLUPH - Analisador Lexico e Sintatico
Phyllipe Matheus Bezerra Alves
Lucas Agra de Omena
Universidade Federal de Alagoas
Ciencia da Computacao

*****************************/

#define DEBUG if(0)

int main(int argc, char const *argv[])
{
    Stack* stack = createStack();

    printf("%d\n", catFunction);


    clearStack(stack);
    free(stack);

    return 0;
}