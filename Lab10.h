#ifndef LAB10_H
#define LAB10_H

#include <stdio.h>

typedef struct {
    char** arr;
    size_t size;
    size_t capacity;
} vector_t;

vector_t* parser(char* filename);
void print_vector(vector_t* str);
char* readWord(FILE* fp);
void quicksort(char** str, int high);
void push_back(vector_t* str, char* word);
void swap(char** a, char** b);
int is_ch(char ch);

#endif // !LAB10_H
