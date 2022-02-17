/*Faça um programa que implemente uma pilha com alocação dinâmica, para armazenar números inteiros.
O usuário deve poder incluir quantos elementos desejar na pilha.
As opções permitidas para o usuário são:
1 - Empilhar um elemento (inserir na pilha) [x]
2 - Desempilhar um elemento (retirar o elemento do topo da pilha.) []
3 - Imprimir o conteúdo da pilha. [x]
Deve ser postado o código fonte em C, compilável e funcionando, sem o uso de bibliotecas específicas de Windows.*/
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

//definição da struct Pilha do tipo Inteiro
typedef struct elemento
{
    int dado;
    struct elemento *prox;
} *Pilha;

Pilha criaPilha() {
    return NULL;
};

int pilhaVazia(Pilha p)
{
    system("cls || clear");
    printf("|*******************************************************|\n");
    printf("|Por favor, aguarde enquanto estamos checando a Pilha.  |\n");
    printf("|*******************************************************|\n");
    if (p == NULL){
        return (TRUE);
    } else
    {
        return (FALSE);
    }
    
};

void imprimePilha(Pilha p)
{
    Pilha ap;
    ap = p;
    printf("|*******************************************************|\n");
    printf("|Itens da pilha:                                        |\n");
    while (ap != NULL)
    {
        printf("|%d - ", ap->dado);
        ap = ap->prox;
    }
    printf("\n|*******************************************************|\n");   
};

Pilha empilhaElemento(Pilha p, int e) 
{
    Pilha novo;
    novo = malloc(sizeof(struct elemento));
    novo->dado = e;
    novo->prox = p;
    return (novo);
}

Pilha desempilha(Pilha p, int *e)
{
    Pilha ap;
    
    if(!pilhaVazia(p))
    {
        *e = p->dado;
        ap = p;
        p = p->prox;
        free(ap);
    } else
    {
        *e = -1;
        system("cls || clear");
        printf("|*******************************************************|\n");
        printf("| A Pilha está vazia.                                   |\n");
        printf("|*******************************************************|\n");
    }
    return (p);
}

int main()
{
    Pilha p;
    p = criaPilha();
    int op;
    int *e;
    int numeroInserido;
    do
    {
        printf("|*******************************************************|\n");
        printf("|                                                       |\n");
        printf("|               IFPR - Estrutura de Dados               |\n");
        printf("|                 Pilha Dinamica - C                    |\n");
        printf("|                                                       |\n");
        printf("|               1 - Inserir elemento:                   |\n");
        printf("|               2 - Retirar elemento:                   |\n");
        printf("|               3 - Imprimir conteudo:                  |\n");
        printf("|               0 - Sair                                |\n");
        printf("|                                                       |\n");
        printf("|*******************************************************|\n");
        printf("Operação: ");

        scanf("%d", &op);
        setbuf(stdin, NULL);

        switch (op)
        {   
        case 1:
            system("cls || clear");
            printf("|*******************************************************|\n");
            printf("|                   Inserir elemento                    |\n");
            printf("|*******************************************************|\n");
            printf("Elemento inteiro a ser inserido: ");
            scanf("%d", &numeroInserido);
            p = empilhaElemento(p, numeroInserido);
            break;
        case 2:
            system("cls || clear");
            printf("|*******************************************************|\n");
            printf("|                   Retirar elemento                    |\n");
            printf("|*******************************************************|\n");
            p = desempilha(p, &e);

            break;
        case 3:
            system("cls || clear");
            printf("|*******************************************************|\n");
            printf("|                   Imprimir conteudo                   |\n");
            printf("|*******************************************************|\n");
            imprimePilha(p);
            break;
        default:
            system("cls || clear");
            printf("|*******************************************************|\n");
            printf("| Opção Invalida, tente novamente.                      |\n");
            printf("|*******************************************************|\n");
            break;
        }
    } while (op != 0);
    return 0;
};
