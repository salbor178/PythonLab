#include<stdio.h>
#include<conio.h>
#include<string.h>

struct producto{
    int codigo;
    char descripcion[41];
    float precio;
};

void imprimir(struct producto x)
{
    printf("Codigo del producto: %i\n",x.codigo);
    printf("Descripcion: %s",x.descripcion);
    printf("Precio: %0.2f", x.precio);
}

int main()
{
    struct producto pro={1,"naranjas",5.50};
    /*
    pro.codigo=1;
    strcpy(pro.descripcion, "naranjas");
    pro.precio=5.50;*/

    imprimir(pro);
    getch();
    return 0;

}