#include <stdio.h>
#include <stdbool.h>
#define MAX 20
#define INVALIDO -1

typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
}REGISTRO;

typedef struct{
    REGISTRO reg;
    int prox;
}ELEMENTO;

typedef struct{
    ELEMENTO l[MAX];
    int inicio;
    int disp;
}LISTA;