#include <stdio.h>

int contarLinhas(FILE *f){
    int qntLinhas = 0;
    char c;

    c = fgetc(f);
    while (c != EOF)
    {
        if (c == '\n'){
            qntLinhas++;
        }
        c = fgetc(f);
    }
    return qntLinhas+1;
}


int main(int argc, char **argv)
{

    FILE *Arq;

    if(argc != 2){
        fprintf(stderr, "Deve ser informado o arquivo a ser contado o numero de linhas\n");
        fprintf(stderr, "%s [Arquivo de entrada.txt]\n", argv[0]);
        return -1;
    }else{
        Arq = fopen(argv[1], "r");
        if(!Arq){
            fprintf(stderr, "Falha ao abrir arquivo tente novamente\n");
            return -1;
        }else{
            fprintf(stdout, "O arquivo [%s] possui %d linhas.", argv[1], contarLinhas(Arq));
        }
    }

    return 0;
}
