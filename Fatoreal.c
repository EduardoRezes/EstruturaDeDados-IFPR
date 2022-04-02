#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    int fat(int n);
        if (n == 0)
            return (1);
        else
            return (n * fat(n - 1));

    /*int fat(int n)
    {
        printf("Numero Fatoreal: ");
        scanf("%f", &num);

        if (num > 1)
            return num * fat(num - 1);
        else
            return 1;
        printf("\nFatorial calculado: %f", fat);
    }*/

    return 0;
}
