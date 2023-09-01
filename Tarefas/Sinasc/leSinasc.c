//Foi utilizado como base o arquivo leSinasc.c disponibilizado via Teams
//Integrantes do grupo:
//José Antônio de Souza Ferreira
//Gabriel Martins da Cruz Padrão
//Raphael Kenji da Rosa
//Natan B. de Andrade

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 2048


float totalPesoTeresina = 0;
float totalPesoCuritiba = 0;
int contadorTeresina = 0;
int contadorCuritiba = 0;
int ano_procurado = 2015;

int anoAtual = 2012;
int preCont = 0;

struct DadosNascimento
{
    int index;
    int CODMUNRES;
    char data_nasc[11];
    int PESO;
    int SEMAGESTAC;
    float adeq_peso_id_gestac;
    int SEXO;
    int IDANOMAL;
    int RACACOR;
    int ESCMAEAGR1;
    int ESTCIVMAE;
    int IDADEMAE;
    int CONSULTAS;
    int PARTO;
    int STTRABPART;
    int KOTELCHUCK;
    int APGAR5;
    int TPROBSON;
};

void separaData(char *data, int *dia, int *mes, int *ano)
{
    *ano = atoi(strtok(data, "-"));
    *mes = atoi(strtok(NULL, "-"));
    *dia = atoi(strtok(NULL, "-"));
}


void processa(struct DadosNascimento *dn)
{
    int dia, mes, ano;
    separaData(dn->data_nasc, &dia, &mes, &ano);

    if (dn->CODMUNRES == 330455 && dn->SEMAGESTAC <= 37)
    {
        if (anoAtual == ano)
        {
            preCont++;
        }
        else
        {
            printf("%d:%d\n", anoAtual, preCont);
            preCont = 1;
            anoAtual = ano;
        }
    }

    if (dn->CODMUNRES == 221100 && ano == ano_procurado)
    {
        totalPesoTeresina = totalPesoTeresina + dn->PESO;
        contadorTeresina++;
    }
    else if (dn->CODMUNRES == 410690 && ano == ano_procurado)
    {
        totalPesoCuritiba += dn->PESO;
        contadorCuritiba++;
    }

}

int main()
{
    char *prox = NULL;
    static char buffer[MAX];
    struct DadosNascimento dn;
    char *linha[18];
    int i;
    FILE *f = fopen("sinasc.csv", "r");
    fgets(buffer, MAX, f);
    fgets(buffer, MAX, f);
    printf("Prematuros nascidos no Rio de Janeiro por ano:");
    while (!feof(f))
    {
        linha[0] = strtok_r(buffer, ",\n", &prox);
        for (i = 1; i < 18; i++)
        {
            linha[i] = strtok_r(NULL, ",\n", &prox);
            if (linha[i] == NULL)
            {
                linha[i] = "";
            }
        }
        dn.index = atoi(linha[0]);
        dn.CODMUNRES = atoi(linha[1]);
        strcpy(dn.data_nasc, linha[2]);
        dn.PESO = atoi(linha[3]);
        dn.SEMAGESTAC = atoi(linha[4]);
        dn.adeq_peso_id_gestac = atof(linha[5]);
        dn.SEXO = atoi(linha[6]);
        dn.IDANOMAL = atoi(linha[7]);
        dn.RACACOR = atoi(linha[8]);
        dn.ESCMAEAGR1 = atoi(linha[9]);
        dn.ESTCIVMAE = atoi(linha[10]);
        dn.IDADEMAE = atoi(linha[11]);
        dn.CONSULTAS = atoi(linha[12]);
        dn.PARTO = atoi(linha[13]);
        dn.STTRABPART = atoi(linha[14]);
        dn.KOTELCHUCK = atoi(linha[15]);
        dn.APGAR5 = atoi(linha[16]);
        dn.TPROBSON = atoi(linha[17]);
        processa(&dn);
        fgets(buffer, MAX, f);
    }

    printf("%d:%d\n", anoAtual, preCont);
    printf("Peso Médio de 2015:\nCuritiba:%.2f\nTeresina:%.2f\n", (totalPesoCuritiba/contadorCuritiba)/1000, (totalPesoTeresina/contadorTeresina)/1000);
    
    fclose(f);
    return 0;
}