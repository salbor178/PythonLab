/*
    Una variable de tipo puntero almacena la direccion de memoria de otra variable que puede ser int,
    char, float, struct, etc.
*/

#include<stdio.h>
#include<conio.h>
#include<string.h>
/*
int main()
{
    int valor1=10;
    int valor2=20;
    int *pe;
    pe=&valor1;
    printf("Lo apuntado por pe es: %i\n", *pe);
    printf("La direccion que almacena pe es: %p\n", pe);
    
    pe=&valor2;
    printf("Lo apuntado por pe es: %i\n", *pe);
    printf("La direccion que almacena pe es: %p\n", pe);
    
    getch();
    return 0;
}
    */

int main()
{
    int x1, x2;
    int *pe;
    pe=&x1;
    *pe=100;
    pe=&x2;
    *pe=200;
    printf("Primer variable entera: %i \n", x1);
    printf("Segunda variable entera: %i \n", x2);

    getch();
    return 0;
}