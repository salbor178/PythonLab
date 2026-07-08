#include<stdio.h>
#include<conio.h>
#include<string.h>

#define TAMANO 4
struct producto
{
    int codigo;
    char descripcion[41];
    float precio;
};

void cargar(struct producto vec[TAMANO])
{
    for (int i = 0; i < TAMANO; i++)
    {
        printf("Ingrese el codigo de producto: ");
        scanf("%i", &vec[i].codigo);
        fflush(stdin);
        printf("Ingrese descripcion: ");
        gets(vec[i].descripcion);
        printf("Ingrese precio: ");
        scanf("%f", &vec[i].precio);
    }
}

void imprimir(struct producto vect[TAMANO])
{
    for (int i = 0; i < TAMANO; i++)
    {
        printf("%i  %s  %0.2f\n", vect[i].codigo, vect[i].descripcion, vect[i].precio);
    }
    
}

void preciomayor(struct producto vector[TAMANO])
{
    int pos=0;
    for (int i = 1; i < TAMANO; i++)
    {
        if (vector[i].precio>vector[pos].precio)
        {
            pos=i;
        }
        
    }
    printf("El producto mas caro es: %s", vector[pos].descripcion);    
}

int main()
{
    struct producto vector[TAMANO];
    cargar(vector);
    imprimir(vector);
    preciomayor(vector);

    getch();
    return 0;
}
