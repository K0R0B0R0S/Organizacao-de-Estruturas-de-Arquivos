#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "include/structs.h"
#include "include/indexFunctions.h"

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

FILE* criaArquivoIndex(FILE *origin){
    Endereco e;
    Indice cepIndex;
    int cont = 0;

    FILE *indexFile = fopen("indexFile.dat", "wb");
    while (!feof(origin))
    {
        fread(&e, sizeof(Endereco), 1, origin);
        
        strncpy(cepIndex.cep, e.cep, 8);
        cepIndex.indice = cont;

        fwrite(&cepIndex, sizeof(Indice), 1, indexFile);
        
        cont++;
    }
    fclose(origin);

    printf("Arquivo de indice criado com sucesso.\n");
    fclose(indexFile);
    indexFile = fopen("indexFile.dat", "rb");
    return indexFile;
}

int ordenaArquivo(FILE *f){
    int posicao, qt;
    Indice *i;

    fseek(f, 0, SEEK_END);
    posicao = ftell(f);
    qt = posicao / sizeof(Indice);
    i = (Indice *)malloc(posicao);
    if (i == NULL)
    {
        fprintf(stderr, "Erro: Nao foi possivel alocar memoria para ordenação do arquivo de indice\n");
        fclose(f);
        return 0;
    }
    rewind(f);

    if (fread(i, sizeof(Indice), qt, f) != qt)
    {
        fprintf(stderr, "Erro ao ler dados do arquivo para ordenação\n");
        fclose(f);
        return 0;
    }
    fclose(f);

    qsort(i, qt, sizeof(Indice), comparaCEP);

    f = fopen("indexFile.dat", "w+b");
    fwrite(i, sizeof(Indice), qt, f);

    printf("Arquivo ordenado com sucesso\n");
    return 1;
}
