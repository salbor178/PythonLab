#include<stdio.h>
#include<conio.h>
#include<string.h>

int main()
{
    char palabra[31];
    printf("Ingrese una palabra");
    gets(palabra);
    int cant = strlen(palabra);
    printf("La palabra %s tine %i letras", palabra, cant);

    getch();
    return 0;
}