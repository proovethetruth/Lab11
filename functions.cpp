
#define _CRT_SECURE_NO_WARNINGS

#include "Lab10.h"
#include <stdio.h>
#include <malloc.h>

char** parser(char* filename) {
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

            while (!is_ch(ch))
            {
                ch = fgetc(fp);
                i++;
            }
            fseek(fp, -(int)sizeof(char), 1);
            i--;
            space = i;
        }
    }
    fseek(fp, 0, SEEK_SET);

    for (int i = 0; i < words; i++)
    {
        for (int j = 0; str[i][j]; j++)
        {
            if (((fscanf(fp, "%c", &str[i][j])) != 1))
                break;
        }
    }
    return str;
}

int is_ch(char ch)
{
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}