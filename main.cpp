
#define _CRT_SECURE_NO_WARNINGS
#include "Lab10.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
	//char* filename = (char*)malloc(sizeof(char) * 10);
	//if (filename == 0 || !scanf("%s", filename))
	//{
	//	printf("\n Incorrect filename input");
	//	return -1;
	//}

	/*char** str = parser(filename);

	printf("\n Contents of .txt file:");
	for (int i = 0; str[i] != NULL; i++) {
		printf("\n\t%d) ", i+1);
		for (int j = 0; is_ch(str[i][j]); j++) {
			printf("%c", str[i][j]);
		}
	}*/
	FILE* fp = fopen("test.txt", "r");
	char* word;

	while ((word = readWord(fp)) != NULL)
	{
		for (int i = 0; word[i] != '\0'; i++)
			printf("%c", word[i]);
		printf(" ");
	}		
	//word = readWord(fp);

	//for (int i = 0; i < 10; i++)
	//	printf("%c", word[i]);

	//printf("... ");

	//word = readWord(fp);

	//for (int i = 0; i < 10; i++)
	//	printf("%c", word[i]);
	return 0;
}