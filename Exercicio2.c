#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 - Exercício 2: Retorno de valor da função para o programa principal

- Copiar o programa anterior, e alterá-lo para que a função somente calcule a área do retângulo, sem imprimir, 
retorne o valor da área para o programa principal. E o programa principal deve imprimir a área.
*/

double calculaRetangulo(double base, double altura){
    double result = 0;
    result = base * altura;
    return result;
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
        system("cls || clear"); //para windows

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
            
            resultado = calculaRetangulo(base, altura);
            printf("O resultado do calculo é: %0.1lf \n", resultado);
            
            break;
        default:
            printf("Opção Invalida.\n"); 
            break;
        }
    } while (op != 0);
}