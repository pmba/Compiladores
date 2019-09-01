#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include <ctype.h>
#include <regex.h>

#include "../includes/auxiliar.h"
#include "../includes/file.h"
#include "../includes/list.h"
#include "../includes/lexical.h"

/****************************

ALLUPH - Analisador Lexico e Sintatico
Phyllipe Matheus Bezerra Alves
Lucas Agra de Omena
Universidade Federal de Alagoas
Ciencia da Computacao

*****************************/

regex_t regular_exp[RegularExpressionsQuant] = {0};

const char regular_exp_pattern[][90] = {

    "^function$",
    "^do$", 
    "^end$", 
    "^main$", 
    "^int$", 
    "^float$", 
    "^string$",
    "^bool$", 
    "^char$", 
    "^void$", 
    "^\\($", 
    "^)$",
    "^,$", 
    "^if$", 
    "^while$", 
    "^from$", 
    "^to$", 
    "^else$", 
    "^doing$", 
    "^;$", 
    "^\\[$", 
    "^]$",
    "^print$", 
    "^read$", 
    "^return$", 
    "^\\+\\+$", 
    "^or$", 
    "^and$", 
    "^!$", 
    "^=$", 
    "^==$", 
    "^!=$", 
    "^(true|false)$", 
    "^>$", 
    "^>=$",
    "^<$", 
    "^<=$", 
    "^\\+$", 
    "^\\-$", 
    "^\\*$",
    "^\\/$", 
    "^\\%$", 
    "^(_)([a-zA-Z])([a-zA-Z|[0-9]|_)*$",
    "^([a-zA-Z])([a-zA-Z|[0-9]|_)*$",
    "^-?[0-9]+$", 
    "^-?[0-9]+(.[0-9]+)$",
    "^\"[ a-zA-Z0-9.,:;\\?!\\+\\-\\*/\\_@&%\\$<>=()'{}[]|]*\"$",
    "^\'[ a-zA-Z0-9.,:;\\?!\\+\\-\\*/\\_@&%\\$<>=(){}[]|]\'$"

};


Boolean initializeLexicalAnalyzer() {

    int i;
    for (i = 0; i < RegularExpressionsQuant; ++i) {

        _DEBUG printf("  [Regex] Compiling regex #%d\n", i);

        if (regcomp(&regular_exp[i], regular_exp_pattern[i], REG_EXTENDED)) {
            printf("[Error] Can't compile regex [%d]: \"%s\"\n", i, regular_exp_pattern[i]);
            return False;
        }
    }

    return True;
} 

Boolean isAnalisysSpecialChar(char ch) {

    switch (ch) {

        case ' ':
        case '\0':
        case '(':
        case ')':
        case '[':
        case ']':
        case ',':
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case ';':
        case '=':
        case '!':
        case '>':
        case '<':
        case '"':
        case '\'':
            return True;
            break;
        default:
            return False;
            break;
    }
}

Token* recognizeWord(char* word, int col) {

    _DEBUG printf("  [Info] Searching for regex match \"%s\"\n", word);

    int i;

    for (i = 0; i < RegularExpressionsQuant; ++i) {
        if (regexec(&regular_exp[i], word, 0, (regmatch_t*) NULL, 0) == 0) {
            _DEBUG printf("    [Info] Regex Match #%d Found \"%s\", Category \"%s\"\n", i, word, categoryToString[i]);

            char* aux = (char*) malloc(strlen(word));
            for(int j = 0; j < strlen(word); j++) {
                aux[j] = word[j];
            }
            aux[strlen(word)] = '\0';

            return newToken(aux, (Category)i, current_line, col);
        } 
    }

    return newToken("_missing", _unrecognized, current_line, col);
}

