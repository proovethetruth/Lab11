
#define _CRT_SECURE_NO_WARNINGS
#include "Lab10.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
	char* filename = (char*)malloc(sizeof(char) * 10);

	printf("\n Input filename: ");
	if (filename == 0 || !scanf("%s", filename))
	{
		printf("\n Incorrect filename input");
		return -1;
	}

	char** str = parser(filename);
	for (int i = 0; str[i] != NULL; i++)
	{
		printf("\n %d. ", i+1);
		for (int j = 0; str[i][j] != '\0'; j++)
			printf("%c", str[i][j]);
	}
	return 0;
}