
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

	vector_t* str;
	str = parser(filename);
	for (int i = 0; i < str->size; i++)
		printf("\n %d. %s", i + 1, str->arr[i]);
	return 0;
}