#ifndef __STRCUTS_H__
#define __STRUCTS_H__

typedef struct
{
    char logradouro[72];
    char bairro[72];
    char cidade[72];
    char uf[72];
    char sigla[2];
    char cep[8];
    char lixo[2];
} Endereco;

typedef struct
{
    char cep[8];
    int indice;
} Indice;

#endif