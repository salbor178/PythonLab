#include<stdio.h>
#include<conio.h>
#include<string.h>

void cargar(int sueldos[5])
{
    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese el valor de sueldo_%i: ", i+1);
        scanf("%i", &sueldos[i]);
    }
}

void ordenamiento(int sueldos[5])
{
    for (int i = 0; i < 4; i++)
    {
        for (int x = 0; x < 4-i; x++)
        {
            if(sueldos[x] > sueldos[x+1])
            {
                int aux=sueldos[x];
                sueldos[x]=sueldos[x+1];
                sueldos[x+1]= aux;
            }
        }
        
    }
    
}

void imprimir(int vector[5])
{
     for (int i = 0; i < 5; i++)
     {
        printf("%i \n", vector[i]);
     }
     
}

int main()
{
    int sueldos[5];

    cargar(sueldos);
    ordenamiento(sueldos);
    imprimir(sueldos);

    getch();
    return 0;
    
}