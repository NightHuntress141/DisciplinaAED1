#include <stdio.h>
#include <stdbool.h>

#define MAX 10

typedef int TIPOCHAVE;

//Criação do registro
typedef struct{
    TIPOCHAVE chave;
}REGISTRO;

//Criação da lista e seu número de elementos
typedef struct{
    REGISTRO l[MAX];
    int nElem;
}LISTA;

/*Esta função recebe o valor da lista1 
e devolve o valor do número de elementos (nElem) da lista*/
int InicializarLista (LISTA *lista1){
    //Iniciamos com o número de elementos igual a zero
    lista1 -> nElem = 0;
    return(lista1 -> nElem);
}

/*Esta função recebe o valor da lista1 
e não devolve nenhuma valor*/
void ExibirLista (LISTA *lista1){
    int i;
    for (i = 0; i < lista1 -> nElem; i++){
        printf("%i \n", lista1 -> l[i].chave);
    }
    return 0;
}

/*Esta função recebe o valor da lista1 e da chave que se deseja procurar 
e devolve o valor da posição na lista*/
int BuscaSequencial (LISTA *lista1, int ch){
    int i;
    for (i = 0; i < lista1 -> nElem; i++){
        if (ch == lista1 -> l[i].chave){
            return i;
        }
        else{
            continue;
        }
    }
}

/*Esta função recebe o valor da lista e da nova chave que se deseja inserir 
e devolve ou um erro por estar cheia (-1) ou uma operação bem sucedida (0)*/
int InserirFinal (LISTA *lista1, REGISTRO *ch_nova){
    if (lista1 -> nElem == MAX){
        return -1;
    }
    lista1 -> l[lista1 -> nElem] = *ch_nova;
    lista1 -> nElem++;
    return 0;
}

/*Esta função recebe o valor da lista, da nova chave que se deseja inserir e sua posição
e devolve ou algum tipo de erro (-1, 2, 3) ou uma operação bem sucedida (0)*/
int InserirEmX (LISTA *lista1, REGISTRO *ch_nova, int *p){
    int j;
    if (lista1 -> nElem == MAX){
        return -1;
    }
    else if (*p < 0){
        return 2;
    }
    else if (*p > lista1 -> nElem){
        return 3;
    }
    
    for (j = lista1 -> nElem; j > *p; j--){
        lista1 -> l[j] = lista1 -> l[j - 1];
    }

    lista1 -> l[*p] = *ch_nova;
    lista1 -> nElem++;
    return 0;
}

/*Esta função recebe o valor da lista e da nova chave que se deseja inserir 
e devolve ou um erro por estar cheia (-1) ou uma operação bem sucedida (0)*/
int InserirInicio (LISTA *lista1, REGISTRO *ch_nova){
    if (lista1 -> nElem == MAX){
        return -1;
    }

    int j;
    for (j = lista1 -> nElem; j > 0; j--){
        lista1 -> l[j] = lista1 -> l[j - 1];
    }
    lista1 -> l[0] = *ch_nova;
    lista1 -> nElem++;
    return 0;

}

/*Esta função recebe o valor da lista e da chave que se deseja excluir 
e devolve ou um valor que indica que a chave não existe na lista (-1) ou uma operação bem sucedida de exclusão (0)*/
int ExcluirElemento (LISTA *lista1, int *excluir_chave){
    int p, j;
    p = BuscaSequencial(&lista1, &excluir_chave);

    if (p == -1){
        return -1;
    }

    for (j = p; j < lista1 -> nElem; j++){
        lista1 -> l[j] = lista1 -> l[j + 1];
    }

    lista1 -> nElem++;
    return 0;
}

/*Esta função recebe o valor da lista
e devolve o valor do número de elementos (nElem) igual a 0*/
void ReinicializarLista(LISTA *lista1){
    lista1 -> nElem = 0;
}

int main(){
    LISTA lista1;
    
    int nElem = InicializarLista(&lista1);
    
    ExibirLista(&lista1);
    
    int ch_buscada;
    int posição_busca_sequencial;
    printf("Insira o valor que deseja ser buscado: ");
    scanf("%i \n", &ch_buscada);
    posição_busca_sequencial = BuscaSequencial(&lista1, &ch_buscada);
    printf("Tal valor se encontra na posição: %i \n", posição_busca_sequencial);

    REGISTRO novo_reg1;
    int resultado_inserir_final;
    printf("Insira o valor que se deseja adicionar no final da lista: ");
    scanf("%i \n", &novo_reg1.chave);
    resultado_inserir_final = InserirFinal(&lista1, &novo_reg1.chave);
    //Como evitar que o programa fique repetidamente perguntando?
    do{
        if (resultado_inserir_final == -1){
            printf("Não foi possivel inserir, pois a lista se encontra cheia! \n");
        }
        else{
            printf("Inserção bem sucedida! \n");
        }
    }while(false);

    REGISTRO novo_reg2;
    int posicao_chave;
    int resultado_inserir_em_X;
    printf("Insira o Valor que se deseja ser adicionado na lista: ");
    scanf("%i \n", &novo_reg2.chave);
    printf("Insira a posição que se deseja colocar o valor [0-%i]: ", MAX);
    scanf("%i \n", &posicao_chave);
    resultado_inserir_em_X = InserirEmX(&lista1, &novo_reg2.chave, &posicao_chave);
    do{
        if (resultado_inserir_em_X == -1){
            printf("Não foi possível inserir, pois a lista se encontra cheia! \n");
        }
        else if (resultado_inserir_em_X == 2){
            printf("Não foi possível inserir, pois a posição sugerida é menor que o intervalo \n");
        }
        else if (resultado_inserir_em_X == 3){
            printf("Não foi possível inserir, pois a posição sugerida é maior que o intervalo \n");
        }
        else{
            printf("Inserção bem sucedida! \n");
        }
    }while(false);

    REGISTRO novo_reg3;
    int resultado_inserir_inicio;
    printf("Insira o valor que se deseja adicionar no final da lista: ");
    scanf("%i \n", &novo_reg3.chave);
    resultado_inserir_inicio = InserirInicio(&lista1, &novo_reg3.chave);
    do{
        if (resultado_inserir_inicio == -1){
            printf("Não foi possivel inserir, pois a lista se encontra cheia! \n");
        }
        else{
            printf("Inserção bem sucedida! \n");
        }
    }while(false);

    REGISTRO excluir_reg1;
    int resultado_excluir;
    printf("Insira o valor que deseja deletar da lista: ");
    scanf("%i \n", &excluir_reg1);
    resultado_excluir = ExcluirElemento(&lista1, &excluir_reg1);
    do{
        if (resultado_excluir == -1){
            printf("Não foi possivel deletar, pois o valor não se encontra na lista! \n");
        }
        else{
            printf("Exclusão bem sucedida! \n");
        }
    }while(false);

    ReinicializarLista(&lista1);


}