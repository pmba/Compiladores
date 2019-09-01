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

Stack* stackProduction(Stack* stack, int production) {

    switch (production)
    {
    case 1:
        push( // DefFunList
            stack, createGenericToken(False, DefFunList)
        );

        break;
    
    case 2:
        
        push( // DefFunList
            stack, createGenericToken(False, DefFunList)
        );
        push( // 'end'
            stack, createGenericToken(True, catEnd)
        );
        push( // SentList
            stack, createGenericToken(False, SentList)
        );
        push( // 'do'
            stack, createGenericToken(True, catDo)
        );
        push( // OpClPar
            stack, createGenericToken(False, OpClPar)
        );
        push( // FunId
            stack, createGenericToken(False, FunId)
        );
        push( // FunType
            stack, createGenericToken(False, FunType)
        );
        push( // 'function'
            stack, createGenericToken(True, catFunction)
        );

        break;
    
    case 3:
        break;

    case 4:
        push( // 'funId'
            stack, createGenericToken(True, catFunId)
        );

        break;

    case 5:
        push( // 'main'
            stack, createGenericToken(True, catMain)
        );

        break;

    case 6:
        push( // 'int'
            stack, createGenericToken(True, catInt)
        );

        break;

    case 7:
        push( // 'Float'
            stack, createGenericToken(True, catFloat)
        );

        break;

    case 8:
        push( // 'String'
            stack, createGenericToken(True, catString)
        );

        break;

    case 9:
        push( // 'Bool'
            stack, createGenericToken(True, catBool)
        );

        break;

    case 10:
        push( // 'Char'
            stack, createGenericToken(True, catChar)
        );

        break;

    case 11:
        push( // VarType
            stack, createGenericToken(False, VarType)
        );

        break;

    case 12:
        push( // 'void'
            stack, createGenericToken(True, catVoid)
        );

        break;

    case 13:
        push( // ')'
            stack, createGenericToken(True, catClsPar)
        );
        push( // 'Par
            stack, createGenericToken(False, Par)
        );
        push( // '('
            stack, createGenericToken(True, catOpPar)
        );

        break;    

    case 14:
        push( // ParAux
            stack, createGenericToken(False, ParAux)
        );

        break;

    case 15:
        push( // ParAux
            stack, createGenericToken(False, ParAux)
        );
        push( // ','
            stack, createGenericToken(True, catComma)
        );

        break;

    case 16:
        break;

    case 17:
        push( // Par
            stack, createGenericToken(False, Par)
        );
        push( // 'id'
            stack, createGenericToken(True, catId)
        );
        push( // VarType
            stack, createGenericToken(False, VarType)
        );

        break;
    
    case 18:
        push( // Par
            stack, createGenericToken(False, Par)
        );
        push( // Exp
            stack, createGenericToken(False, Exp)
        );

        break;

    case 19:
        push( // SentListAux
            stack, createGenericToken(False, SentListAux)
        );
        push( // Sent
            stack, createGenericToken(False, Sent)
        );

        break;

    case 20:
        push( // SentList
            stack, createGenericToken(False, SentList)
        );

        break;

    case 21:
        break;

    case 22:
        push( // Else
            stack, createGenericToken(False, Else)
        );
        push( // 'end'
            stack, createGenericToken(True, catEnd)
        );
        push( // SentList
            stack, createGenericToken(False, SentList)
        );
        push( // 'do'
            stack, createGenericToken(True, catDo)
        );
        push( // BoolExp
            stack, createGenericToken(False, BoolExp)
        );
        push( // 'if'
            stack, createGenericToken(True, catIf)
        );

        break;

    case 23:
        push( // 'end'
            stack, createGenericToken(True, catEnd)
        );
        push( // SentList
            stack, createGenericToken(False, SentList)
        );
        push( // 'do'
            stack, createGenericToken(True, catDo)
        );
        push( // BoolExp
            stack, createGenericToken(False, BoolExp)
        );
        push( // 'while'
            stack, createGenericToken(True, catWhile)
        );

        break;

    case 24:
        push( // 'end'
            stack, createGenericToken(True, catEnd)
        );
        push( // SentList
            stack, createGenericToken(False, SentList)
        );
        push( // 'do'
            stack, createGenericToken(True, catDo)
        );
        push( // Doing
            stack, createGenericToken(False, Doing)
        );        
        push( // ArExp
            stack, createGenericToken(False, ArExp)
        );
        push( // 'to'
            stack, createGenericToken(True, catTo)
        );
        push( // BoolExp
            stack, createGenericToken(False, BoolExp)
        );
        push( // 'from'
            stack, createGenericToken(True, catFrom)
        );

        break;

    case 25:
        push( // Decl
            stack, createGenericToken(False, Decl)
        );

        break;

    case 26:
        push( // Atr
            stack, createGenericToken(False, Atr)
        );

        break;

    case 27:
        push( // Print
            stack, createGenericToken(False, Print)
        );

        break;

    case 28:
        push( // Read
            stack, createGenericToken(False, Read)
        );

        break;

    case 29:
        push( // FunCall
            stack, createGenericToken(False, FunCall)
        );

        break;

    case 30:
        push( // Return
            stack, createGenericToken(False, Return)
        );

        break;

    case 31:
        push( // 'end'
            stack, createGenericToken(True, catEnd)
        );
        push( // SentList
            stack, createGenericToken(False, SentList)
        );
        push( // 'do'
            stack, createGenericToken(True, catDo)
        );
        push( // 'else'
            stack, createGenericToken(True, catElse)
        );

        break;

    case 32:
        break;

    case 33:
        push( // Atr
            stack, createGenericToken(False, Atr)
        );
        push( // 'doing'
            stack, createGenericToken(True, catDoing)
        );

        break;

    case 34:
        break;

    case 35:
        push( // ';'
            stack, createGenericToken(True, catSemiCol)
        );
        push( // Id
            stack, createGenericToken(False, Id)
        );
        push( // VarType
            stack, createGenericToken(False, VarType)
        );
    
        break;

    case 36:
        push( // VecType
            stack, createGenericToken(False, VecType)
        );
        push( // 'id'
            stack, createGenericToken(True, catId)
        );
    
        break;

    case 37:
        push( // ']'
            stack, createGenericToken(True, catClsPar)
        );
        push( // Exp
            stack, createGenericToken(False, Exp)
        );
        push( // '['
            stack, createGenericToken(True, catOpPar)
        );    

        break;

    case 38:
        break;

    case 39:
        push( // ';'
            stack, createGenericToken(True, catSemiCol)
        );   
        push( // Exp
            stack, createGenericToken(False, Exp)
        );   
        push( // '='
            stack, createGenericToken(True, catOpeAtr)
        );   
        push( // Id
            stack, createGenericToken(False, Id)
        );   

        break;

    case 40:
        push( // ';'
            stack, createGenericToken(True, catSemiCol)
        );   
        push( // ')'
            stack, createGenericToken(True, catClsPar)
        );         
        push( // Exp
            stack, createGenericToken(False, Exp)
        );   
        push( // '('
            stack, createGenericToken(True, catOpPar)
        );    
        push( // 'print'
            stack, createGenericToken(True, catPrint)
        );    
        break;

    case 41:
        push( // ';'
            stack, createGenericToken(True, catSemiCol)
        );   
        push( // ')'
            stack, createGenericToken(True, catClsPar)
        );         
        push( // Id
            stack, createGenericToken(False, Id)
        );   
        push( // '('
            stack, createGenericToken(True, catOpPar)
        );    
        push( // 'read'
            stack, createGenericToken(True, catRead)
        );  
    
        break;

    case 42:
        push( // ';'
            stack, createGenericToken(True, catSemiCol)
        );
        push( // OpClPar
            stack, createGenericToken(False, OpClPar)
        );
        push( // 'funId'
            stack, createGenericToken(True, catFunId)
        );
        break;

    case 43:
        push( // ';'
            stack, createGenericToken(True, catSemiCol)
        );
        push( // Exp
            stack, createGenericToken(False, Exp)
        );
        push( // 'return'
            stack, createGenericToken(True, catReturn)
        );
        break;

    case 44:
        push( // ExpRec
            stack, createGenericToken(False, ExpRec)
        );
        push( // BoolExp
            stack, createGenericToken(False, BoolExp)
        );
        break;

    case 45:
        break;

    default:
        break;
    }
}


