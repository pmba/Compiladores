#include "./auxiliar.h"

#define _DEBUG if(True)

typedef struct list {
    Token* head;

} List;


List* newList() {

    List* new_list = malloc(sizeof(List*));
    new_list->head = NULL;

    return new_list;
}

void pushList(List* list, Token* newToken) {

    if(list->head == NULL) {
        list->head = newToken;
        return;
    }

    Token* aux = list->head;

    while(list->head->next != NULL) {
        list->head = list->head->next;
    }

    list->head->next = newToken;
    list->head = aux;
}

Token* nextToken(List* list) {
    if (list->head == NULL) return NULL;

    if (list->head->next == NULL) 
        return list->head;

    else {
        Token* aux = list->head;
        list->head = list->head->next;

        return aux;
    }
}

void printList (List* list) {
    Token* aux = list->head;

    if(list->head != NULL) {
        printf("%s\n", list->head->lexeme);
    }

    while(list->head->next != NULL) {
        list->head = list->head->next;
        printf("%s\n", list->head->lexeme);
    }

    list->head = aux;
}