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

#define NonTerminalQuant 40
#define TerminalsQuant 1

GenericCategory preditive_table[NonTerminalQuant][TerminalsQuant] = {
    {  },
    {  },
    {  },
    {  },
    {  },
    {  },
    {  },
    {  },
    {  },
    {  },
    {  },
    {  },
    {  },
    {  },
    {  },
    {  },
    {  },
    {  },
    {  },
    {  },
    {  },
    {  },
    {  },
    {  },
    {  },
    {  },
    {  },
    {  },
    {  },
    {  },
    {  },
    {  },
    {  },
    {  },
    {  },
    {  },
    {  },
    {  },
    {  },
    {  }
};

typedef enum non_term {

    // start the non terminal count from the categories count end
    S, DefFunList, DefMainFun,
    VarType, FunType, OpClPar,
    Par, ParAux, SentList,
    SentListAux, Sent, Else,
    Doing, Decl, Id, VecType,
    Art, Print, Read, FunCall,
    Return, Exp, ExpRec, 
    BoolExp, BoolExpRed, 
    BoolTerm, BoolTermRec, 
    BoolFac, EqExp, EqOpe,
    RelExp, RelExpRec, RelOpe,
    ArExp, ArExpRec, ArTerm,
    ArTermRec, ArFac, ArOpe,
    MultOpe

} NonTerminal;

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