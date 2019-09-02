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

        printf("          %11s -> ", NonTerminalToString[S]);
        printf("%s", NonTerminalToString[DefFunList]);

        push( // DefFunList
            stack, createGenericToken(False, DefFunList)
        );

        break;
    
    case 2:
        printf("          %11s -> ", NonTerminalToString[DefFunList]);
        printf("%s", terminalToString[catFunction]);
        printf("%s", NonTerminalToString[FunType]);
        printf("%s", NonTerminalToString[FunId]);
        printf("%s", NonTerminalToString[OpClPar]);
        printf("%s", terminalToString[catDo]);
        printf("%s", NonTerminalToString[SentList]);
        printf("%s", terminalToString[catEnd]);
        printf("%s", NonTerminalToString[DefFunList]);

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
        printf("          %11s -> Epsilon", NonTerminalToString[DefFunList]);
        break;

    case 4:
        printf("          %11s -> ", NonTerminalToString[FunId]);     
        printf("%s", terminalToString[catFunId]);

        push( // 'funId'
            stack, createGenericToken(True, catFunId)
        );

        break;

    case 5:
        printf("          %11s -> ", NonTerminalToString[FunId]);    
        printf("%s", terminalToString[catMain]);

        push( // 'main'
            stack, createGenericToken(True, catMain)
        );

        break;

    case 6:
        printf("          %11s -> ", NonTerminalToString[VarType]);  
        printf("%s", terminalToString[catInt]);

        push( // 'int'
            stack, createGenericToken(True, catInt)
        );

        break;

    case 7:
        printf("          %11s -> ", NonTerminalToString[VarType]);  
        printf("%s", terminalToString[catFloat]);

        push( // 'Float'
            stack, createGenericToken(True, catFloat)
        );

        break;

    case 8:
        printf("          %11s -> ", NonTerminalToString[VarType]); 
        printf("%s", terminalToString[catString]);

        push( // 'String'
            stack, createGenericToken(True, catString)
        );

        break;

    case 9:
        printf("          %11s -> ", NonTerminalToString[VarType]); 
        printf("%s", terminalToString[catBool]);

        push( // 'Bool'
            stack, createGenericToken(True, catBool)
        );

        break;

    case 10:
        printf("          %11s -> ", NonTerminalToString[VarType]);  
        printf("%s", terminalToString[catChar]);

        push( // 'Char'
            stack, createGenericToken(True, catChar)
        );

        break;

    case 11:
        printf("          %11s -> ", NonTerminalToString[FunType]);  
        printf("%s", NonTerminalToString[VarType]);
        printf("%s", NonTerminalToString[FunTypeAux]);

        push( // FunTypeAux
            stack, createGenericToken(False, FunTypeAux)
        );        
        push( // VarType
            stack, createGenericToken(False, VarType)
        );

        break;

    case 12:
        printf("          %11s -> ", NonTerminalToString[FunType]);  
        printf("%s", terminalToString[catVoid]);

        push( // 'void'
            stack, createGenericToken(True, catVoid)
        );

        break;

    case 13:
        printf("          %11s -> ", NonTerminalToString[FunTypeAux]);  
        printf("%s", terminalToString[catOpBrac]);
        printf("%s", terminalToString[catClsBrac]);

        push( // ']'
            stack, createGenericToken(True, catClsBrac)
        );

        push( // '['
            stack, createGenericToken(True, catOpBrac)
        );

        break;

    case 14:
        printf("          %11s -> Epsilon", NonTerminalToString[FunTypeAux]);  
        break;

    case 15:
        printf("          %11s -> ", NonTerminalToString[OpClPar]);
        printf("%s", terminalToString[catOpPar]);
        printf("%s", NonTerminalToString[Par]);
        printf("%s", terminalToString[catClsPar]);
          
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
        printf("          %11s -> ", NonTerminalToString[Par]); 
        printf("%s", NonTerminalToString[ParAux]); 

        push( // ParAux
            stack, createGenericToken(False, ParAux)
        );

        break;

    case 17:
        printf("          %11s -> ", NonTerminalToString[Par]);  
        printf("%s", terminalToString[catComma]);
        printf("%s", NonTerminalToString[ParAux]);

        push( // ParAux
            stack, createGenericToken(False, ParAux)
        );
        push( // ','
            stack, createGenericToken(True, catComma)
        );

        break;

    case 18:
        printf("          %11s -> Epsilon", NonTerminalToString[Par]);  
        break;

    case 19:
        printf("          %11s -> ", NonTerminalToString[ParAux]); 
        printf("%s", NonTerminalToString[VarType]);
        printf("%s", terminalToString[catId]);
        printf("%s", NonTerminalToString[FunTypeAux]);
        printf("%s", NonTerminalToString[Par]); 

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
        printf("          %11s -> ", NonTerminalToString[ParAux]); 
        printf("%s", NonTerminalToString[Exp]);
        printf("%s", NonTerminalToString[Par]); 

        push( // Par
            stack, createGenericToken(False, Par)
        );
        push( // Exp
            stack, createGenericToken(False, Exp)
        );

        break;

    case 21:
        printf("          %11s -> ", NonTerminalToString[SentList]);  
        printf("%s", NonTerminalToString[Sent]);
        printf("%s", NonTerminalToString[SentListAux]);

        push( // SentListAux
            stack, createGenericToken(False, SentListAux)
        );
        push( // Sent
            stack, createGenericToken(False, Sent)
        );

        break;

    case 22:
        printf("          %11s -> ", NonTerminalToString[SentListAux]);
        printf("%s", NonTerminalToString[SentList]);

        push( // SentList
            stack, createGenericToken(False, SentList)
        );

        break;

    case 23:

        printf("          %11s -> Epsilon", NonTerminalToString[SentListAux]);  
        break;

    case 24:
        printf("          %11s -> ", NonTerminalToString[Sent]);  
        printf("%s", terminalToString[catIf]);
        printf("%s", NonTerminalToString[BoolExp]);
        printf("%s", terminalToString[catDo]);
        printf("%s", NonTerminalToString[SentList]);
        printf("%s", terminalToString[catEnd]);
        printf("%s", NonTerminalToString[Else]);

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
        printf("          %11s -> ", NonTerminalToString[Sent]);  
        printf("%s", terminalToString[catWhile]);
        printf("%s", NonTerminalToString[BoolExp]);
        printf("%s", terminalToString[catDo]);
        printf("%s", NonTerminalToString[SentList]);
        printf("%s", terminalToString[catEnd]);

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
        printf("          %11s -> ", NonTerminalToString[Sent]);  
        printf("%s", terminalToString[catFrom]);
        printf("%s", NonTerminalToString[Atr]);
        printf("%s", terminalToString[catTo]);
        printf("%s", NonTerminalToString[ArExp]);
        printf("%s", NonTerminalToString[Doing]);
        printf("%s", terminalToString[catDo]);
        printf("%s", NonTerminalToString[SentList]);
        printf("%s", terminalToString[catEnd]);

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
        printf("          %11s -> ", NonTerminalToString[Sent]);  
        printf("%s", NonTerminalToString[Decl]);
        printf("%s", terminalToString[catSemiCol]);

        push( // ';'
            stack, createGenericToken(True, catSemiCol)
        );
        push( // Decl
            stack, createGenericToken(False, Decl)
        );

        break;

    case 28:
        printf("          %11s -> ", NonTerminalToString[Sent]);  
        printf("%s", NonTerminalToString[Atr]);
        printf("%s", terminalToString[catSemiCol]);

        push( // ';'
            stack, createGenericToken(True, catSemiCol)
        );
        push( // Atr
            stack, createGenericToken(False, Atr)
        );

        break;

    case 29:
        printf("          %11s -> ", NonTerminalToString[Sent]);  
        printf("%s", NonTerminalToString[Print]);
        printf("%s", terminalToString[catSemiCol]);

        push( // ';'
            stack, createGenericToken(True, catSemiCol)
        );
        push( // Print
            stack, createGenericToken(False, Print)
        );

        break;

    case 30:
        printf("          %11s -> ", NonTerminalToString[Sent]);  
        printf("%s", NonTerminalToString[Read]);
        printf("%s", terminalToString[catSemiCol]);

        push( // ';'
            stack, createGenericToken(True, catSemiCol)
        );
        push( // Read
            stack, createGenericToken(False, Read)
        );

        break;

    case 31:
        printf("          %11s -> ", NonTerminalToString[Sent]);  
        printf("%s", NonTerminalToString[FunCall]);
        printf("%s", terminalToString[catSemiCol]);

        push( // ';'
            stack, createGenericToken(True, catSemiCol)
        );
        push( // FunCall
            stack, createGenericToken(False, FunCall)
        );

        break;

    case 32:
        printf("          %11s -> ", NonTerminalToString[Sent]);  
        printf("%s ", NonTerminalToString[Return]);
        printf("%s ", terminalToString[catSemiCol]);

        push( // ';'
            stack, createGenericToken(True, catSemiCol)
        );
        push( // Return
            stack, createGenericToken(False, Return)
        );

        break;

    case 33:
        printf("          %11s -> ", NonTerminalToString[Else]);  
        printf("%s ", terminalToString[catElse]);
        printf("%s ", terminalToString[catDo]);
        printf("%s ", NonTerminalToString[SentList]);
        printf("%s ", terminalToString[catEnd]);

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
        printf("          %11s -> Epsilon", NonTerminalToString[Else]);  
        break;

    case 35:
        printf("          %11s -> ", NonTerminalToString[Doing]);  
        printf("%s ", terminalToString[catDoing]);
        printf("%s ", NonTerminalToString[Atr]);

        push( // Atr
            stack, createGenericToken(False, Atr)
        );
        push( // 'doing'
            stack, createGenericToken(True, catDoing)
        );

        break;

    case 36:
        printf("          %11s -> Epsilon", NonTerminalToString[Doing]);  
        break;

    case 37:
        printf("          %11s -> ", NonTerminalToString[Decl]);
        printf("%s ", NonTerminalToString[VarType]);
        printf("%s ", NonTerminalToString[Id]);

        push( // Id
            stack, createGenericToken(False, Id)
        );
        push( // VarType
            stack, createGenericToken(False, VarType)
        );
    
        break;

    case 38:
        printf("          %11s -> ", NonTerminalToString[Id]);
        printf("%s ", terminalToString[catId]);
        printf("%s ", NonTerminalToString[VecType]);

        push( // VecType
            stack, createGenericToken(False, VecType)
        );
        push( // 'id'
            stack, createGenericToken(True, catId)
        );
    
        break;

    case 39:
        printf("          %11s -> ", NonTerminalToString[VecType]);  
        printf("%s ", terminalToString[catOpBrac]);
        printf("%s ", NonTerminalToString[Exp]);
        printf("%s ", terminalToString[catClsBrac]);

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
        printf("          %11s -> Epsilon", NonTerminalToString[VecType]);  
        break;

    case 41:
        printf("          %11s -> ", NonTerminalToString[Atr]);  
        printf("%s ", NonTerminalToString[Id]);
        printf("%s ", terminalToString[catOpeAtr]);
        printf("%s ", NonTerminalToString[Exp]);

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
        printf("          %11s -> ", NonTerminalToString[Print]);
        printf("%s ", terminalToString[catPrint]);
        printf("%s ", terminalToString[catOpPar]);
        printf("%s ", NonTerminalToString[Exp]);
        printf("%s ", terminalToString[catClsPar]);

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
        printf("          %11s -> ", NonTerminalToString[Read]);
        printf("%s ", terminalToString[catRead]);
        printf("%s ", terminalToString[catOpPar]);
        printf("%s ", NonTerminalToString[Id]);
        printf("%s ", NonTerminalToString[catClsPar]);

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
        printf("          %11s -> ", NonTerminalToString[FunCall]);  
        printf("%s ", terminalToString[catFunId]);
        printf("%s ", NonTerminalToString[OpClPar]);

        push( // OpClPar
            stack, createGenericToken(False, OpClPar)
        );
        push( // 'funId'
            stack, createGenericToken(True, catFunId)
        );
        break;

    case 45:
        printf("          %11s -> ", NonTerminalToString[Return]);  
        printf("%s ", terminalToString[catReturn]);
        printf("%s ", NonTerminalToString[ReturnRec]);

        push( // ReturnRec
            stack, createGenericToken(False, ReturnRec)
        );
        push( // 'return'
            stack, createGenericToken(True, catReturn)
        );
        break;

    case 46:
        printf("          %11s -> ", NonTerminalToString[ReturnRec]);  
        printf("%s ", NonTerminalToString[Exp]);

        push( // Exp
            stack, createGenericToken(False, Exp)
        );
        break;

    case 47:
        printf("          %11s -> Epsilon", NonTerminalToString[ReturnRec]);  
        break;

    case 48:
        printf("          %11s -> ", NonTerminalToString[Exp]);
        printf("%s ", NonTerminalToString[BoolExp]);
        printf("%s ", NonTerminalToString[ExpRec]);

        push( // ExpRec
            stack, createGenericToken(False, ExpRec)
        );
        push( // BoolExp
            stack, createGenericToken(False, BoolExp)
        );

        break;

    case 49:
        printf("          %11s -> ", NonTerminalToString[ExpRec]);  
        printf("%s ", terminalToString[catOpeConc]);
        printf("%s ", NonTerminalToString[BoolExp]);
        printf("%s ", NonTerminalToString[ExpRec]);

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
        printf("          %11s -> Epsilon", NonTerminalToString[ExpRec]);  
        break;

    case 51:
        printf("          %11s -> ", NonTerminalToString[BoolExp]);  
        printf("%s ", NonTerminalToString[BoolTerm]);
        printf("%s ", NonTerminalToString[BoolExpRec]);

        push( // BoolExpRec
            stack, createGenericToken(False, BoolExpRec)
        );
        push( // BoolTerm
            stack, createGenericToken(False, BoolTerm)
        );

        break;

    case 52:
        printf("          %11s -> ", NonTerminalToString[BoolExpRec]);  
        printf("%s ", terminalToString[catOpeOr]);
        printf("%s ", NonTerminalToString[BoolTerm]);
        printf("%s ", NonTerminalToString[BoolExpRec]);

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
        printf("          %11s -> Epsilon", NonTerminalToString[BoolExpRec]);  
        break;

    case 54:
        printf("          %11s -> ", NonTerminalToString[BoolTerm]);
        printf("%s ", NonTerminalToString[BoolFac]);
        printf("%s ", NonTerminalToString[BoolTermRec]);

        push( // BoolTermRec
            stack, createGenericToken(False, BoolTermRec)
        );
        push( // BoolFac
            stack, createGenericToken(False, BoolFac)
        );

        break;

    case 55:
        printf("          %11s -> ", NonTerminalToString[BoolTermRec]);  
        printf("%s ", terminalToString[catOpeAnd]);
        printf("%s ", NonTerminalToString[BoolFac]);
        printf("%s ", NonTerminalToString[BoolTermRec]);

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
        printf("          %11s -> Epsilon", NonTerminalToString[BoolTermRec]);  
        break;

    case 57:
        printf("          %11s -> ", NonTerminalToString[BoolFac]);
        printf("%s ", terminalToString[catOpeNeg]);
        printf("%s ", NonTerminalToString[EqExp]);

        push( // EqExp
            stack, createGenericToken(False, EqExp)
        );
        push( // '!'
            stack, createGenericToken(True, catOpeNeg)
        );
        
        break;

    case 58:
        printf("          %11s -> ", NonTerminalToString[BoolFac]);  

        printf("%s ", NonTerminalToString[EqExp]);

        push( // EqExp
            stack, createGenericToken(False, EqExp)
        );

        break;

    case 59:
        printf("          %11s -> ", NonTerminalToString[EqExp]);  
        printf("%s ", NonTerminalToString[RelExp]);
        printf("%s ", NonTerminalToString[EqExpAux]);

        push( // EqExpAux
            stack, createGenericToken(False, EqExpAux)
        );
        push( // RelExp
            stack, createGenericToken(False, RelExp)
        );

        break;

    case 60:
        printf("          %11s -> ", NonTerminalToString[EqExpAux]);
        printf("%s ", NonTerminalToString[EqOpe]);
        printf("%s ", NonTerminalToString[RelExp]);

        push( // RelExp
            stack, createGenericToken(False, RelExp)
        );
        push( // EqOpe
            stack, createGenericToken(False, EqOpe)
        );

        break;

    case 61:
        printf("          %11s -> Epsilon", NonTerminalToString[EqExpAux]);  
        break;

    case 62:
        printf("          %11s -> ", NonTerminalToString[EqOpe]); 
        printf("%s ", terminalToString[catOpeEq]);

        push( // '=='
            stack, createGenericToken(True, catOpeEq)
        );

        break;

    case 63:
        printf("          %11s -> ", NonTerminalToString[EqOpe]);  
        printf("%s ", terminalToString[catOpeDif]);

        push( // '!='
            stack, createGenericToken(True, catOpeDif)
        );

        break;

    case 64:
        printf("          %11s -> ", NonTerminalToString[RelExp]);  
        printf("%s ", terminalToString[catCteBool]);
        printf("%s ", NonTerminalToString[RelExpRec]);

        push( // RelExpRec
            stack, createGenericToken(False, RelExpRec)
        );
        push( // 'cteBool'
            stack, createGenericToken(True, catCteBool)
        );

        break;

    case 65:
        printf("          %11s -> ", NonTerminalToString[RelExp]);
        printf("%s ", NonTerminalToString[ArExp]);
        printf("%s ", NonTerminalToString[RelExpRec]);

        push( // RelExpRec
            stack, createGenericToken(False, RelExpRec)
        );
        push( // ArExp
            stack, createGenericToken(False, ArExp)
        );
    
        break;

    case 66:
        printf("          %11s -> ", NonTerminalToString[RelExpRec]);

        printf("%s ", NonTerminalToString[RelOpe]);
        printf("%s ", NonTerminalToString[RelExp]);
        printf("%s ", NonTerminalToString[RelExpRec]);

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
        printf("          %11s -> Epsilon", NonTerminalToString[RelExpRec]);  
        break;

    case 68:
        printf("          %11s -> ", NonTerminalToString[RelOpe]);
        printf("%s ", terminalToString[catOpeGt]);

        push( // '>'
            stack, createGenericToken(True, catOpeGt)
        );

        break;

    case 69:
        printf("          %11s -> ", NonTerminalToString[RelOpe]);
        printf("%s ", terminalToString[catOpeGte]);

        push( // '>='
            stack, createGenericToken(True, catOpeGte)
        );

        break;

    case 70:
        printf("          %11s -> ", NonTerminalToString[RelOpe]);
        printf("%s ", terminalToString[catOpeLt]);

        push( // '<'
            stack, createGenericToken(True, catOpeLt)
        );

        break;

    case 71:
        printf("          %11s -> ", NonTerminalToString[RelOpe]);  
        printf("%s ", terminalToString[catOpeLte]);

        push( // '<='
            stack, createGenericToken(True, catOpeLte)
        );

        break;

    case 72:
        printf("          %11s -> ", NonTerminalToString[ArExp]);  
        printf("%s ", NonTerminalToString[ArTerm]);
        printf("%s ", NonTerminalToString[ArExpRec]);

        push( // ArExpRec
            stack, createGenericToken(False, ArExpRec)
        );
        push( // ArTerm
            stack, createGenericToken(False, ArTerm)
        );

        break;

    case 73:
        printf("          %11s -> ", NonTerminalToString[ArExpRec]);  
        printf("%s ", NonTerminalToString[ArOpe]);
        printf("%s ", NonTerminalToString[ArTerm]);
        printf("%s ", NonTerminalToString[ArExpRec]);

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
        printf("          %11s -> Epsilon", NonTerminalToString[ArExpRec]);  
        break;

    case 75:
        printf("          %11s -> ", NonTerminalToString[ArTerm]);  
        printf("%s ", NonTerminalToString[ArFac]);
        printf("%s ", NonTerminalToString[ArTermRec]);

        push( // ArTermRec
            stack, createGenericToken(False, ArTermRec)
        );
        push( // ArFac
            stack, createGenericToken(False, ArFac)
        );

        break;

    case 76:
        printf("          %11s -> ", NonTerminalToString[ArTermRec]);  
        printf("%s ", NonTerminalToString[MultOpe]);
        printf("%s ", NonTerminalToString[ArFac]);
        printf("%s ", NonTerminalToString[ArTermRec]);

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
        printf("          %11s -> Epsilon", NonTerminalToString[ArTermRec]);  
        break;

    case 78:
        printf("          %11s -> ", NonTerminalToString[ArFac]);  
        printf("%s ", terminalToString[catOpPar]);
        printf("%s ", NonTerminalToString[ArExp]);
        printf("%s ", terminalToString[catClsPar]);

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
        printf("          %11s -> ", NonTerminalToString[ArFac]);
        printf("%s ", NonTerminalToString[Id]);

        push( // Id
            stack, createGenericToken(False, Id)
        );

        break;

    case 80:
        printf("          %11s -> ", NonTerminalToString[ArFac]);
        printf("%s ", NonTerminalToString[FunCall]);

        push( // FunCall
            stack, createGenericToken(False, FunCall)
        );

        break;

    case 81:
        printf("          %11s -> ", NonTerminalToString[ArFac]);
        printf("%s ", terminalToString[catCteInt]);

        push( // 'CteInt'
            stack, createGenericToken(True, catCteInt)
        );

        break;

    case 82:
        printf("          %11s -> ", NonTerminalToString[ArFac]);
        printf("%s ", terminalToString[catCteFloat]);

        push( // 'CteFloat'
            stack, createGenericToken(True, catCteFloat)
        );

        break;

    case 83:
        printf("          %11s -> ", NonTerminalToString[ArFac]);
        printf("%s ", terminalToString[catCteStr]);

        push( // 'CteString'
            stack, createGenericToken(True, catCteStr)
        );

        break;

    case 84:
        printf("          %11s -> ", NonTerminalToString[ArFac]);
        printf("%s ", terminalToString[catCteChar]);

        push( // 'CteChar'
            stack, createGenericToken(True, catCteChar)
        );

        break;

    case 85:
        printf("          %11s -> ", NonTerminalToString[ArOpe]);
        printf("%s ", terminalToString[catOpeSum]);

        push( // '+'
            stack, createGenericToken(True, catOpeSum)
        );

        break;

    case 86:
        printf("          %11s -> ", NonTerminalToString[ArOpe]);
        printf("%s ", terminalToString[catOpeSub]);

        push( // '-'
            stack, createGenericToken(True, catOpeSub)
        );

        break;

    case 87:
        printf("          %11s -> ", NonTerminalToString[MultOpe]);
        printf("%s ", terminalToString[catOpeMult]);

        push( // '*'
            stack, createGenericToken(True, catOpeMult)
        );

        break;

    case 88:
        printf("          %11s -> ", NonTerminalToString[MultOpe]);
        printf("%s ", terminalToString[catOpeDiv]);

        push( // '/'
            stack, createGenericToken(True, catOpeDiv)
        );

        break;

    case 89:
        printf("          %11s -> ", NonTerminalToString[MultOpe]);
        printf("%s ", terminalToString[catOpeMod]);

        push( // '%'
            stack, createGenericToken(True, catOpeMod)
        );

        break;

    default:
        break;
    }

    printf("\n");

    return stack;
}


