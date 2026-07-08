#include<stdio.h>
#include<conio.h>
#include<string.h>

int superficie(int lado)
{
    int superficie = lado * lado;
    return superficie;
}

int main()
{
    int valor;
    printf("Ingrese el valor del lado del cuadrado");
    scanf("%i", &valor);
    int super = superficie(valor);
    printf("La superficie del cuadrado es %i", super);

    getch();
    return 0;
}
