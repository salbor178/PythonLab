#include<stdio.h>
#include<conio.h>

int main ()
{
    int n1;
    float resto;

    printf("Ingrese primer numero: \n");
    scanf("%i", &n1);

    resto= n1%10;

    if (0 < resto)
    {
        printf("el numero tiene 2 cifras");
    }
    else
    {
        printf("el numero tiene 2 cifras");

    }


    getch();
    return 0;
}