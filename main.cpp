
#define _CRT_SECURE_NO_WARNINGS

#include "Lab10.h"
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
	if (!parse(&str, filename))
		return -1;

	quicksort(str.arr, str.size);
	print_vector(&str);

	printf("\n");
	get_most_common(str.arr, str.size);
	destroy(&str);
	return 0;
}