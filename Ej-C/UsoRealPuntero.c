#include<stdio.h>
#include<conio.h>
#include<string.h>


void cargar(int *pe1, int *pe2)
{
    *pe1=100;
    *pe2=200;
}


int main()
{
    int x1, x2;
    cargar(&x1, &x2);
    printf("%i  %i", x1, x2);

    getch();
    return 0;
     
}