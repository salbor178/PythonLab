#include<stdio.h>
#include<stdlib.h>


int main()
{
    int *valor = malloc(sizeof(int));
    if(valor == NULL)
    {
        fprintf(stderr, "Error: could not allocate memory\n");
        return (1);
    }

    *valor = 25;
    printf(" %i ", *valor);
    printf(" %p ", valor);

    free(valor);

    system("pause");
    return (0);
}