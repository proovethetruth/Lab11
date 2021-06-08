
#define _CRT_SECURE_NO_WARNINGS

#include "Lab10.h"
#include <stdlib.h>
#include <string.h>

void init_vector(vector_t* v) {
    v->arr = (char**)calloc(2, sizeof(char) * 2);
    v->size = 0;
    v->capacity = 2;
}

void destroy(vector_t* v) {
    for (int i = 0; i < (int)v->size; i++)
    {
        if (v->arr[i] != NULL)
            free(v->arr[i]);
    }
    v->size = 0;
}

void push_back(vector_t* str, char* word) {
    char** tmp = NULL;
    if (str->size == str->capacity)
    {
        str->capacity *= 2;
        tmp = (char**)calloc(str->capacity, str->capacity * sizeof(char));
        if (!tmp)
        {
            printf("\n\a ERROR: Can't allocate enough memory");
            return;
        }
        for (int i = 0; i < (int)str->size; i++)
        {
            tmp[i] = str->arr[i];
        }
        str->arr = tmp;
    }
    //for (int i = 0; i < (int)str->size; i++)
    //{
    //    if (strcmp(str->arr[i], word) == 0)
    //        return;
    //}
    str->arr[str->size] = word;
    str->size++;
}

void print_vector(vector_t* str)
{
    if (str->size == 0)
        return;
    for (int i = 0; i < (int)str->size; i++)
        printf("\n %d. %s", i + 1, str->arr[i]);
}

int parse(vector_t* str, char* filename) {
    FILE* fp;
    if (!(fp = fopen(filename, "r")))
        return 0;

    init_vector(str);

    char* word;
    while ((word = readWord(fp)) != NULL)
        push_back(str, word);
    return 1;
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

void get_most_common(char** arr, size_t size)
{
    int count = 0, maxCount = 0, index = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (strcmp(arr[i], arr[j]) == 0)
                count++;
        }
        if (count > maxCount)
        {
            maxCount = count;
            index = i;
        }
        count = 0;
    }
    if (maxCount > 0)
        printf("\n Most repeated word is: \"%s\" (seen %d times)", arr[index], maxCount);
    else
        printf(" File is empty");
}

void quicksort(char** arr, unsigned int length) {
    unsigned int i, piv = 0;
    if (length <= 1)
        return;

    for (i = 0; i < length; i++) {
        if (strcmp(arr[i], arr[length - 1]) < 0)
            swap(arr + i, arr + piv++);
    }
    swap(arr + piv, arr + length - 1);

    quicksort(arr, piv++);
    quicksort(arr + piv, length - piv);
}

void swap(char** a, char** b) {
    char* temp = *a;
    *a = *b;
    *b = temp;
}

int is_ch(char ch)
{
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}