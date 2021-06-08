
#define _CRT_SECURE_NO_WARNINGS

#include "Lab10.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

void init_vector(vector_t* v) {
    v->arr = (char**)calloc(2, sizeof(char) * 2);
    v->arr[1] = NULL;
    v->size = 0;
    v->capacity = 2;
}

void destroy(vector_t* v) {
    for (int i = 0; i < (int)v->size; i++)
    {
        if (v->arr[i] != NULL)
            free(v->arr[i]);
    }
}



void parser(vector_t* str, char* filename) {
    FILE* fp;
    if (!(fp = fopen(filename, "r")))
        return;

    init_vector(str);

    char* word;
    while ((word = readWord(fp)) != NULL)
        push_back(str, word);

    quicksort(str->arr, str->size);
}

void push_back(vector_t* str, char* word) {
    char** tmp = NULL;
    if (str->size + 1 >= str->capacity)
    {
        str->capacity *= 2;

        tmp = (char**)calloc(str->capacity, str->capacity * sizeof(char));
        if (!tmp)
        {
            printf("\n\a ERROR: Can't allocate enough memory");
            return;
        }
        for (int i = 0; i < str->size; i++)
        {
            tmp[i] = str->arr[i];
            free(str->arr[i]);
        }
        str->arr = tmp;
    }
    str->arr[str->size] = word;
    str->arr[str->size + 1] = NULL;
    str->size++;
}

void swap(char** a, char** b) {
    char* temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(char** str, int high) {
    unsigned int i, piv = 0;
    if (high <= 1)
        return;

    for (i = 0; i < high; i++) {
        // if curr str < pivot str, move curr into lower array and  lower++(pvt)
        if (strcmp(str[i], str[high - 1]) < 0) 	//use string in last index as pivot
            swap(str + i, str + piv++);
    }
    //move pivot to "middle"
    swap(str + piv, str + high - 1);

    //recursively sort upper and lower
    quicksort(str, piv++);			//set length to current pvt and increase for next call
    quicksort(str + piv, high - piv);
}

char* readWord(FILE* fp) {
    char ch = 0;

    while (!is_ch(ch))
    {
        ch = fgetc(fp);
        if (ch == EOF || !ch)
            return NULL;
    }

    int size = 1;
    while (is_ch(ch))
    {
        if ((ch = fgetc(fp)) == EOF || !ch)
            break;
        size++;
    }
    fseek(fp, -(size * (int)sizeof(char)), 1);

    if (ch != EOF || !ch)
        size--;

    char* word = (char*)calloc(size, sizeof(char) * size + 1);
    if (!word)
    {
        printf("\n Allocation error.");
        return NULL;
    }
    for (int i = 0; i < size; i++)
        word[i] = fgetc(fp);
    word[size] = '\0';

    return word;
}

int is_ch(char ch)
{
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}