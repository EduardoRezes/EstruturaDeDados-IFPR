/* Faça um programa que implemente uma fila com alocação dinâmica, para armazenar números inteiros.
O usuário deve poder incluir quantos elementos desejar na fila.
As opções permitidas para o usuário são:
1 - Inserir um elemento no final da fila [x]
2 - Retirar um elemento do início da fila [x]
3 - Imprimir o conteúdo da fila. [x]
Deve ser postado o código fonte em C, compilável e funcionando, sem o uso de bibliotecas específicas de Windows.
*/
#include <stdio.h>
#include <stdlib.h>

#pragma region Definições

#define TRUE 1
#define FALSE 0

#pragma endregion

#pragma region Declaração da estrutura Fila
struct elemento
{
    int dado;              // Conteúdo (inteiro)
    struct elemento *prox; // Ponteiro para o próximo registro
};

typedef struct elemento *ApElemento;

typedef struct
{
    ApElemento ini;
    ApElemento fim;
} Fila;
#pragma endregion

#pragma region Cria a Fila
Fila criaFila()
{
    Fila f;
    f.ini = NULL;
    f.fim = NULL;
    return f;
    system("cls || clear");
    printf("|****************************************|\n");
    printf("| Fila criada com sucesso.               |\n");
    printf("|****************************************|\n");
}
#pragma endregion

#pragma region Verifica Fila se está vazia
int filaVazia(Fila f)
{
    if (f.ini == NULL)
        return TRUE;
    else
        return FALSE;
}
#pragma endregion

#pragma region Imprimir o conteúdo da fila
void imprimeFila(Fila f)
{
    if (!filaVazia(f))
    {
        ApElemento ap;
        system("cls || clear");
        printf("|****************************************|\n");
        printf("|            Itens da Lista              |\n");
        printf("|****************************************|\n");
        ap = f.ini;
        while (ap != NULL)
        {
            printf(" %d - ", ap->dado);
            ap = ap->prox;
        }
        printf("\n|****************************************|\n");
    }
    else
    {
        system("cls || clear");
        printf("|****************************************|\n");
        printf("| A fila está Vazia.                     |\n");
        printf("|****************************************|\n");
    }
}
#pragma endregion

#pragma region Inserir um elemento no final da fila
Fila insereFilaFinal(Fila f, int e)
{
    ApElemento novo;
    novo = malloc(sizeof(struct elemento));
    novo->dado = e;
    novo->prox = NULL;
    if (filaVazia(f))
    {
        f.ini = novo;
        f.fim = novo;
    }
    else
    {
        f.fim->prox = novo;
        f.fim = novo;
    }
    system("cls || clear");
    printf("     O elemento foi inserido com sucesso.    \n");
    return f;
}
#pragma endregion

#pragma region Retira um elemento do início da fila
Fila retiraFila(Fila f, int *e)
{
    ApElemento ap;
    if (!filaVazia(f))
    {
        *e = f.ini->dado;
        ap = f.ini;
        f.ini = f.ini->prox;
        free(ap);
        if (filaVazia(f))
            f.fim = NULL;
    }
    else
    {
        *e = -1;
        system("cls || clear");
        printf("|****************************************|\n");
        printf("| A fila está Vazia.                     |\n");
        printf("|****************************************|\n");
    }
    return f;
}
#pragma endregion

#pragma region Main Program
int main()
{
    Fila f;
    f = criaFila();
    int e;
    int op;
    int numeroInserido;
    do
    {
        printf("|****************************************|\n");
        printf("|                                        |\n");
        printf("|        IFPR - Estrutura de Dados       |\n");
        printf("|            Fila Dinamica - C           |\n");
        printf("|                                        |\n");
        printf("|     1 - Inserir elemento:              |\n");
        printf("|     2 - Retirar elemento:              |\n");
        printf("|     3 - Imprimir conteudo da fila:     |\n");
        printf("|     0 - Sair                           |\n");
        printf("|                                        |\n");
        printf("|****************************************|\n");
        printf("Operação: ");

        scanf("%d", &op);
        setbuf(stdin, NULL);

        switch (op)
        {
        case 1:
            system("cls || clear");
            printf("|****************************************|\n");
            printf("|            Inserir elemento            |\n");
            printf("|****************************************|\n");
            printf("Elemento inteiro a ser inserido: ");
            scanf("%d", &numeroInserido);
            f = insereFilaFinal(f, numeroInserido);
            break;
        case 2:
            system("cls || clear");
            printf("|****************************************|\n");
            printf("|            Retirar elemento            |\n");
            printf("|****************************************|\n");
            f = retiraFila(f, &e);
            break;
        case 3:
            system("cls || clear");
            printf("|****************************************|\n");
            printf("|            Imprimir conteudo           |\n");
            printf("|****************************************|\n");
            imprimeFila(f);
            break;
        default:
            system("cls || clear");
            printf("|****************************************|\n");
            printf("| Opção Invalida, tente novamente.       |\n");
            printf("|****************************************|\n");
            break;
        }
    } while (op != 0);
    return 0;
};
#pragma endregion