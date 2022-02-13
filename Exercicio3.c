#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
- Exercício 3: Calculadora de quatro operações básicas.
  - Implemente uma função que receba dois números, e retorne a soma dos dois;
  - Implemente uma função que receba dois números, e retorne o produto dos dois;
  - Implemente uma função que receba dois números, e retorne a diferença entre o primeiro e o segundo;
  - Implemente uma função que receba dois números, e retorne o resultado da divisão do primeiro pelo segundo;
  - Implemente uma função que receba dois números, e um caracter que indique a operação ("+", "-", "*" ou "/") e calcule o resultado da operação, 
  chamando as funções já implementadas.
  - Implemente o programa principal, que solicita dois números e a operação ao usuário, e chama a função que calcula o resultado da operação.
*/

double n1, n2, result;
char sinal;

double soma(double n1, double n2) {
    return n1 + n2;
}

double sub(double n1, double n2) {
    return n1 - n2;
}

double mult(double n1, double n2) {
    return n1 * n2;
}

double divi(double n1, double n2) {
    return n1 / n2;
}

int main()
{
    char op;
    do
    {
        printf("|*******************************************************|\n");
        printf("|                 IFPR - Estrutura de Dados             |\n");
        printf("|                       CALCULADORA - C                 |\n");
        printf("|   Digite o primeiro Numero:                           |\n");
        scanf("%lf", &n1);
        printf("|   Digite o segundo Numero:                            |\n");
        scanf("%lf", &n2);
        printf("|-------------------------------------------------------|\n");
        printf("|   + - Adição                                          |\n");
        printf("|   - - Subtração                                       |\n");
        printf("|   * - Multiplicação                                   |\n");
        printf("|   / - Divisão                                         |\n"); 
        printf("|   Digite uma operação das acimas:                     |\n");
        scanf("%c", &op);
        printf("|-------------------------------------------------------|\n");
        printf("|   0 - Sair                                            |\n");
        printf("|*******************************************************|\n");


        scanf("%c", &op);
        switch (op)
        {
        case '+':
            system("cls || clear");
            printf("|*******************************************************|\n");
            printf("|                          Adição                       |\n");
            result = soma(n1, n2);
            printf("| A soma do %0.1lf e %0.1lf, é igual %0.1lf.            |\n", n1, n2, result);
            printf("|*******************************************************|\n");
            

            break;
        case '-': 
            system("cls || clear");
            printf("|*******************************************************|\n");
            printf("|                       Subtração                       |\n");
            result = sub(n1, n2);
            printf("| A subtração de %0.1lf com %0.1lf, é igual %0.1lf.     |\n", n1, n2, result);
            printf("|*******************************************************|\n");
            
            break;
        
        case '*':
            system("cls || clear");
            printf("|*******************************************************|\n");
            printf("|                    Multiplicação                      |\n");
            result = mult(n1, n2);
            printf("| A multiplicação entre %0.1lf e %0.1lf, é igual %0.1lf.| \n", n1, n2, result);
            printf("|*******************************************************|\n");
            break;

        case '/':
            system("cls || clear");
            printf("|*******************************************************|\n");
            printf("|                         Divisão                       |\n");
            printf("| Primeiro Numero:                                      |\n");
            result = divi(n1, n2);
            printf("| A divisão de %0.1lf com %0.1lf, é igual %0.1lf.       |\n", n1, n2, result);
            printf("|*******************************************************|\n");
           
            break;

        default:
            if(n1 != 0 && op != '0' && n2 != 0)
                printf(" Operador invalido\n\n ");
            else{
                printf("\nSinto muito, algo inesperado aconteceu.\n\n");
                printf(" Fechando calculadora!\n ");
            }   
            break;
        }
    } while (n1 != 0 && op != '0' && n2 != 0);
}
