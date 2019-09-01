#ifndef STACK_H
#define STACK_H

/* generic category used to join non-terminals and terminals category at stack */

typedef struct gen_tk {

    Boolean terminal;
    int catNum;
    struct gen_tk* next;
} GenericToken;

typedef struct stack {

    GenericToken* top;
    int size;
} Stack;

GenericToken* createGenericToken(Boolean isTerminal, int catNum);
Boolean isEmpty(Stack* stack);
GenericToken* peek(Stack* stack);
Boolean push(Stack* stack, GenericToken* gerToken);
GenericToken* pop(Stack* stack);
int clearStack(Stack* stack);
Stack* createStack();

#endif // STACK_H
