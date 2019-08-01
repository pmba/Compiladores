typedef struct list {
    Token* head;

} List;


List* newList() {

    List* new_list = malloc(sizeof(List));
    new_list->head = NULL;

    return new_list;
}

List* pushList(List* list, Token* newToken) {

    _DEBUG printf("Add %s \n", newToken->lexeme);

    if(list->head == NULL) {
        list->head = newToken;
    } else {

        Token* aux = list->head;

        _DEBUG printf("%s -> ", aux->lexeme);

        while(aux->next != NULL) {
            aux = aux->next;
            _DEBUG printf("%s -> ", aux->lexeme);
        }

        aux->next = newToken;        
    }
    _DEBUG printf("\n ok \n\n");
    return list;
}

Token* nextToken(List* list) {
    if (list->head == NULL) return NULL;

    if (list->head->next == NULL){
        Token* aux = list->head;
        list->head = NULL;
        return aux;
    } 
     
    else {
        Token* aux = list->head;
        list->head = list->head->next;

        return aux;
    }
}

void printList (List* list) {

    if(list->head != NULL) {

        Token* aux = list->head;
        
        printToken(list->head);
        
        while(list->head->next != NULL) {
            list->head = list->head->next;
            printToken(list->head);
        }

        list->head = aux;

    } else {
        printf("Empty list\n");
    }
}