#include<stdio.h>
#include<conio.h>
#include<string.h>

int main()
{
    char nombre1[31];
    char nombre2[31];
    char nombrelargo[31];

    printf("Ingrese el primer nombre: ");
    gets(nombre1);
    printf("Ingrese el segundo nombre: ");
    gets(nombre2);

    if (strlen(nombre1)>strlen(nombre2))
    {
        strcpy(nombrelargo, nombre1);
    }
    else
    {
        strcpy(nombrelargo, nombre2);

    }
    
    printf("%s", nombrelargo);

    getch();
    return 0;
}