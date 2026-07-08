#include<stdio.h>
#include<conio.h>
#include<string.h>
/*
struct producto
{
    int codigo;
    char desc[41];
    float precio;
};

void cargar(struct producto *ppro)
{
    printf("Ingrese codigo: ");
    scanf("%i", &(*ppro).codigo);
    fflush(stdin);
    printf("Ingrese descripcion: ");
    gets((*ppro).desc);
    printf("Ingrese precio: ");
    scanf("%f", &(*ppro).precio);
}

void imprimir(struct producto p)
{
    printf("Codigo: %i", p.codigo);
    printf("Descripcion: %s", p.desc);
    printf("Precio: %.2f", p.precio);
}

int main()
{
    struct producto pro;
    cargar(&pro);
    imprimir(pro);
    getch();
    return 0;
}
*/

/*
// SINTAXIS SIMPLIFICADA

struct producto
{
    int codigo;
    char desc[41];
    float precio;
};

void cargar(struct producto *ppro)
{
    printf("Ingrese codigo: ");
    scanf("%i", &ppro->codigo);
    fflush(stdin);
    printf("Ingrese descripcion: ");
    gets(ppro->desc);
    printf("Ingrese precio: ");
    scanf("%f", &ppro->precio);
}

void imprimir(struct producto p)
{
    printf("Codigo: %i", p.codigo);
    printf("Descripcion: %s", p.desc);
    printf("Precio: %.2f", p.precio);
}

int main()
{
    struct producto pro;
    cargar(&pro);
    imprimir(pro);


    getch();
    return 0;

}

*/

// EJEMPLO


struct pais
{
    char nombre[41];
    int canthab;
};

void cargar(struct pais *ppais)
{
    printf("Ingrese nombre del pais: ");
    gets(ppais->nombre);
    printf("Ingrese cantidad de habitantes: ");
    scanf("%i", ppais->canthab);
    fflush(stdin);
}

void imprimir(struct pais pa)
{
    printf("Nombre del pais es: %s, y la cantidad de habitantes es: %i", pa.nombre, pa.canthab);
}

int main()
{
    struct pais pais1, pais2, pais3;
    cargar(&pais1);
    cargar(&pais2);
    cargar(&pais3);

    imprimir(pais1);
    imprimir(pais2);
    imprimir(pais3);

    getch();
    return 0;
}
