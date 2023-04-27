//Transformar arquivo de texto UNIX para arquivo de texto DOS

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
    char c;
    FILE *entrada;
    FILE *saida;
    
    entrada = fopen("loremipsum.txt", "rb");
    saida = fopen("loremipsum_dos.txt", "wb");

    c = fgetc(entrada);
    while (!feof(entrada))
    {
        if (c == '\n'){
            fputc('\r', saida);
        }
        fputc(c, saida);
        c = fgetc(entrada);
    }
    
    return 0;

}