#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
- Exercício 1: Chamada de função passando parâmetro por valor
  - Implemente um programa que solicite a base e a altura de um retângulo, e chame uma função que calcule e imprima a área do retângulo. 
    A impressão da área do retângulo deve ser feita dentro da função. */

double calculaRetangulo(double base, double altura){
    double result = 0;
    result = base * altura;
    printf("O resultado do calculo é: %0.1lf \n", result);
    return 0;
}

int main()
{
    int op;
    do
    {

        printf("*********************************************\n");
        printf("* IFPR - Estrutura de Dados                 *\n");
        printf("* 1 - Calcula Retângulo                     *\n");
        printf("* 0 - Sair                                  *\n");
        printf("*********************************************\n");

        scanf("%d", &op);
        //system("cls");

            double base; 
            double altura; 
            double resultado;
        switch (op)
        {
        case 1:

            printf("*********************************************\n");
            printf("*Digite o valor da base: \n");
            scanf("%lf", &base);
            printf("*Digite o valor da altura: \n");
            scanf("%lf", &altura);
            printf("*********************************************\n");
            
            calculaRetangulo(base, altura);
            
            break;
        default:
            printf("Opção Invalida.\n"); 
            break;
        }
    } while (op != 0);
}