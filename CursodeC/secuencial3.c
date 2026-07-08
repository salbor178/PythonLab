#include<stdio.h>
#include<conio.h>

int main ()
{
    int n1, n2, n3, n4, suma, producto, sumatot;
    float promedio;

    printf("Ingrese el primer numero: \n");
    scanf("%i", &n1);
    printf("Ingrese el segundo numero: \n");
    scanf("%i", &n2);
    printf("Ingrese el tercer numero: \n");
    scanf("%i", &n3);
    printf("Ingrese el cuarto numero: \n");
    scanf("%i", &n4);

    suma=n1+n2;
    producto=n3*n4;

    printf("El resultado de la suma de los 2 primeros numeros es: ");
    printf("%i", suma);
    printf("El resultado del producto de los 2 ultimos numeros es: ");
    printf("%i", producto);
    printf("\n");
    sumatot=n1+n2+n3+n4;
    promedio= sumatot/4;
    printf("El promedio de los 4 numeros ingresados es: \n");
    printf("%.2f", promedio);
    getch();
    return 0;
}