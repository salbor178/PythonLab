// ejercicio 136 https://www.youtube.com/watch?v=jN77kGt9CGg&list=PLIygiKpYTC_6zHLTjI6cFIRZm1BCT3CuV&index=137

#include<stdio.h>
#include<conio.h>
#include<string.h>

struct punto{
    int x;
    int y;
};

struct punto cargar()
{
    struct punto p;
    printf("Ingrese la coordenada x del punto: ");
    scanf("%i", &p.x);
    printf("Ingrese la coordenada y del punto: ");
    scanf("%i", &p.y);
    return p;
}
