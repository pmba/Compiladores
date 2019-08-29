#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../includes/auxiliar.h"
#include "../includes/file.h"

/****************************

ALLUPH - Analisador Lexico e Sintatico
Phyllipe Matheus Bezerra Alves
Lucas Agra de Omena
Universidade Federal de Alagoas
Ciencia da Computacao

*****************************/

int current_line = 0;

Boolean openFile(const char* path) {

    file = fopen(path, "r");

    if (file != NULL) {
        
        _DEBUG printf("[Success] File \"%s\" opened on read mode.\n", path);
        return True;
    } else {
        
        printf("[Error] File \"%s\" not found.\n", path);
        return False;
    }
}

void closeFile() {
    fclose(file);
}

Boolean emptyLine(char* line) {

    int i;
    for (i = 0; line[i] != '\0'; ++i) {

        if (line[i] != ' ') 
            return False;
    }

    return True;
}

char* readLine() {
    
    char* line = NULL;
    size_t len = 0;
    size_t read;

    if ((read = getline(&line, &len, file)) != -1) {
        
        ++current_line;

        int line_len = strlen(line);

        if (line_len >= 1 && line[line_len - 1] == '\n') {

            line[line_len - 1] = '\0';
        }

        if (emptyLine(line)) {

            printLine(line, current_line);
            return readLine();    
        } else {

            printLine(line, current_line);
            return line;
        }
    }


    free(line);
    return NULL;
}