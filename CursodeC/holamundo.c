#include<stdio.h>
#include<conio.h>

int main()
{
    int n1, n2, suma, producto;
    printf("Ingrese primer valor: ");
    scanf("%i", &n1);
    printf("Ingrese segundo valor: ");
    scanf("%i", &n2);
    suma= n1+n2;
    producto= n1 * n2;
    printf("La suma de los dos valores es: %i", suma);
    printf("\n");
    printf("El producto de los dos valores es: %i", producto);
    getch();
    return 0;
}