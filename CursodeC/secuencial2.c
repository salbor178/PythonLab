#include<stdio.h>
#include<conio.h>

int main()
{
    int lado, perimetro;
    printf("Ingrese el valor de lado del cuadrado: ");
    scanf("%i", &lado);
    perimetro=lado*4;
    printf("El perimetro del cuadrado es de: ");
    printf("%i", perimetro);
    getch();
    return 0;
}