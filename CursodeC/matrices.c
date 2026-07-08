#include<stdio.h>

const int ciudad = 2;
const int semana = 7;

int main()
{    
    int corona[ciudad][semana];
    int i, j;
    for ( i = 0; i < ciudad; i++)
    {
        for ( j = 0; j < semana; j++)
        {
            printf("ciudad: %d, dia: %d. \n", i+1, j+1);
            scanf("%d", &corona[i][j]);
        }
        
    }

    for ( i = 0; i < ciudad; i++)
    {
        for ( j = 0; j < semana; j++)
        {
            printf("ciudad: %d, dia: %d. La cantidad de contagiadoes es: %d. \n", i+1, j+1, corona[i][j]);
        }
        
    }
    

    return 0;
}