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
} endereco;

int main(){
    FILE *fa = fopen("cep_a.dat", "rb");
    FILE *fb = fopen("cep_b.dat", "rb");
    FILE *fc = fopen("cep_saida.dat", "wb");

    endereco ea, eb;
    fread(&ea, sizeof(endereco), 1, fa);
    fread(&eb, sizeof(endereco), 1, fb);

    while(!feof(fa) && !feof(fb)){
        if (strncmp(ea.cep, eb.cep, 8)< 0){
            fwrite(&ea, sizeof(endereco), 1, fc);
            fread(&ea, sizeof(endereco), 1, fa);
        } else {
            fwrite(&eb, sizeof(endereco), 1, fc);
            fread(&eb, sizeof(endereco), 1, fb);
        }
    }

    while(!feof(fa)){
        fwrite(&ea, sizeof(endereco), 1, fc);
        fread(&ea, sizeof(endereco), 1, fa);
    }

    while(!feof(fb)){
        fwrite(&eb, sizeof(endereco), 1, fc);
        fread(&eb, sizeof(endereco), 1, fb);
    }

    fclose(fa);
    fclose(fb);
    fclose(fc);
    return 0;
}