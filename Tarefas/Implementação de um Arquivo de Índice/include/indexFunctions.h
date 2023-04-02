#ifndef __INDEX_FUNCIONS_H__
#define __INDEX_FUNCIONS_H__
#include <stdio.h>

int comparaCEP(const void *i1, const void *i2);
int arquivoExiste(char* name);
FILE* criaArquivoIndex(FILE *origin);
int ordenaArquivo(FILE *f);

#endif