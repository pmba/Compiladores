/****************************

ALLUPH - Analisador Lexico e Sintatico
Phyllipe Matheus Bezerra Alves
Lucas Agra de Omena
Universidade Federal de Alagoas
Ciencia da Computacao

*****************************/

const char regular_exp[][90] = {

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
            return True;
            break;
        default:
            return False;
            break;
    }
}

Token* recognizeSpecialChar(char ch, char next_ch, int col) {

    if (ch == ' ' || ch == '\0' || ch == '\n') { 
        printf("Return NULL\n");
        return NULL;
    }

    char lexeme[3];

    switch (ch) {

        case '(':
            lexeme[0] = '(';
            lexeme[1] = '\0';

            return newToken(lexeme, catOpPar, current_line, col);
            break;

        case ')':
            lexeme[0] = ')';
            lexeme[1] = '\0';

            return newToken(lexeme, catClsPar, current_line, col);
            break;

        case '[':
            lexeme[0] = '[';
            lexeme[1] = '\0';

            return newToken(lexeme, catOpBrac, current_line, col);
            break;

        case ']':
            lexeme[0] = ']';
            lexeme[1] = '\0';

            return newToken(lexeme, catClsBrac, current_line, col);
            break;

        case ',':
            lexeme[0] = ',';
            lexeme[1] = '\0';

            return newToken(lexeme, catComma, current_line, col);
            break;

        case '+':
            if (next_ch == '+') {
                // ++ case
                lexeme[0] = '+';
                lexeme[1] = '+';
                lexeme[2] = '\0';

                return newToken(lexeme, catOpeConc, current_line, col);
            } else {
                // + case
                lexeme[0] = '+';
                lexeme[1] = '\0';

                return newToken(lexeme, catOpeSum, current_line, col);
            }
            break;

        case '-':
            lexeme[0] = '-';
            lexeme[1] = '\0';

            return newToken(lexeme, catOpeSub, current_line, col);
            break;

        case '*':
            lexeme[0] = '*';
            lexeme[1] = '\0';

            return newToken(lexeme, catOpeMult, current_line, col);
            break;

        case '/':
            lexeme[0] = '/';
            lexeme[1] = '\0';

            return newToken(lexeme, catOpeDiv, current_line, col);
            break;

        case '%':
            lexeme[0] = '%';
            lexeme[1] = '\0';

            return newToken(lexeme, catOpeMod, current_line, col);
            break;

        case ';':
            lexeme[0] = '/';
            lexeme[1] = '\0';

            return newToken(lexeme, catSemiCol, current_line, col);
            break;

        default:
            return NULL;
            break;
    }
}

Boolean analyseLine(char* line) {

    int i;
    int buffer_index = 0;

    char buffer[31];

    for (i = 0; i <= strlen(line); ++i) {

        if (isalnum(line[i]) || line[i] == '_') {
            buffer[buffer_index++] = line[i];
        }

        if (isAnalisysSpecialChar(line[i]) && buffer_index != 0) {

            char analisys_special_char = line[i];
            buffer[buffer_index] = '\0';
            buffer_index = 0;

            _DEBUG printf("\t[Info] Lexeme found: \"%s\"\n", buffer);

            Token* recognized_char = recognizeSpecialChar(line[i], line[i+1], i);

            if (recognized_char != NULL) {
                _DEBUG printf("\t[Info] Lexeme found: \"%s\"\n", recognized_char->lexeme);

            }
            
            free(recognized_char);
        }
    }
}