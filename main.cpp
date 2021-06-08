
#define _CRT_SECURE_NO_WARNINGS
#include "Lab10.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
	char* filename = (char*)malloc(sizeof(char) * 32);
	if (filename == 0 || !scanf("%s", filename))
	{
		printf("\n Incorrect filename input");
		return -1;
	}

	char** str = parser(filename);

	printf("\n Contents of .txt file:");
	for (int i = 0; str[i] != NULL; i++) {
		printf("\n\t%d) ", i+1);
		for (int j = 0; is_ch(str[i][j]); j++) {
			printf("%c", str[i][j]);
		}
	}
	return 0;
}