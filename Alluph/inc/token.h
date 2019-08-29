typedef struct token {

    char* lexeme;
    Category category;
    int row, col;
    
} Token;

typedef struct list_node {
    Token* token;
    struct list_node* next;

} ListNode;

Token* newToken(char* lex, Category cat, int row, int col) {

    Token* new_token = (Token*) malloc(sizeof(Token));

    new_token->lexeme = lex;
    new_token->category = cat;
    new_token->row = row;
    new_token->col = col;
    
    return new_token;
}

Token* newStrChToken(char* lex, int row, int col) {

    Category token_cat;
    if (lex[0] == '\'' || lex[0] == '"') {
            
        char* aux = (char*) malloc(strlen(lex));
        for(int j = 0; j < strlen(lex); j++) {
            aux[j] = lex[j];
        }
        aux[strlen(lex)] = '\0';
        
        if (lex[0] == '\'' ) return newToken(aux, catCteChar, row, col);
        if (lex[0] == '"') return newToken(aux, catCteStr, row, col);
    }

    printf("Erro newStrChToken");
    return NULL;
}

Token* nextToken(ListNode* TokenList) {

    if (TokenList == NULL) {

        TokenList = analyseLine(TokenList);
        
        if(TokenList == NULL) {
            return newToken("EOF", catEOF, current_line, _column+1);
        }
    }

    if (TokenList->next == NULL){
        Token* aux = TokenList->token;
        TokenList = NULL;

        return aux;
    } 
     
    else {
        Token* aux = TokenList->token;
        TokenList = TokenList->next;

        return aux;
    }
}

void printToken(Token* token) {
    printf("          [%04d, %04d] (%04d, %20s) {%s}\n", token->row, token->col, token->category, categoryToString[token->category], token->lexeme);
}

ListNode* newListNode(Token* token) {

    ListNode* new_list_node = malloc(sizeof(ListNode));
    new_list_node->token = token;
    new_list_node->next = NULL;

    return new_list_node;
}

ListNode* pushList(ListNode* head, Token* token) {

    if(head == NULL) {
        head = newListNode(token);
    } else {

        ListNode* aux = head;

        while(aux->next != NULL) {
            aux = aux->next;            
        }

        aux->next = newListNode(token);        
    }  

    return head;
}

void printList (ListNode* head) {

    if(head != NULL) {

        ListNode* aux = head;
        
        while(aux != NULL) {
            printToken(aux->token);
            aux = aux->next;
        }

        free(aux);
    } else {
        printf("Empty list\n");
    }
}
