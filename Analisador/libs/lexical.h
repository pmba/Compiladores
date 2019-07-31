/****************************

ALLUPH - Analisador Lexico e Sintatico
Phyllipe Matheus Bezerra Alves
Lucas Agra de Omena
Universidade Federal de Alagoas
Ciencia da Computacao

*****************************/

typedef struct token {

    char* lexeme;
    Category category;
    int row, col;

    struct token* next;
} Token;