#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "include/structs.h"
#include "include/searchFunctions.h"

int buscaBinaria(FILE *f, char *CEP)
{
	if (!f){
		fprintf(stderr, "Arquivo ERRO\n");
	}

	Indice i;
	int inicio, meio, fim = 0;

	fseek(f, 0, SEEK_END);
	fim = (ftell(f) / sizeof(Indice)) - 1;


	while (inicio <= fim)
	{
		meio = (inicio + fim) / 2;
		fseek(f, meio * sizeof(Indice), SEEK_SET);
		fread(&i, sizeof(Indice), 1, f);
		if (strncmp(CEP, i.cep, 8) == 0)
		{
			return i.indice;
		}
		else if (strcmp(CEP, i.cep) < 0)
		{
			fim = meio - 1;
		}
		else
		{
			inicio = meio + 1;
		}
	}
	return -1;
}
