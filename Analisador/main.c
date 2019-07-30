#include <stdio.h>
#include <stdlib.h>
#include "./libs/stack.h"

/****************************

ALLUPH - Analisador Lexico e Sintatico
Phyllipe Matheus Bezerra Alves
Lucas Agra de Omena
Universidade Federal de Alagoas
Ciencia da Computacao

*****************************/

typedef enum category {

    Cat1, Cat2

} Category;

#define DEBUG if(0)

int main(int argc, char const *argv[])
{
    Stack* stack = createStack();

    


    clearStack(stack);
    free(stack);

    return 0;
}