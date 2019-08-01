#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

int main(int argc, char const *argv[]) {

    // // printf("> %s\n", argv[1]);

    // regex_t _funIdRE;

    // char str[] = "\'a\'";

    // printf("> %s\n", str);

    // if (regcomp(&_funIdRE, "^\'([ a-zA-Z0-9.,:;\\?!\\+\\-\\*/\\_@&%\\$<>=(){}[]|])\'$", 
    //     REG_EXTENDED|REG_NOSUB) != 0) {

    //     printf("Error\n");
    //     exit(EXIT_FAILURE);
    // }

    // if (regexec(&_funIdRE, str, 0, (regmatch_t*) NULL, 0) == 0) {

    //     printf("Match\n");
    // } else {

    //     printf("Not a Match.\n");
    // }

    char str[10];

    char c = 'a';

    str = c;

    printf("%s\n", str);

    return 0;
}