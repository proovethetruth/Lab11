
#define _CRT_SECURE_NO_WARNINGS

#include "Lab10.h"
#include <stdio.h>
#include <malloc.h>
//
//char** parser(char* filename) {
//        FILE* fp;
//        fp = fopen(filename, "r");
//
//        char** str = (char**)calloc(N, sizeof(char*) * N);
//        if (!str)
//        {
//            printf("\n Allocation error");
//            return NULL;
//        }
//
//        for (int i = 0; !feof(fp); i++)
//        {
//            while (!is_ch(fgetc(fp)));
//            if (!feof(fp))
//                fseek(fp, -(int)sizeof(char), 1);
//
//            readWord(fp, str[i]);
//        }
//        return str;
//}
//
//int readWord(FILE* fp, char* str)
//{
//    int i = 0;
//    while (is_ch(fgetc(fp)))
//        i++;
//
//    if(!(str = (char*)malloc(sizeof(char) * i + 1)))
//        return -1;
//
//    int j = 0;
//    if (((fscanf(fp, "%c", &str[j])) != 1))
//        return -5;
//
//    while (is_ch(str[j]) && !feof(fp))
//    {
//        if (((fscanf(fp, "%c", &str[j])) != 1))
//            return -5;
//        j++;
//    }
//}

/* char** parser(char* filename) {
    FILE* fp;
    fp = fopen(filename, "r");

    char** str = (char**)calloc(N, sizeof(char*) * N);
    if (!str)
    {
        printf("\n Allocation error");
        return NULL;
    }

    char ch;
    int space = 0, words = 0;
    for (int i = 0; !feof(fp); i++)
    {
        ch = fgetc(fp);
        if (!is_ch(ch))
        {
            if (i != space)
            {
                if (!(str[words] = (char*)calloc(i - space, sizeof(char) * (i - space))))
                {
                    printf("\n Allocation error");
                    return NULL;
                }
                words++;
            }

            while (!is_ch(ch) && !feof(fp))
            {
                ch = fgetc(fp);
                i++;
            }
            if(!feof(fp))
                fseek(fp, -(int)sizeof(char), 1);
            i--;
            space = i;
        }
    }
    fseek(fp, 0, SEEK_SET);
    for (int i = 0; i < words; i++)
    {
        while (!is_ch(fgetc(fp)));
        if (!feof(fp))
            fseek(fp, -(int)sizeof(char), 1);

        int j = 0;
        do {
            if (((fscanf(fp, "%c", &str[i][j])) != 1))
                break;
            j++;
        } while (is_ch(str[i][j-1]) && !feof(fp));
    }
    return str;
}*/

char** parser(char* filename) {
    FILE* fp;
    fp = fopen(filename, "r");

    int capacity = 32;
    char** str = (char**)calloc(capacity, sizeof(char*) * capacity);
    if (!str)
    {
        printf("\n Allocation error");
        return NULL;
    }

    char ch;
    int space = 0, words = 0;
    for (int i = 0; !feof(fp); i++)
    {
        ch = fgetc(fp);
        if (!is_ch(ch))
        {
            if (i != space)
            {
                if (!(str[words] = (char*)calloc(i - space, sizeof(char) * (i - space))))
                {
                    printf("\n Allocation error");
                    return NULL;
                }
                words++;
            }

            while (!is_ch(ch) && !feof(fp))
            {
                ch = fgetc(fp);
                i++;
            }
            if(!feof(fp))
                fseek(fp, -(int)sizeof(char), 1);
            i--;
            space = i;
        }
    }
    fseek(fp, 0, SEEK_SET);
    for (int i = 0; i < words; i++)
    {
        while (!is_ch(fgetc(fp)));
        if (!feof(fp))
            fseek(fp, -(int)sizeof(char), 1);

        int j = 0;
        do {
            if (i > capacity + 1)
            {
                if (!(str = (char**)realloc(str, capacity + 50)))
                    return NULL;
                capacity += 50;
            }

            if (((fscanf(fp, "%c", &str[i][j])) != 1))
                break;
            j++;
        } while (is_ch(str[i][j-1]) && !feof(fp));
    }
    return str;
}

int is_ch(char ch)
{
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}