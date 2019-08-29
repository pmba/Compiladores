#ifndef FILE_READER_H
#define FILE_READER_H

FILE* file;
extern int current_line;

Boolean openFile(const char* path);
void closeFile();
Boolean emptyLine(char* line);
char* readLine();

#endif // FILE_READER_H
