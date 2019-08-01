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


const char regular_exp[][RegularExpressionsQuant] = {

    "^function$", "^do$", "^end$", 
    "^main$", "^int$", "^float$", "^string$",
    "^bool$", "^char$", "^void$", "^($", "^)$",
    "^,$", "^if$", "^while$", "^from$", "^to$", 
    "^else$", "^doing$", "^;$", "^[$", "^]$",
    "^print$", "^read$", "^return$", "^++$", 
    "^or$", "^and$", "^!$", "^=$", "^==$", 
    "^!=$", "^(true|false)$", "^>$", "^>=$",
    "^<$", "^<=$", "^\\+$", "^\\-$", "^\\*$",
    "^\\/$", "^\\%$", 
    "(_)([a-zA-Z])([a-zA-Z|[0-9]|_)*",
    "([a-zA-Z])([a-zA-Z|[0-9]|_)*",
    "^-?[0-9]+$", "^-?[0-9]+(.[0-9]+)$",
    "^\"([ a-zA-Z]|[0-9]|[.,:;\\?!\\+\\-\\*/\\_@&%\\$<>=()])*(\\[|\\])*(\\{\\})*(\\|)*(\')*\"$",
    "^\'([ a-zA-Z0-9.,:;\\?!\\+\\-\\*/\\_@&%\\$<>=(){}[]|])\'$"

};