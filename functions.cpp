
#define _CRT_SECURE_NO_WARNINGS

#include "Lab10.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

char** parser(char* filename) {
    FILE* fp;
    if (!(fp = fopen(filename, "r")))
        return NULL;

    int amount = count_words(fp);

    char** str = (char**)calloc(amount, sizeof(char) * amount + 1);
    if (!str)
    {
        printf("\n Allocation Error.");
        return NULL;
    }
    str[amount] = NULL;

    for (int i = 0; i < amount; i++)
        str[i] = readWord(fp);

    quicksort(str, amount);
    return str;
}

void swap(char** a, char** b) {
    char* temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(char** str, int length) {
    unsigned int i, piv = 0;
    if (length <= 1)
        return;

    for (i = 0; i < length; i++) {
        // if curr str < pivot str, move curr into lower array and  lower++(pvt)
        if (strcmp(str[i], str[length - 1]) < 0) 	//use string in last index as pivot
            swap(str + i, str + piv++);
    }
    //move pivot to "middle"
    swap(str + piv, str + length - 1);

    //recursively sort upper and lower
    quicksort(str, piv++);			//set length to current pvt and increase for next call
    quicksort(str + piv, length - piv);
}

int count_words(FILE* fp) {
    int count = 0;
    char ch = 'a';

    while (1)
    {
        if ((ch = fgetc(fp)) == EOF || !ch)
            break;

        if (!is_ch(ch))
        {
            count++;
            while (!is_ch(ch))
            {
                ch = fgetc(fp);
                if (ch == EOF || !ch)
                    break;
            }
            fseek(fp, -(int)sizeof(char), 1);
        }

    }

    count++;

    fseek(fp, 0, SEEK_SET);
    return count;
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