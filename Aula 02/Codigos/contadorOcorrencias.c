#include <stdio.h>
#define T 256

int ehLetra(char c){
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)){
        return 1;
    }else{
        return 0;
    }
}

void contaOcorrencias(int *v, FILE *f){
    char c;
    c = fgetc(f);
    while (c != EOF)
    {
        v[c] = v[c]+1;
        c = fgetc(f);
    }
}

void mostraOcorrencias(int v[]){
    for(int i=0;i<=T;i++){
        if (ehLetra(i)){
            printf("%c : %d\n", i, v[i]);
        }
    }
}

int main(int argc, char **argv)
{

    FILE *Arq;
    int ocorrencias[T] = {0};

    if(argc != 2){
        fprintf(stderr, "Deve ser informado apenas o arquivo a ser contado as ocorrencias de bytes\n");
        fprintf(stderr, "%s [Arquivo de entrada.txt]\n", argv[0]);
        return -1;
    }else{
        Arq = fopen(argv[1], "rb");
        if(!Arq){
            fprintf(stderr, "Falha ao abrir arquivo tente novamente\n");
            return -1;
        }else{
            contaOcorrencias(ocorrencias , Arq);
            mostraOcorrencias(ocorrencias);
        }
    }

    fclose(Arq);

    return 0;
}
