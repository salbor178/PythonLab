#include<stdio.h>
#include<conio.h>

int main ()
{
    int n1, n2, mayor;

    printf("Ingrese primer numero: \n");
    scanf("%i", &n1);
    printf("Ingrese segundo numero: \n");
    scanf("%i", &n2);

    if (n1 < n2)
    {
        mayor=n2;
    }
    else
    {
        mayor=n1;
    }

    printf("El mayor de ambos numero es: \n");
    printf("%i", mayor);

    getch();
    return 0;
}