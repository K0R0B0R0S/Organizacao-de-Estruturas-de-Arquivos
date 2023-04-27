//Contar ocorrencias de byte em arquivo
#include <stdio.h>
#include <stdlib.h>

int main(){
    int ocorrencia[256] = {0};
    char c;
    FILE * entrada = fopen("loremipsum.txt", "rb");

    c = fgetc(entrada);
    while (!feof(entrada))
    {
        ocorrencia[c] = ocorrencia[c] + 1;
        c = fgetc(entrada);
    }

    for(int i=0;i<256;i++){
        printf("%c:%d\n", i, ocorrencia[i]);
    }
    
    printf("%c", c);

    return 0;
}