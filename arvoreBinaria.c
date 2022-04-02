/*Faça um programa que implemente uma árvore binária com alocação dinâmica, para armazenar números inteiros.
O usuário deve poder incluir quantos elementos desejar na árvore.
As opções permitidas para o usuário são:
1 - Inserir um elemento na árvore [x]
2 - Retirar um elemento da árvore
3 - Buscar um elemento na árvore, indicando como saída se o elemento existe ou não na árvore [x]
4 - Imprimir todos os elementos da árvore em pré-ordem
5 - Imprimir todos os elementos da árvore em ordem crescente
6 - Imprimir todos os elementos da árvore em pós-ordem
Deve ser postado o código fonte em C, compilável e funcionando, sem o uso de bibliotecas específicas de Windows.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elemento
{
    int dado;
    struct Elemento *esq;
    struct Elemento *dir;
};
typedef struct Elemento *Arvore;

Arvore criaArvore()
{
    // printf("Arvore Criada");
    return NULL;
}

void insereArvore(Arvore *a, int valor)
{
    // Busca da posição de inserção
    if ((*a) == NULL)
    {
        (*a) = (Arvore)malloc(sizeof(struct Elemento));
        (*a)->dado = valor;
        (*a)->esq = NULL;
        (*a)->dir = NULL;
    }
    else if (valor < (*a)->dado)
        insereArvore(&((*a)->esq), valor); // insere a esquerda
    else if (valor > (*a)->dado)           // insere a direita
        insereArvore(&((*a)->dir), valor);
    else
    {
        system("cls || clear");
        printf("|************************************|\n");
        printf("| Valor ja existe... tente outro.    |\n");
        printf("|************************************|\n");
    }
}

void removeArvore(Arvore *a, int num)
{
    Arvore aux;

    if (*a != NULL)
    {
        if (num > ((*a)->dado))
        {
            removeArvore(&((*a)->dir), num);
        }
        else if (num < ((*a)->dado))
        {
            removeArvore(&((*a)->esq), num);
        }
        else
        {
            if ((*a)->dir == NULL)
            {
                aux = (*a);
                *a = aux->esq;
                free(aux);
            }
            else if ((*a)->esq == NULL)
            {
                aux = (*a)->dir;
                free(*a);
                *a = aux;
            }
            else
            {
                antecessor(*a, &((*a)->esq));
            }
        }
    }
}

void antecessor(Arvore a, Arvore *x)
{
    Arvore aux;

    if ((*x)->dir != NULL)
    {
        antecessor(a, &((*x)->dir));
    }
    else
    {
        a->dado = (*x)->dado;
        aux = *x;
        *x = aux->esq;
        free(aux);
    }
}

Arvore buscaElementoArvore(Arvore a, int valor)
{
    if (a == NULL)
        return NULL;
    else if (valor < a->dado)
        return buscaElementoArvore(a->esq, valor);
    else if (valor > a->dado)
        return buscaElementoArvore(a->dir, valor);
    else
        return a;
}

void printPreOrdem(Arvore a)
{
    if (a != NULL)
    {
        printf("\n%d", a->dado);
        printPreOrdem(a->esq);
        printPreOrdem(a->dir);
    }
}

void printElementoCrescente(Arvore a)
{
    if (a != NULL)
    {
        printElementoCrescente(a->esq);
        printf("\n%d", a->dado);
        printElementoCrescente(a->dir);
    }
}

void printPosOrdem(Arvore a)
{
    if (a != NULL)
    {
        printPosOrdem(a->esq);
        printPosOrdem(a->dir);
        printf("\n%d", a->dado);
    }
}

int main()
{
    Arvore arvore;
    Arvore arvoreaux;
    arvore = criaArvore();
    int numero;
    int op;
    do
    {
        printf("|************************************************************|\n");
        printf("|                                                            |\n");
        printf("|               IFPR - Estrutura de Dados                    |\n");
        printf("|                 Árvore bináriaTarefa                       |\n");
        printf("|                                                            |\n");
        printf("|               1 - Inserir elemento:                        |\n");
        printf("|               2 - Retirar elemento:                        |\n");
        printf("|               3 - Buscar elemento:                         |\n");
        printf("|               4 - Imprimir elementos - Pré-ordem:          |\n");
        printf("|               5 - Imprimir elementos - Ordem Crescente:    |\n");
        printf("|               6 - Imprimir elementos - Pós-ordem:          |\n");
        printf("|               0 - Sair                                     |\n");
        printf("|                                                            |\n");
        printf("|************************************************************|\n");
        printf("Operação: ");

        scanf("%d", &op);
        setbuf(stdin, NULL);

        switch (op)
        {
        case 1:
        {
            system("cls || clear");
            printf("|**********************|\n");
            printf("| Inserir elemento.    |\n");
            printf("|**********************|\n");
            scanf("%d", &numero);
            insereArvore(&arvore, numero);
            break;
        }
        case 2:
        {
            system("cls || clear");
            printf("|**********************|\n");
            printf("| Retirar elemento.    |\n");
            printf("|**********************|\n");
            scanf("%d", &numero);
            removeArvore(&arvore, numero);
            break;
        }
        case 3:
        {

            system("cls || clear");
            printf("|**********************|\n");
            printf("| Buscar elemento.     |\n");
            printf("|**********************|\n");
            scanf("%d", &numero);
            arvoreaux = buscaElementoArvore(arvore, numero);
            if (arvoreaux == NULL)
            {
                printf("|**********************************|\n");
                printf("| O numero %d, não foi encontrado. |\n", numero);
                printf("|**********************************|\n");
            }
            else
            {
                printf("|******************************|\n");
                printf("| O numero %d, foi encontrado. |\n", numero);
                printf("|******************************|\n");
            }

            break;
        }
        case 4:
        {
            system("cls || clear");
            printf("|************************************|\n");
            printf("| Imprimir elementos - Pré-ordem     |\n");
            printf("|************************************|\n");
            printPreOrdem(arvore);
            break;
        }
        case 5:
        {
            system("cls || clear");
            printf("|******************************************|\n");
            printf("| Imprimir elementos - Ordem Crescente     |\n");
            printf("|******************************************|\n");
            printElementoCrescente(arvore);
            break;
        }
        case 6:
        {
            system("cls || clear");
            printf("|************************************|\n");
            printf("| Imprimir elementos - Pós-ordem     |\n");
            printf("|************************************|\n");
            printPosOrdem(arvore);
            break;
        }
        default:
            system("cls || clear");
            printf("|***********************************|\n");
            printf("| Opção Invalida, tente novamente.  |\n");
            printf("|***********************************|\n");
            break;
        }
    } while (op != 0);

    return 0;
}