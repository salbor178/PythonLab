#include<stdio.h>

int main()
{
    int numeros[4], i;
    printf("Ingrese cuatro numeros: ..\n");
    for ( i = 0; i < 4; i++)
    {
        scanf("%d", &numeros[i]);
    }
    printf("los numeros ingresados son: \n");
    for ( i = 0; i < 4; i++)
    {
        printf("%d\n", numeros[i]);
    }
    
    return 0;
}