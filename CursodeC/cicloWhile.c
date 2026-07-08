#include<stdio.h>
#include<conio.h>

int main()
{
    int num, x, suma;
    float promedio;
    x=0;
    suma=0;
    while (x<10)
    {
        printf("Ingrese un numero: \n");
        scanf("%i", &num);
        suma= suma + num;
        x= x + 1;
    }
    promedio= suma / 10;
    printf("El promedio de numeros ingresados es: \n");
    printf("%.1f", promedio);
    printf("la suma total de todos los numero es: \n");
    printf("%i", suma);
    getch();
    return 0;
}