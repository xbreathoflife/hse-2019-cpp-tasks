#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "mergesort.h"


int int_comparator(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int char_comparator(const void *a, const void *b) {
    return *(char*)a - *(char*)b;
}

int str_comparator(const void *a, const void *b) {
	return strcmp(*(const char**)a, *(const char**)b);
}

int main(int argc, char *argv[]) {
	int i;

	if (argc > 2) {
		if (!strcmp(argv[1], "int")) {
			int *array_int = malloc((argc - 2) * sizeof(int));
			assert(array_int != NULL);

			for (i = 0; i < argc - 2; i++)
				array_int[i] = atoi(argv[i + 2]);
			mergesort(array_int, argc - 2, sizeof(int), int_comparator);
			for (int i = 0; i < argc - 2; i++)
				printf("%i ", array_int[i]);
			free(array_int);  
		} else if (!strcmp(argv[1], "char")) {
			char *array_char = malloc((argc - 2) * sizeof(char));
			assert(array_char != NULL);

			for (i = 0; i < argc - 2; i++)
				array_char[i] = argv[i + 2][0];
			mergesort(array_char, argc - 2, sizeof(char), char_comparator);
			for (int i = 0; i < argc - 2; i++)
				printf("%c ", array_char[i]);
			free(array_char);
		} else {		
			mergesort(argv+2, argc - 2, sizeof(argv[2]), str_comparator);
			for (int i = 0; i < argc - 2; i++)
				printf("%s ", argv[i+2]);
		} 

	}
	return 0;
}
