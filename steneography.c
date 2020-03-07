#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NDEBUG
//#undef NDEBUG

/*
	Program to modify bytes of a file
*/

typedef unsigned char byte;

int returnSize(FILE * ptr){
	fseek(ptr, 0L, SEEK_END);
	int size = ftell(ptr);
	rewind(ptr);
	return size;
}

void encryptString(char charArray[], int key){
	for(int i = 0; charArray[i] != '\0'; ++i){
		charArray[i] += key;
	}
}

int main(int argc, char * argv[]){

	const char * message = argv[1];
	char messageArray[strlen(argv[1]) + 1];
	strcpy(messageArray, message);
	encryptString(messageArray, 10);

	/* Get size of the file */
	FILE *fp = fopen("test.bin", "r+b");
	if(fp == NULL){
		printf("File does not exist\n");
		exit(EXIT_FAILURE);
	}

	if(argc < 2){
		printf("A commandline argument must be specified\n");
		exit(EXIT_FAILURE);
	}

	int size = returnSize(fp);
	int stringSize = strlen(argv[1]);
	srand(time(NULL));

#ifdef NDEBUG
	printf("Size of the file is : %d\n", size);
	printf("Commandline argument is : %s\n", argv[1]);
	printf("String size is : %d\n", stringSize);
#endif

	// int indexTable[stringSize];
	for(int i = 0; i < stringSize; ++i){
		int randomPos = rand() % size;
		// indexTable[i] = randomPos;
		fseek(fp, randomPos, SEEK_SET);
		fputc(messageArray[i], fp);
	}

	fclose(fp);

	return 0;
}