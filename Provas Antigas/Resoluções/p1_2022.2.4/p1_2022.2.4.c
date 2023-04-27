//Conta quantos logreadouros existem por Sigla
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char logradouro[72];
	char bairro[72];
	char cidade[72];
	char uf[72];
	char sigla[2];
	char cep[8];
	char lixo[2];
} Endereco;

int main(int argc, char const *argv[])
{
	FILE * f;
	int qnt = 0;
	Endereco prev, curr; 

	f = fopen("cep_ordenado2.dat", "rb");
	fread(&prev, sizeof(Endereco), 1, f);
	fread(&curr, sizeof(Endereco), 1, f);
	while (!feof(f))
	{
		if(strncmp(curr.sigla, prev.sigla, 2) == 0){
			qnt += 1;
		}else if(strncmp(curr.sigla, prev.sigla, 2) != 0){
			printf("%.2s: %d\n", prev.sigla, qnt+1);
			qnt = 0;
			
		}
		prev = curr;
		fread(&curr, sizeof(Endereco), 1, f);
	}
	printf("%.2s: %d\n", prev.sigla, qnt+1);

	return 0;
}

