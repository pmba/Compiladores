#ifndef STACK_H
#define STACK_H

/* generic category used to join non-terminals and terminals category at stack */

typedef enum generic_cat { EmptyStack = -1 } GenericCategory; 

typedef struct node {

    GenericCategory value;
    struct node* next;
} Node;

typedef struct stack {

    Node* top;
    int size;
} Stack;

Node* createNode(GenericCategory value, Node* next);
Boolean isEmpty(Stack* stack);
GenericCategory peek(Stack* stack);
Boolean push(Stack* stack, GenericCategory value);
GenericCategory pop(Stack* stack);
int clearStack(Stack* stack);
Stack* createStack();

#endif // STACK_H
