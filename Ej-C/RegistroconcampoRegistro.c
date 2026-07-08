#include<stdio.h>
#include<conio.h>
#include<string.h>

#define TAMANO 3

struct fecha
{
    int dd;
    int mm;
    int aa;
};

struct producto
{
    int cod;
    char desc[41];
    float precio;
    struct fecha fvencimiento;
};

void cargar(struct producto vect[TAMANO])
{
    for (int i = 0; i < TAMANO; i++)
    {
        printf("Ingrese cod de producto: ");
        scanf("%i", &vect[i].cod);
        fflush(stdin);
        printf("Ingrese descripcion: ");
        gets(vect[i].desc);
        printf("Ingrese precio: ");
        scanf("", &vect[i].precio);
        printf("Ingrese fecha de vencimiento:...");
        printf("Dia:");
        scanf("%i", &vect[i].fvencimiento.dd);
        printf("Mes:");
        scanf("%i", &vect[i].fvencimiento.mm);
        printf("Anio:");
        scanf("%i", &vect[i].fvencimiento.aa);
    }
    
}

int main()
{

}

