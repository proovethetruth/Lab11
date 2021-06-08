#ifndef LAB10_H
#define LAB10_H

#include <stdio.h>

typedef struct {
    char** arr;
    size_t size;
    size_t capacity;
} vector_t;

void init_vector(vector_t* v);
void destroy(vector_t* v);
void push_back(vector_t* str, char* word);
void print_vector(vector_t* str);

void parse(vector_t* str, char* filename);
char* readWord(FILE* fp);

void quicksort(char** str, int high);
void swap(char** a, char** b);

int is_ch(char ch);

#endif // !LAB10_H