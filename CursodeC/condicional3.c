#include<stdio.h>
#include<conio.h>

int main ()
{
    int n1, n2, n3;
    float promedio;

    printf("Ingrese primer numero: \n");
    scanf("%i", &n1);
    printf("Ingrese segundo numero: \n");
    scanf("%i", &n2);
    printf("Ingrese segundo numero: \n");
    scanf("%i", &n3);
    promedio= (n1+n2+n3)/3;
    if (7 <= promedio)
    {
        printf("El alumno promociono la materia con: \n");
        printf("%.1f", promedio);
    }
    else
    {
        printf("El alumno no promociono la materia \n");
    }


    getch();
    return 0;
}