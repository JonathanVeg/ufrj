// gcc vector.c -o vector -Wall && ./vector

#include "stdio.h"
#include "stdlib.h"
#define MAX 5

inline void print(int n, int ln){
	printf("%d", n);

	if (ln){
		printf("\n");
	}
}

int * vector;

int main(int argc, char const *argv[])
{
	int tam = MAX;

	vector = (int*)malloc(tam*sizeof(int));

	int i;

	for (i = 0; i < MAX; ++i)
		vector[i] = i;

	for (i = 0; i < MAX; ++i)
		print(vector[i], 1);

	return 0;
}