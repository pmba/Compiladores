#include <stdio.h>
#include <stdlib.h>

#include "../includes/auxiliar.h"
#include "../includes/stack.h"
#include "../includes/grammar.h"

/****************************

ALLUPH - Analisador Lexico e Sintatico
Phyllipe Matheus Bezerra Alves
Lucas Agra de Omena
Universidade Federal de Alagoas
Ciencia da Computacao

*****************************/

void stackProduction(Stack* stack, int production) {

    switch (production)
    {
    case 1:
        push( // DefFunList
            stack, createGenericToken(False, DefFunList);
        );

        break;
    
    case 2:
        
        push( // DefFunList
            stack, createGenericToken(False, DefFunList);
        );
        push( // 'end'
            stack, createGenericToken(True, catEnd);
        );
        push( // SentList
            stack, createGenericToken(False, SentList);
        );
        push( // 'do'
            stack, createGenericToken(True, catDo);
        );
        push( // OpClPar
            stack, createGenericToken(False, OpClPar);
        );
        push( // FunId
            stack, createGenericToken(False, FunId);
        );
        push( // FunType
            stack, createGenericToken(False, FunType);
        );
        push( // 'function'
            stack, createGenericToken(True, catFunction);
        );

        break;
    
    case 3:
        break;

    case 4:
        push( // 'funId'
            stack, createGenericToken(True, catFunId);
        );

        break;

    case 5:
        push( // 'main'
            stack, createGenericToken(True, catMain);
        );

        break;

    case 6:
        push( // 'int'
            stack, createGenericToken(True, catInt);
        );

        break;

    case 7:
        push( // 'Float'
            stack, createGenericToken(True, catFloat);
        );

        break;

    case 8:
        push( // 'String'
            stack, createGenericToken(True, catString);
        );

        break;

    case 9:
        push( // 'Bool'
            stack, createGenericToken(True, catBool);
        );

        break;

    case 10:
        push( // 'Char'
            stack, createGenericToken(True, catChar);
        );

        break;

    case 11:
        push( // VarType
            stack, createGenericToken(False, VarType);
        );

        break;

    case 12:
        push( // 'void'
            stack, createGenericToken(True, catVoid);
        );

        break;

    case 13:
        push( // ')'
            stack, createGenericToken(True, catClsPar);
        );
        push( // 'Par
            stack, createGenericToken(False, Par);
        );
        push( // '('
            stack, createGenericToken(True, catOpPar);
        );

        break;    

    case 14:
        push( // ParAux
            stack, createGenericToken(False, ParAux);
        );

        break;

    case 15:
        push( // ParAux
            stack, createGenericToken(False, ParAux);
        );
        push( // ','
            stack, createGenericToken(True, catComma);
        );

        break;

    case 16:
        break;

    case 17:
        push( // Par
            stack, createGenericToken(False, Par);
        );
        push( // 'id'
            stack, createGenericToken(True, catId);
        );
        push( // VarType
            stack, createGenericToken(False, VarType);
        );

        break;
    
    case 18:
        push( // Par
            stack, createGenericToken(False, Par);
        );
        push( // Exp
            stack, createGenericToken(False, Exp);
        );

        break;

    case 19:
        push( // SentListAux
            stack, createGenericToken(False, SentListAux);
        );
        push( // Sent
            stack, createGenericToken(False, Sent);
        );

        break;

    case 20:
        push( // SentList
            stack, createGenericToken(False, SentList);
        );

        break;

    case 21:
        break;

    case 22:
        push( // Else
            stack, createGenericToken(False, Else);
        );
        push( // 'end'
            stack, createGenericToken(True, catEnd);
        );
        push( // SentList
            stack, createGenericToken(False, SentList);
        );
        push( // 'do'
            stack, createGenericToken(True, catDo);
        );
        push( // BoolExp
            stack, createGenericToken(False, BoolExp);
        );
        push( // 'if'
            stack, createGenericToken(True, catIf);
        );

        break;

    case 23:
        push( // 'end'
            stack, createGenericToken(True, catEnd);
        );
        push( // SentList
            stack, createGenericToken(False, SentList);
        );
        push( // 'do'
            stack, createGenericToken(True, catDo);
        );
        push( // BoolExp
            stack, createGenericToken(False, BoolExp);
        );
        push( // 'while'
            stack, createGenericToken(True, catWhile);
        );

        break;

    case 24:
        // TODO:

        break;

    default:
        break;
    }
}


