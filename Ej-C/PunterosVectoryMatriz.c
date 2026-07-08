#include<stdio.h>
#include<conio.h>
#include<string.h>
/*
#define TAM 5

void cargar(float *p)
{
    for (int i = 0; i < TAM; i++)
    {
        printf("Ingrese elemento: ");
        scanf("%f", &p[i]);
    }
}

void imprimir(float *p)
{
    for (int i = 0; i < TAM; i++)
    {
        printf(" %0.2f ", p[i]);
    }
}

int main()
{
    float vect[TAM];
    cargar(vect);
    imprimir(vect);

    getch();
    return 0;
}
*/

// Ejemplo2

#define LARGO 41

void cargar(char *ppal)
{
    printf("Ingrese una palabra: ");
    gets(ppal);
}

void imprimir(char *ppal)
{
    printf("La palabra ingresada es: %s", ppal);
}

int main()
{
    char palabra[LARGO];
    cargar(palabra);
    imprimir(palabra);
    getch();
    return 0;
}