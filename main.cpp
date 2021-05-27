
#define _CRT_SECURE_NO_WARNINGS
#include "Lab10.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	char* filename = (char*)malloc(sizeof(char) * N);
	if (!scanf("%s", filename) || filename == 0)
	{
		printf("\n Incorrect filename input");
		return -1;
	}

	char** str = parser(filename);
	return 0;
}