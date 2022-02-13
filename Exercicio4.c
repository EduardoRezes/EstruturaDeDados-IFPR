/*
Faça um programa que  implementa uma lista com vetores de strings, conforme o exemplo visto em sala, com as seguintes operações:
    1. Inserir elemento 
    2. Retirar Elemento
    3. Criar Lista
    4. Contar elementos da lista
    5. Exibir o conteúdo da lista

    A interface com o usuário deve ser feita pelo programa principal, passando os parâmetros para as funções que implementam as operações sobre a 
    lista.
*/
#include <stdio.h>
#include <stdlib.h>

#define MaxItens 10
#define TamItem 20

//definido Lista
typedef char tpLista[MaxItens] [TamItem];

//cria lista
tpLista L1;

int main() {
    char op;
    do
    {
        printf("|*******************************************************|\n");
        printf("|                                                       |\n");
        printf("|               IFPR - Estrutura de Dados               |\n");
        printf("|                 Lista com Vetores - C                 |\n");
        printf("|                                                       |\n");
        printf("|               1 - Inserir elemento:                   |\n");
        printf("|               2 - Retirar elemento:                   |\n");
        printf("|               3 - Criar Lista:                        |\n");
        printf("|               4 - Retirar elemento:                   |\n");
        printf("|               0 - Sair                                |\n");
        printf("|                                                       |\n");
        printf("|*******************************************************|\n");


        scanf("%c", &op);
        switch (op)
        {
        case '1':
            system("cls || clear");
            printf("|*******************************************************|\n");
            printf("|                          Adição                       |\n");
            printf("| A soma do %0.1lf e %0.1lf, é igual %0.1lf.            |\n", n1, n2, result);
            printf("|*******************************************************|\n");    
            break;
      
        default:
            break;
        }
    } while (op != 0);
}