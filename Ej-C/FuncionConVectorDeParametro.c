#include<stdio.h>
#include<conio.h>
#include<string.h>

void cargar(int vec[5])
{
    for (int x=0;x<5;x++)
    {
        printf("Ingrese elemento: ");
        scanf("%i", &vec[x]);
    }
}

void imprimir(int vec[5])
{
    printf("Contenido completo del vector. \n");
    for (int i = 0; i < 5; i++)
    {
        printf("%i", vec[i]);
    }    
}

int main()
{
    int vector[5];
    cargar(vector);
    imprimir(vector);
    getch();

    return 0;
}