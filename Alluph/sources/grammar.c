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
        push( // FunTypeAux
            stack, createGenericToken(False, FunTypeAux)
        );        
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
        push( // ']'
            stack, createGenericToken(True, catClsBrac)
        );

        push( // '['
            stack, createGenericToken(True, catOpBrac)
        );

        break;

    case 14:
        break;

    case 15:
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

    case 16:
        push( // ParAux
            stack, createGenericToken(False, ParAux)
        );

        break;

    case 17:
        push( // ParAux
            stack, createGenericToken(False, ParAux)
        );
        push( // ','
            stack, createGenericToken(True, catComma)
        );

        break;

    case 18:
        break;

    case 19:
        push( // Par
            stack, createGenericToken(False, Par)
        );
        push( // FunTypeAux
            stack, createGenericToken(False, FunTypeAux)
        );
        push( // 'id'
            stack, createGenericToken(True, catId)
        );
        push( // VarType
            stack, createGenericToken(False, VarType)
        );

        break;
    
    case 20:
        push( // Par
            stack, createGenericToken(False, Par)
        );
        push( // Exp
            stack, createGenericToken(False, Exp)
        );

        break;

    case 21:
        push( // SentListAux
            stack, createGenericToken(False, SentListAux)
        );
        push( // Sent
            stack, createGenericToken(False, Sent)
        );

        break;

    case 22:
        push( // SentList
            stack, createGenericToken(False, SentList)
        );

        break;

    case 23:
        break;

    case 24:
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

    case 25:
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

    case 26:
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
        push( // Atr
            stack, createGenericToken(False, Atr)
        );
        push( // 'from'
            stack, createGenericToken(True, catFrom)
        );

        break;

    case 27:
        push( // ';'
            stack, createGenericToken(True, catSemiCol)
        );
        push( // Decl
            stack, createGenericToken(False, Decl)
        );

        break;

    case 28:
        push( // ';'
            stack, createGenericToken(True, catSemiCol)
        );
        push( // Atr
            stack, createGenericToken(False, Atr)
        );

        break;

    case 29:
        push( // ';'
            stack, createGenericToken(True, catSemiCol)
        );
        push( // Print
            stack, createGenericToken(False, Print)
        );

        break;

    case 30:
        push( // ';'
            stack, createGenericToken(True, catSemiCol)
        );
        push( // Read
            stack, createGenericToken(False, Read)
        );

        break;

    case 31:
        push( // ';'
            stack, createGenericToken(True, catSemiCol)
        );
        push( // FunCall
            stack, createGenericToken(False, FunCall)
        );

        break;

    case 32:
        push( // ';'
            stack, createGenericToken(True, catSemiCol)
        );
        push( // Return
            stack, createGenericToken(False, Return)
        );

        break;

    case 33:
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

    case 34:
        break;

    case 35:
        push( // Atr
            stack, createGenericToken(False, Atr)
        );
        push( // 'doing'
            stack, createGenericToken(True, catDoing)
        );

        break;

    case 36:
        break;

    case 37:
        push( // Id
            stack, createGenericToken(False, Id)
        );
        push( // VarType
            stack, createGenericToken(False, VarType)
        );
    
        break;

    case 38:
        push( // VecType
            stack, createGenericToken(False, VecType)
        );
        push( // 'id'
            stack, createGenericToken(True, catId)
        );
    
        break;

    case 39:
        push( // ']'
            stack, createGenericToken(True, catClsBrac)
        );
        push( // Exp
            stack, createGenericToken(False, Exp)
        );
        push( // '['
            stack, createGenericToken(True, catOpBrac)
        );    

        break;

    case 40:
        break;

    case 41:
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

    case 42:
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

    case 43:
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

    case 44:
        push( // OpClPar
            stack, createGenericToken(False, OpClPar)
        );
        push( // 'funId'
            stack, createGenericToken(True, catFunId)
        );
        break;

    case 45:

        push( // ReturnRec
            stack, createGenericToken(False, ReturnRec)
        );
        push( // 'return'
            stack, createGenericToken(True, catReturn)
        );
        break;

    case 46:
        push( // Exp
            stack, createGenericToken(False, Exp)
        );
        break;

    case 47:
        break;

    case 48:
        push( // ExpRec
            stack, createGenericToken(False, ExpRec)
        );
        push( // BoolExp
            stack, createGenericToken(False, BoolExp)
        );

        break;

    case 49:
        push( // ExpRec
            stack, createGenericToken(False, ExpRec)
        );
        push( // BoolExp
            stack, createGenericToken(False, BoolExp)
        );
        push( // '++'
            stack, createGenericToken(True, catOpeConc)
        );

        break;

    case 50:
        break;

    case 51:
        push( // BoolExpRec
            stack, createGenericToken(False, BoolExpRec)
        );
        push( // BoolTerm
            stack, createGenericToken(False, BoolTerm)
        );

        break;

    case 52:
        push( // BoolExpRec
            stack, createGenericToken(False, BoolExpRec)
        );
        push( // BoolTerm
            stack, createGenericToken(False, BoolTerm)
        );
        push( // 'or'
            stack, createGenericToken(True, catOpeOr)
        );

        break;

    case 53:
        break;

    case 54:
        push( // BoolTermRec
            stack, createGenericToken(False, BoolTermRec)
        );
        push( // BoolFac
            stack, createGenericToken(False, BoolFac)
        );

        break;

    case 55:
        push( // BoolTermRec
            stack, createGenericToken(False, BoolTermRec)
        );
        push( // BoolFac
            stack, createGenericToken(False, BoolFac)
        );
        push( // 'and'
            stack, createGenericToken(True, catOpeAnd)
        );

        break;

    case 56:
        break;

    case 57:
        push( // EqExp
            stack, createGenericToken(False, EqExp)
        );
        push( // '!'
            stack, createGenericToken(True, catOpeNeg)
        );
        
        break;

    case 58:
        push( // EqExp
            stack, createGenericToken(False, EqExp)
        );

        break;

    case 59:
        push( // EqExpAux
            stack, createGenericToken(False, EqExpAux)
        );
        push( // RelExp
            stack, createGenericToken(False, RelExp)
        );

        break;

    case 60:
        push( // RelExp
            stack, createGenericToken(False, RelExp)
        );
        push( // EqOpe
            stack, createGenericToken(False, EqOpe)
        );

        break;

    case 61:
        break;

    case 62:
        push( // '=='
            stack, createGenericToken(True, catOpeEq)
        );

        break;

    case 63:
        push( // '!='
            stack, createGenericToken(True, catOpeDif)
        );

        break;

    case 64:
        push( // RelExpRec
            stack, createGenericToken(False, RelExpRec)
        );
        push( // 'cteBool'
            stack, createGenericToken(True, catCteBool)
        );

        break;

    case 65:
        push( // RelExpRec
            stack, createGenericToken(False, RelExpRec)
        );
        push( // ArExp
            stack, createGenericToken(False, ArExp)
        );
    
        break;

    case 66:
        push( // RelExpRec
            stack, createGenericToken(False, RelExpRec)
        );
        push( // RelExp
            stack, createGenericToken(False, RelExp)
        );
        push( // RelOpe
            stack, createGenericToken(False, RelOpe)
        );
    
        break;

    case 67:
        break;

    case 68:
        push( // '>'
            stack, createGenericToken(True, catOpeGt)
        );

        break;

    case 69:
        push( // '>='
            stack, createGenericToken(True, catOpeGte)
        );

        break;

    case 70:
        push( // '<'
            stack, createGenericToken(True, catOpeLt)
        );

        break;

    case 71:
        push( // '<='
            stack, createGenericToken(True, catOpeLte)
        );

        break;

    case 72:
        push( // ArExpRec
            stack, createGenericToken(False, ArExpRec)
        );
        push( // ArTerm
            stack, createGenericToken(False, ArTerm)
        );

        break;

    case 73:
        push( // ArExpRec
            stack, createGenericToken(False, ArExpRec)
        );
        push( // ArTerm
            stack, createGenericToken(False, ArTerm)
        );
        push( // ArOpe
            stack, createGenericToken(False, ArOpe)
        );

        break;

    case 74:
        break;

    case 75:
        push( // ArTermRec
            stack, createGenericToken(False, ArTermRec)
        );
        push( // ArFac
            stack, createGenericToken(False, ArFac)
        );

        break;

    case 76:
        push( // ArTermRec
            stack, createGenericToken(False, ArTermRec)
        );
        push( // ArFac
            stack, createGenericToken(False, ArFac)
        );
        push( // MultOpe
            stack, createGenericToken(False, MultOpe)
        );

        break;

    case 77:
        break;

    case 78:
        push( // ')'
            stack, createGenericToken(True, catClsPar)
        );
        push( // ArExp
            stack, createGenericToken(False, ArExp)
        );
        push( // '('
            stack, createGenericToken(True, catOpPar)
        );

        break;

    case 79:
        push( // Id
            stack, createGenericToken(False, Id)
        );

        break;

    case 80:
        push( // FunCall
            stack, createGenericToken(False, FunCall)
        );

        break;

    case 81:
        push( // 'CteInt'
            stack, createGenericToken(True, catCteInt)
        );

        break;

    case 82:
        push( // 'CteFloat'
            stack, createGenericToken(True, catCteFloat)
        );

        break;

    case 83:
        push( // 'CteString'
            stack, createGenericToken(True, catCteStr)
        );

        break;

    case 84:
        push( // 'CteChar'
            stack, createGenericToken(True, catCteChar)
        );

        break;

    case 85:
        push( // '+'
            stack, createGenericToken(True, catOpeSum)
        );

        break;

    case 86:
        push( // '-'
            stack, createGenericToken(True, catOpeSub)
        );

        break;

    case 87:
        push( // '*'
            stack, createGenericToken(True, catOpeMult)
        );

        break;

    case 88:
        push( // '/'
            stack, createGenericToken(True, catOpeDiv)
        );

        break;

    case 89:
        push( // '%'
            stack, createGenericToken(True, catOpeMod)
        );

        break;

    default:
        break;
    }


    return stack;
}


