/****************************

ALLUPH - Analisador Lexico e Sintatico
Phyllipe Matheus Bezerra Alves
Lucas Agra de Omena
Universidade Federal de Alagoas
Ciencia da Computacao

*****************************/

typedef struct node {

    Boolean terminal;
    NonTerminal non_term;
    Category terminal;
    struct node* next;
} Node;

typedef struct stack {

    Node* top;
    int size;
} Stack;


Node* createNode(Boolean isTerminal, int catNum) {

    Node* newNode = malloc(sizeof(Node));

    newNode->terminal = isTerminal;

    newNode->non_term = NULL;
    newNode->terminal = NULL;

    if(isTerminal) {
        newNode->terminal = catNum;
    } else {
        newNode->non_term = catNum;
    }

    newNode->next = NULL;

    return newNode;
}

Boolean isEmpty(Stack* stack) {

    return stack->size == 0 ? True : False;
}


Node* peek(Stack* stack) {

    if (stack != NULL) {

        return stack->top;
    } else {
        printf("Peeking null stack\n");
        return NULL;
    }
}


Boolean push(Stack* stack, Boolean isTerminal, int catNum) {

    if (stack != NULL) {

        Node* newTop = createNode(isTerminal, catNum);
        newTop->next = stack->top;
        stack->top = newTop;
        ++stack->size;

        return True;
    } else {

        return False;
    }
}


Node* pop(Stack* stack) {

    if (stack->size > 0 && stack != NULL) {

        Node* popped = stack->top;
        stack->top = stack->top->next;

        --stack->size;

        return popped;
    } else {

        return NULL;
    }
}



int clearStack(Stack* stack) {

    int popped_count = 0;

    Node* aux;

    while ((aux = pop(stack)) != NULL) {
        free(aux);
        ++popped_count;
    }

    if (stack != NULL) {

        // force stack to remove the last node
        ++stack->size;
        aux = pop(stack);
        free(aux);
        ++popped_count;
    }

    return popped_count;
}

Stack* createStack() {

    Stack* newStack = malloc(sizeof(Stack));
    newStack->top = NULL;
    newStack->size = 0;
    
    return newStack; 
}
