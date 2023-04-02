#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structs.h"

int comparaCEP(const void *i1, const void *i2)
{
    return strncmp(((Indice *)i1)->cep, ((Indice *)i2)->cep, 8);
}

int arquivoExiste(char* name){
    FILE *f;
    f = fopen(name, "rb");
    if(f){
        return 1;
    }else{
        return 0;
    }
}

void criaArquivoIndex(FILE *origin, FILE *indexFile){
    Endereco e;
    Indice cepIndex;
    int cont = 0;

    origin = fopen("cep.dat", "rb");
    indexFile = fopen("cepIndex.dat", "wb");

    while (!feof(origin))
    {
        fread(&e, sizeof(Endereco), 1, origin);
        
        strncpy(cepIndex.cep, e.cep, 8);
        cepIndex.indice = cont;

        fwrite(&cepIndex, sizeof(Indice), 1, indexFile);
        
        cont++;
    }

    printf("Arquivo de indice criado com sucesso.");
    fclose(indexFile);
    fclose(origin);
}

void ordenaArquivo(FILE *f){
    int posicao, qt;
    Indice *i;

    f = fopen("cepIndex.dat", "rb");
    fseek(f, 0, SEEK_END);
    posicao = ftell(f);
    qt = posicao / sizeof(Indice);
    i = (Indice *)malloc(posicao);
    if (i == NULL)
    {
        fprintf(stderr, "Erro: Nao ao alocar memoria na ordenacao do arquivo de indice\n");
        fclose(f);
        return -1;
    }
    rewind(f);

    if (fread(i, sizeof(Indice), qt, f) == qt)
    {
        printf("Lido = OK\n");
    }
    fclose(f);

    qsort(i, qt, sizeof(Indice), comparaCEP);
    f = fopen("cepIndex.dat", "wb");
    fwrite(i, sizeof(Indice), qt, f);
    fclose(f);
}
