#ifndef LEXICAL_H
#define LEXICAL_H

#define RegularExpressionsQuant 48

int _column;

// DO NOT CHANGE DE ORDER
extern const char regular_exp_pattern[][90];

Boolean initializeLexicalAnalyzer();
Boolean isAnalisysSpecialChar(char ch);
Token* recognizeWord(char* word, int col);
Token* recognizeSpecialChar(char ch, char next_ch, int col);
Boolean analyseLine();

#endif // LEXICAL_H
