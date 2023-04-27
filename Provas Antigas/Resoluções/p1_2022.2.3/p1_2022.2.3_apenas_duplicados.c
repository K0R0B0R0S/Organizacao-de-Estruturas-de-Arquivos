//Contar quando candidatos se inscreveram no mesmo concurso em anos diferentes
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


int main(int argc, char *argv[])
{
    FILE *entrada2021, *entrada2022;
    FILE *saida;

    Endereco e2021, e2022;

    entrada2021 = fopen("cep_a.dat", "rb");
    entrada2022 = fopen("cep_a2.dat", "rb");
    saida = fopen("duplicados.dat", "wb");

    fread(&e2021, sizeof(Endereco), 1, entrada2021);
    fread(&e2022, sizeof(Endereco), 1, entrada2022);
    while (!feof(entrada2021) && !feof(entrada2022))
    {
        if(strncmp(e2021.cep, e2022.cep, 8) == 0){
            fwrite(&e2021, sizeof(Endereco), 1, saida);
            fread(&e2021, sizeof(Endereco), 1, entrada2021);
            fread(&e2022, sizeof(Endereco), 1, entrada2022);
        }else if(strncmp(e2021.cep, e2022.cep, 8) < 0){
            fread(&e2021, sizeof(Endereco), 1, entrada2021);
        }else{
            fread(&e2022, sizeof(Endereco), 1, entrada2022);
        }
    }
    

    
    Endereco e;



    return 0;
}
