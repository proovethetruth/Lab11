#ifndef LAB10_H
#define LAB10_H

#include <stdio.h>
char** parser(char* filename);
int count_words(FILE* fp);
char* readWord(FILE* fp);
void quicksort(char** str, int length);
void swap(char** a, char** b);
int is_ch(char ch);

#endif // !LAB10_H
