/*Implementar um programa que gerencia uma lista encadeada ordenada com alocação dinâmica.
Cada elemento da lista deve conter um número inteiro.
Os elementos devem ser inseridos em ordem crescente. Por exemplo, de for inserida a sequência 5, 3, 9, 4, ao imprimir o conteúdo
da lista, deve aparecer 3, 4, 5, 9.
O programa deve oferecer ao usuário as operações:
- Inserir elemento na lista; [x]
- Retirar elemento da lista; [x]
- Buscar um elemento informado está na lista, retornando o endereço do elemento se ele existir na lista, ou NULL se não existir[x];
- Imprimir o conteúdo da lista; [x]
- Contar o número de elementos da lista.[x]*/

#include <stdio.h>
#include <stdlib.h>

struct elemento
{
   int dado;
   struct elemento *prox;
};

typedef struct elemento *Lista;

Lista criaLista()
{
   return NULL;
}

void imprimeLista(Lista l)
{
   Lista p; 
   printf("|*******************************************************|\n");
   printf("| Itens da lista.                                       |\n");
   p = l;
   while (p != NULL)
   {
      printf("%d - ", p->dado);
      p = p->prox;
   }
   printf("\n|*******************************************************|\n");
}

int contaLista(Lista l)
{
   Lista p;
   int cont = 0;
   p = l;
   while (p != NULL)
   {
      cont++;
      p = p->prox;
   }
   return cont;
}

Lista buscaLista(Lista l, int e)
{
   Lista p;
   p = l;
   while ((p != NULL) && (p->dado != e))
   {
      p = p->prox;
   }
   return (p);
}

Lista insereLista(Lista l, int e)
{
   Lista novo;
   novo = malloc(sizeof(struct elemento));
   novo->dado = e;
   novo->prox = l;
   return (novo);
}

Lista retiraLista(Lista l, int e)
{
   Lista p,
   ant;
   p = l;
   ant = l;

   while ((p != NULL) && (p->dado != e))
   {
      ant = p;
      p = p->prox;
   }
   if (p != NULL)
   {      
      if (p == ant) 
      {
         l = p->prox;
         free(p);
      }
      else 
      {
         ant->prox = p->prox;
         free(p);
      }
   }
   return (l);
}

int main()
{
   Lista l;
   Lista pos;
   l = criaLista();
   int cont;
   int item;
   int op;
   do
   {
      printf("|*******************************************************|\n");
      printf("|                                                       |\n");
      printf("|               IFPR - Estrutura de Dados               |\n");
      printf("|               Lista Encadeada Ordenada                |\n");
      printf("|                                                       |\n");
      printf("|               1 - Inserir elemento:                   |\n");
      printf("|               2 - Retirar elemento:                   |\n");
      printf("|               3 - Imprimir elemento:                  |\n");
      printf("|               4 - Imprimir lista:                     |\n");
      printf("|               5 - Conta elementos:                    |\n");
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
         printf("Numero a ser inserida: ");
         scanf("%d", &item);
         l = insereLista(l, item);
         break;
      case 2:
         system("cls || clear");
         printf("|*******************************************************|\n");
         printf("|                   Retirar elemento                    |\n");
         printf("|*******************************************************|\n");
         printf("Numero a ser removido: ");
         scanf("%d", &item);
         l = retiraLista(l, item);
         break;
      case 3:
         system("cls || clear");
         printf("|*******************************************************|\n");
         printf("|                   Imprimir elemento                   |\n");
         printf("|*******************************************************|\n");
         scanf("%d", &item);
         pos = buscaLista(l, item);
         if (pos == NULL)
         {
            printf("|*******************************************************|\n");
            printf("| Item não encontrado.                                  |\n");
            printf("|*******************************************************|\n");
         } else
         {
            printf("|*******************************************************|\n");
            printf("|Item encontrado.                                       |\n");
            printf("|*******************************************************|\n");
         }
         
         break;
      case 4:
         system("cls || clear");
         printf("|*******************************************************|\n");
         printf("|                   Imprimir lista                      |\n");
         printf("|*******************************************************|\n");
         imprimeLista(l);
         break;
      case 5:
         system("cls || clear");
         printf("|*******************************************************|\n");
         printf("|                   Conta elementos                     |\n");
         cont = contaLista(l);
         printf("| A lista tem %d itens.                                 |\n", cont);
         printf("|*******************************************************|\n");
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
}