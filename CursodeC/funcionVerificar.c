#include<stdio.h>

void numeroprimo();

int main ()
{
    numeroprimo();

    return 0;
}

void numeroprimo()
{
    int n, i, flag = 0;
    printf("Ingrese un numero: ");
    scanf("%d", &n);
    for ( i = 2; i <= n/2; i++)
    {
        if (n%i == 0)
        {
            flag = 1;
        }
        
    }
    if (flag == 1)
    {
        printf("%d no es un numero primo.", n);
    }
    else
    {
        printf("%d es un numero primo.", n);
    }
    
    
}