Token* recognizeSpecialChar(char ch, char next_ch, int col) {

    if (ch == ' ' || ch == '\0' || ch == '\n' || ch == '\t') { 
        return NULL;
    }

    switch (ch) {

        case '(':
            return newToken("(", catOpPar, current_line, col);
            break;

        case ')':
            return newToken(")", catClsPar, current_line, col);
            break;

        case '[':
            return newToken("[", catOpBrac, current_line, col);
            break;

        case ']':
            return newToken("]", catClsBrac, current_line, col);
            break;

        case ',':
            return newToken(",", catComma, current_line, col);
            break;

        case '=':
            return newToken("=", catOpeEq, current_line, col);
            break;

        case '"':
        case '\'':
            return newToken("_missing", _unrecognized, current_line, col);
            break;

        case '+':
            if (next_ch == '+') {
                // ++ case and eat next_token
                ++_column;
                return newToken("++", catOpeConc, current_line, col);
            } 

            return newToken("+", catOpeSum, current_line, col);
            break;

        case '-':
            return newToken("-", catOpeSub, current_line, col);
            break;

        case '*':
            return newToken("*", catOpeMult, current_line, col);
            break;

        case '/':
            return newToken("/", catOpeDiv, current_line, col);
            break;

        case '%':
            return newToken("%", catOpeMod, current_line, col);
            break;

        case ';':
            return newToken(";", catSemiCol, current_line, col);
            break;

        case '!':
            return newToken("!", catOpeNeg, current_line, col);
            break;

        case '>':
            if (next_ch == '=') {
                // >= case and eat next_token
                ++_column;
                return newToken(">=", catOpeGte, current_line, col);
            }

            return newToken(">", catOpeGt, current_line, col);
            break;

        case '<':
            if (next_ch == '=') {
                // <= case and eat next_token
                ++_column;
                return newToken("<=", catOpeLte, current_line, col);
            }

            return newToken("<", catOpeLt, current_line, col);
            break;

        default:
            return NULL;
            break;
    }
}
ListNode* analyseLine(ListNode* TokenList) {

    char* line = readLine();

    if (line != NULL) {

        int buffer_index = 0;

        char buffer[33];

        for (_column = 0; _column <= strlen(line); ++_column) {

            if (isalnum(line[_column]) || line[_column] == '_') {
                buffer[buffer_index++] = line[_column];
            }

            if (isAnalisysSpecialChar(line[_column])) {

                if (buffer_index != 0) {

                    char analisys_special_char = line[_column];
                    buffer[buffer_index] = '\0';
                    buffer_index = 0;

                    _DEBUG printf("\t[Info] Lexeme found: \"%s\"\n", buffer);
                    Token* recognized_word = recognizeWord(buffer, _column);
                    
                    if(recognized_word->category != _unrecognized) {
                        TokenList = pushList(TokenList, recognized_word);
                    }
                
                }

                if (line[_column] == '"' || line[_column] == '\'') {
                    int j;
                    Boolean _closed_cte = False;

                    for (j = _column + 1; line[j] != '\0'; ++j) {

                        if (line[j] == line[_column]) {
                            _closed_cte = True;
                            break;
                        }
                    }

                    int _cte_length = _closed_cte ? j-(_column) : 0;

                    if (_cte_length > 0) {
                        char _cte_lex[_cte_length+2];

                        for (j = _column; j <= _cte_length + _column; ++j) {
                            _cte_lex[j-_column] = line[j];
                        }

                        _cte_lex[j-_column] = '\0';
                        Token* recognized_cte = newStrChToken(_cte_lex, current_line, _column);
                    
                        TokenList = pushList(TokenList, recognized_cte);
                        _column += _cte_length;
                        continue;
                    }
                }

                Token* recognized_char = recognizeSpecialChar(line[_column], line[_column+1], _column);

                if (recognized_char != NULL) {

                    _DEBUG printf("\t[Info] Lexeme found: \"%s\", Category \"%s\"\n", recognized_char->lexeme, categoryToString[recognized_char->category]);
                    TokenList = pushList(TokenList, recognized_char);
                
                }
            } 

        } 
    } 
    return TokenList;
}