#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void selection_sort(int list[], int tam) 
{ 
	int i;
	int j;
	int less;
	int aux;

	for (i = 0; i < (tam-1); i++) 
	{
		less = i;
		for (j = (i+1); j < tam; j++) {
			if(list[j] < list[less]) {
				less = j;
			}
		}
		if (i != less) {
			aux = list[i];
			list[i] = list[less];
			list[less] = aux;
		}
	}
}

void merge(int list[], int tam) {
	int center;
	int i, j, k;
	int* aux;

	aux = (int*) malloc(tam * sizeof(int));
	if (aux == NULL) {
		exit(1);
	}

	center = tam / 2;

	i = 0;
	j = center;
	k = 0;
	while (i < center && j < tam) {
		if (list[i] < list[j]) {
			aux[k] = list[i++];
		}
		else {
			aux[k] = list[j++];
		}
		++k;
	}

	if (i == center) {
		while (j < tam) {
			aux[k++] = list[j++];
		}
	}
	else {
		while (i < center) {
			aux[k++] = list[i++];

		}
	}

	for (i = 0; i < tam; ++i) {
		list[i] = aux[i];
	}

	free(aux);
}

void merge_sort(int list[], int tam) {
	int center;

	if (tam > 1) {
		center = tam / 2;
		merge_sort(list, center);
		merge_sort(list + center, tam - center);
		merge(list, tam);
	}
}

int main(int argc, char *argv[])
{
	int input,n;
	int count = 0;
	int* list = NULL;
	int reading = 1;
	while (reading != EOF){
		reading = scanf ("%d", &input);
		count++;

		list = (int*) realloc (list, count * sizeof(int));

		if (list!=NULL) {
			list=list;
			list[count-1]=input;
		}
		else {
			free (list);
			puts ("Erro ao realocar a memória");
			exit (1);
		}
	}
	
	if ((argc == 2) && (strcmp(argv[1],"-m") == 0)){
		printf("Ordenando por merge\n");
		merge_sort(list, count-1);
	}
	else{
		printf("Ordenando por selection\n");
		selection_sort(list, count-1);
	}

	// por algum motivo ele meio que replica o último número no final da lista, por isso tiro ele.

	for (n=0;n<count-1;n++)
		printf ("%d ",list[n]);
	printf("\n");

	free (list);


	return 0;
}