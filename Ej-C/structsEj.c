#include<stdio.h>
#include<conio.h>
#include<string.h>

struct pais
{
    char nombre[40];
    int cantidadhab;
};

int main()
{
    struct pais pais1, pais2, pais3;
    printf("Ingrese el nombre del pais");
    gets(pais1.nombre);
    printf("Ingrese la cant de habitantes");
    scanf("%i", &pais1.cantidadhab);
    
    printf("Ingrese el nombre del pais");
    gets(pais2.nombre);
    printf("Ingrese la cant de habitantes");
    scanf("%i", &pais2.cantidadhab);
    
    printf("Ingrese el nombre del pais");
    gets(pais3.nombre);
    printf("Ingrese la cant de habitantes");
    scanf("%i", &pais3.cantidadhab);
    

    
    
}
