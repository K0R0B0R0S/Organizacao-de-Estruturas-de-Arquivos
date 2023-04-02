#include <stdio.h>
#include "indexFunctions.h"
#include "searchFunctions.h"
#include "structs.h"


#define input "cep.dat"

void imprimeEnderecoNoIndice(int index)
{
	FILE *f = fopen(input, "rb");
	Endereco e;
	fseek(f, index * sizeof(Endereco), SEEK_SET);
	fread(&e, sizeof(Endereco), 1, f);
	printf("%.72s\n%.72s\n%.72s\n%.72s\n%.2s\n%.8s\n", e.logradouro, e.bairro, e.cidade, e.uf, e.sigla, e.cep);
}

int main(int argc, char **argv)
{

    int indexCEP;

    FILE *f = fopen(input, "rb");
	FILE *index;
	if(!arquivoExiste("indexFile.dat")){
		index = criaArquivoIndex(f);
		ordenaArquivo(index);
	}else{
		index = fopen("indexFile.dat", "rb");
	}
	
	printf("");
    indexCEP = buscaBinaria(index, argv[1]);
	if (indexCEP != -1)
	{
		printf("CEP Encontrado\n");
		imprimeEnderecoNoIndice(indexCEP);
	}
	else{
		printf("CEP nao encontrado\n");
	}
	fclose(index);
	fclose(f);
    return 0;
}
