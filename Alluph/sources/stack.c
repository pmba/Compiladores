#include <stdio.h>
#include <stdlib.h>

#include "../includes/auxiliar.h"
#include "../includes/stack.h"

/****************************

ALLUPH - Analisador Lexico e Sintatico
Phyllipe Matheus Bezerra Alves
Lucas Agra de Omena
Universidade Federal de Alagoas
Ciencia da Computacao

*****************************/

/*

    createNode: (GenericCategory, next) -> Node*

    Create a new node wich contains a value and a next, if the node needs to be the head node,
    just pass NULL on 'next' parameter.
 
 */
Node* createNode(GenericCategory value, Node* next) {

    Node* newNode = malloc(sizeof(Node*));

    newNode->value = value;
    newNode->next = next;

    return newNode;
}

/*

    isEmpty: (Stack*) -> Boolean

    return True if the stack has a size of 0 otherwise return False

*/

Boolean isEmpty(Stack* stack) {

    return stack->size == 0 ? True : False;
}

/*

    peek: (Stack*) -> GenericCategory

    return the stack->top->value if stack is not NULL, otherwise return EmptyStack

*/

GenericCategory peek(Stack* stack) {

    if (stack != NULL) {

        return stack->top->value;
    } else {

        return EmptyStack;
    }
}

/*

    push: (Stack*, GenericCategory) -> Boolean

    push a new node to the top of the given stack if the stack is not null, otherwise
    return false

*/

Boolean push(Stack* stack, GenericCategory value) {

    if (stack != NULL) {

        Node* newTop = createNode(value, stack->top);
        stack->top = newTop;
        ++stack->size;

        return True;
    } else {

        return False;
    }
}

/*

    pop: (Stack*) -> GenericCategory

    return the stack->top->value, and remove it, if stack is not NULL and stack size is greater 
    than 0, otherwise return EmptyStack

*/

GenericCategory pop(Stack* stack) {

    if (stack->size > 0 && stack != NULL) {

        Node* popped = stack->top;
        stack->top = stack->top->next;

        GenericCategory popped_value = popped->value;
        free(popped);

        --stack->size;

        return popped_value;
    } else {

        return EmptyStack;
    }
}

/*

    clearStack: (Stack*) -> int

    pop all elements from the given stack and return how many elements has been removed, including
    the default node (EmptyStack)

*/

int clearStack(Stack* stack) {

    int popped_count = 0;

    while (pop(stack) != EmptyStack) {
        ++popped_count;
    }

    if (stack != NULL) {

        // force stack to remove the last node
        ++stack->size;
        pop(stack);
        ++popped_count;
    }

    return popped_count;
}

/*

    createStack: () -> Stack*

    create a new empty stack, with a default top (EmptyStack) and return it

*/

Stack* createStack() {

    Stack* newStack = malloc(sizeof(Stack*));
    newStack->top = createNode(EmptyStack, NULL);
    newStack->size = 0;
    
    return newStack; 
}
