/*
Implementar um programa que gerencia uma lista encadeada ordenada com alocação dinâmica.

Cada elemento da lista deve conter um número inteiro.

Os elementos devem ser inseridos em ordem crescente. Por exemplo, de for inserida a sequência 5, 3, 9, 4, ao imprimir o conteúdo da lista, 
deve aparecer 3, 4, 5, 9.

O programa deve oferecer ao usuário as operações:

- Inserir elemento na lista;

- Retirar elemento da lista;

- Buscar um elemento informado está na lista, retornando o endereço do elemento se ele existir na lista, ou NULL se não existir;

- Imprimir o conteúdo da lista;

- Contar o número de elementos da lista.
*/
#include<stdio.h>
#include<stdlib.h>

struct elemento {
   int dado;				// Conteúdo (inteiro)
   struct elemento *prox;	// Ponteiro para o próximo registro
};

typedef struct elemento *Lista;

Lista criaLista()
{
	return NULL;
}

void menu(){
    char op;
    do{
        printf("|*******************************************************|\n");
        printf("|                                                       |\n");
        printf("|           IFPR - Estrutura de Dados  2022             |\n");
        printf("|             Lista Encadeada Ordenada - C              |\n");
        printf("|                                                       |\n");
        printf("|               1 - Inserir elemento:                   |\n");
        printf("|               2 - Remover elemento:                   |\n");
        printf("|               3 - Buscar um elemento:                 |\n");
        printf("|               4 - Imprimir elementos:                 |\n");
        printf("|               5 - Numero de elementos:                |\n");
        printf("|               0 - Sair                                |\n");
        printf("|                                                       |\n");
        printf("|*******************************************************|\n");
    } while (op != 0);
    
}