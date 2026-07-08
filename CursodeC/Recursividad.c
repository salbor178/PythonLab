#include<stdio.h>

int suma(int n);

int main()
{
    int numero, resultado;
    printf("Ingrese los numeros: ");
    scanf("%d", &numero);

    resultado = suma(numero);

    printf("la suma es: %d", resultado);
    return 0;
}

int suma(int n)
{
    if( n != 0)
    {
        return n + suma(n-1);
    }
    else
    {
        return n;
    }
}