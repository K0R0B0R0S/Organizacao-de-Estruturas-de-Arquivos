#include <stdio.h>
#include <string.h>

/*
Integrantes:
José Antônio de Souza Ferreira
Natan Balthazar de Andrade
Gabriel Martins da Cruz Padrão
Raphael Kenji da Rosa
*/

typedef struct
{
	char logradouro[72];
	char bairro[72];
	char cidade[72];
	char uf[72];
	char sigla[2];
	char cep[8];
	char lixo[2];
} Endereco;

int main(int argc, char **argv)
{
	FILE *f;
	Endereco e;
	int c;
	int achei = 0;
	int inicio, meio, fim = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USO: %s [CEP]", argv[0]);
		return 1;
	}

	c = 0;
	printf("Tamanho da Estrutura: %ld\n\n", sizeof(Endereco));
	f = fopen("cep_ordenado.dat", "rb");
	fseek(f, 0, SEEK_END);
	fim = (ftell(f) / sizeof(Endereco)) - 1;

	while (inicio <= fim)
	{
		c++;
		meio = (inicio + fim) / 2;
		fseek(f, meio * sizeof(Endereco), SEEK_SET);
		fread(&e, sizeof(Endereco), 1, f);
		if (strncmp(argv[1], e.cep, 8) == 0)
		{
			printf("%.72s\n%.72s\n%.72s\n%.72s\n%.2s\n%.8s\n", e.logradouro, e.bairro, e.cidade, e.uf, e.sigla, e.cep);
			achei = 1;
			break;
		}
		else if (strcmp(argv[1], e.cep) < 0)
		{
			fim = meio - 1;
		}
		else
		{
			inicio = meio + 1;
		}
	}
	printf(achei ? "CEP Encontrado\n" : "CEP não Encontrado\n");
	printf("Total Lido: %d\n", c);
	fclose(f);
}
