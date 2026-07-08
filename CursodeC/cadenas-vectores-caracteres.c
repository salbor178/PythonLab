#include<stdio.h>
#include<conio.h>

int main()
{
    char nombre1[21];
    char nombre2[21];

    int edad1, edad2;
    printf("Ingrese nombre 1: ");
    gets(nombre1);
    printf("Ingrese la edad1: ");
    scanf("%i", &edad1);
    fflush(stdin); // liberar el buffer porque el scanf retiene el caracter "ENTER"
    printf("Ingrese nombre 2: ");
    gets(nombre2);
    printf("Ingrese la edad2: ");
    scanf("%i", &edad2);
    
    printf("La primera persona se llama %s y su edad es %i",nombre1, edad1);


    
}