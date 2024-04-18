#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

typedef struct
{
    char cep[8];
    int indice;
} Indice;


int main(int argc, char **argv[])
{
    FILE *origem, *destino;
    Endereco e;
    Indice cepIndice;
    int qt, cont = 0;

    //Cria o arquivo indice
    origem = fopen("cep.dat", "rb");
    destino = fopen("cep_index.dat", "wb");
    qt = fread(&e, sizeof(Endereco), 1, origem);
    while (qt > 0)
    {
        strncpy(cepIndice.cep, e.cep, 8);
        cepIndice.indice = cont;

        fwrite(&cepIndice, sizeof(Indice), 1, destino);
        qt = fread(&e, sizeof(Endereco), 1, origem);
        cont++;
    }
    
    fclose(origem);
    fclose(destino);
    //Leitura do arquivo indice para testes
    destino = fopen("cep_index.dat", "rb");
    qt = fread(&cepIndice, sizeof(Indice), 1, destino);
    while (qt > 0)
    {
        printf("Indice:%d CEP:%.8s\n", cepIndice.indice, cepIndice.cep);
        qt = fread(&cepIndice, sizeof(Indice), 1, destino);  
    }
    
    fclose(destino);
    return 0;
}
