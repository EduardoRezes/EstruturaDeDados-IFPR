/******************************************************** 
   Faça um programa que  implementa uma lista com vetores de strings, conforme o exemplo visto em sala, com as seguintes operações:
    1. Inserir elemento [x]
    2. Retirar Elemento [x]
    3. Criar Lista [x]
    4. Contar elementos da lista
    5. Exibir o conteúdo da lista [x] 

    A interface com o usuário deve ser feita pelo programa principal, passando os parâmetros para as funções que implementam as operações sobre 
    a lista.
    Enviar o arquivo fonte em C, funcionando.

*********************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MaxItens 5
#define TamItem 10

//lista
typedef char tpLista[MaxItens][TamItem];

void criaLista(tpLista l)
{
   int i;
   for (i = 0; i < MaxItens; i++)
   {
      l[i][0] = '\0';
   }
}

void imprimeLista(tpLista l)
{
   int i;
   printf("|*******************************************************|\n");
   printf("| Itens da lista                                        |\n");
   for (i=0; i<MaxItens && strlen(l[i])>0; i++){
      printf("%s - ",l[i]);
   } 
   return (i);
}

void insereElemento(tpLista l, char *item)
{
   int i;
   for (i = 0; i < MaxItens && strlen(l[i]) > 0; i++);
   if (i < MaxItens)
   {
      strcpy(l[i], item); 
      system("cls || clear");
      printf("|*******************************************************|\n");
      printf("| Item (%s) inserido com sucesso                        |\n", item);
      printf("|*******************************************************|\n");
   }
   else{
      system("cls || clear");
      printf("|*******************************************************|\n");
      printf("| Lista cheia, não pode inserir                         |\n");
      printf("|*******************************************************|\n");
   }
}

void retiraLista(tpLista l, char *item)
{
   int i;
   for (i = 0; i < MaxItens && strlen(l[i]) > 0 && (strcmp(l[i], item) != 0); i++);

   if (i < MaxItens && (strcmp(l[i], item) == 0))
   {
      system("cls || clear");
      printf("|*******************************************************|\n");
      printf("| Item (%s) encontrado, removendo.                      |\n", item);
      printf("|*******************************************************|\n");
      if (i < (MaxItens - 1))
      {
         for (; i < (MaxItens - 1) && strlen(l[i]) > 0; i++)
            strcpy(l[i], l[i + 1]);
      }
      l[MaxItens - 1][0] = '\0';
   }
   else{
      system("cls || clear");
      printf("|*******************************************************|\n");
      printf("| Item (%s) não encontrado.                             |\n", item);
      printf("|*******************************************************|\n");
   }
}

int contaLista(tpLista l){
   int i;
   for (i = 0; i<MaxItens && strlen(l[i])>0; i++);
   return(i);
}


int main()
{
   tpLista list;
   criaLista(list);
   int op;
   do
   {
      printf("|*******************************************************|\n");
      printf("|                                                       |\n");
      printf("|               IFPR - Estrutura de Dados               |\n");
      printf("|                 Lista de Char - C                     |\n");
      printf("|                                                       |\n");
      printf("|               1 - Inserir String:                     |\n");
      printf("|               2 - Retirar elemento:                   |\n");
      printf("|               3 - Imprimir conteudo:                  |\n");
      printf("|               4 - Conta elementos:                    |\n");
      printf("|               0 - Sair                                |\n");
      printf("|                                                       |\n");
      printf("|*******************************************************|\n");
      printf("Operação: ");

      scanf("%d", &op);
      setbuf(stdin, NULL);

      char stringInserida[TamItem];
      char stringRemovida[TamItem];
      switch (op)
      {   
      case 1:
         system("cls || clear");
         printf("|*******************************************************|\n");
         printf("|                   Inserir String                      |\n");
         printf("|*******************************************************|\n");
         printf("String a ser inserida: ");
         scanf("%s", stringInserida);
         insereElemento(list, stringInserida);
         break;
      case 2:
         system("cls || clear");
         printf("|*******************************************************|\n");
         printf("|                   Retirar elemento                    |\n");
         printf("|*******************************************************|\n");
         printf("String a ser removida: ");
         scanf("%s", stringRemovida);
         retiraLista(list, stringRemovida);
         break;
      case 3:
         system("cls || clear");
         printf("|*******************************************************|\n");
         printf("|                   Imprimir conteudo                   |\n");
         printf("|*******************************************************|\n");
         imprimeLista(list);
         break;
       case 4:
         system("cls || clear");
         printf("|*******************************************************|\n");
         printf("|                   Conta elementos                     |\n");
         int i = contaLista(list);
         printf("|O numero de elementos é %d.                            |\n", i);
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