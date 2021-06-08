
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

	vector_t str;
	parse(&str, filename);
	print_vector(&str);
	destroy(&str);
	return 0;
}