typedef struct list {
    struct list* next;
    Token* token;

} List;


List* newList() {

    List* new_list = malloc(sizeof(List));

    new_list->token = NULL;
    new_list->next = NULL;

    return new_list;
}

List* pushList(List* list, Token* newToken) {

    _DEBUG printf("Add %s \n", newToken->lexeme);

    if(list->token == NULL) {
        list->token = newToken;
    } else {

        List* aux = list;

        _DEBUG printf("%s -> ", aux->token->lexeme);

        while(aux->next != NULL) {
            aux = aux->next;
            _DEBUG printf("%s -> ", aux->token->lexeme);
        }
        aux->next = newList();
        aux->next->token = newToken;        
    }
    _DEBUG printf("\n ok \n\n");
    return list;
}

Token* nextToken(List* list) {

}

List* popList(List* list) {
    if (list->token == NULL) return NULL;

    List* aux = list->token;

    if (list->next == NULL){
        list->token = NULL;
    } 
     
    else {
        list = (list->next);
    }

    return aux;
}

void printList (List* list) {

    if(list->token != NULL) {

        List* aux = list;
        
        printToken(aux->token);
        
        while(aux->next != NULL) {
            aux = aux->next;
            printToken(aux->token);
        }

    } else {
        printf("Empty list\n");
    }
}