
#define _CRT_SECURE_NO_WARNINGS

#include "Lab10.h"
#include <stdio.h>
#include <malloc.h>

//char** parser(char* filename) {
//    FILE* fp;
//    if (!(fp = fopen(filename, "r")))
//        return NULL;
//
//    size_t size = 0, capacity = 32;
//    char** str = (char**)calloc(capacity, sizeof(char*) * capacity);
//    if (!str)
//    {
//        printf("\n Allocation error");
//        return NULL;
//    }
//
//    char ch;
//    int space = 0;
//    for (int i = 0; !feof(fp); i++)
//    {
//        ch = fgetc(fp);
//        if (!is_ch(ch))
//        {
//            if (i != space)
//            {
//                if (!(str[size] = (char*)calloc(i - space, sizeof(char) * (i - space))))
//                {
//                    printf("\n Allocation error");
//                    return NULL;
//                }
//                size++;
//            }
//
//            while (!is_ch(ch) && !feof(fp))
//            {
//                ch = fgetc(fp);
//                i++;
//            }
//            if (!feof(fp))
//                fseek(fp, -(int)sizeof(char), 1);
//            i--;
//            space = i;
//        }
//    }
//    fseek(fp, 0, SEEK_SET);
//
//    for (int i = 0; i < size; i++)
//    {
//        while (!is_ch(fgetc(fp)));
//        if (!feof(fp))
//            fseek(fp, -(int)sizeof(char), 1);
//
//        int j = 0;
//        do {
//            if (i > capacity + 1)
//            {
//                if (!(str = (char**)realloc(str, capacity + 50)))
//                    return NULL;
//                capacity += 50;
//            }
//
//            if (((fscanf(fp, "%c", &str[i][j])) != 1))
//                break;
//            j++;
//        } while (is_ch(str[i][j - 1]) && !feof(fp));
//    }
//
//    return str;
//}

char* readWord(FILE* fp) {
    char ch = fgetc(fp);
    while (!is_ch(ch))
    {
        ch = fgetc(fp);
    }


    int size = 1;
    while (is_ch(ch))
    {
        if ((ch = fgetc(fp)) == EOF || !ch)
            break;
        size++;
    }
    fseek(fp, -(size * (int)sizeof(char)), 1);

    char* word = (char*)calloc(size, sizeof(char) * size + 1);
    if (!word)
    {
        printf("\n Allocation error.");
        return NULL;
    }
    for (int i = 0; i < size; i++)
        word[i] = fgetc(fp);

    return word;
}

int is_ch(char ch)
{
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}