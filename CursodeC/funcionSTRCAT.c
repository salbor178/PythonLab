#include<stdio.h>
#include<conio.h>
#include<string.h>

int main()
{
    char nombre[31];
    char apellido[31];
    char nomape[62];

    printf("Ingrese el nombre");
    gets(nombre);
    printf("Ingrese el apellido");
    gets(apellido);

    strcpy(nomape, nombre);
    strcat(nomape, " ");
    strcat(nomape, apellido);
    
    printf("%s", nomape);

    getch();
    return 0;
}