#include<stdio.h>

int main(){
    int i;
    double num, suma = 0.0;

    for(i=1; i<= 4; ++i)
    {
        printf("Ingrese el numero_%d: ", i);
        scanf("%lf", &num);
        if(num < 0.0)
        {
            break;          
        }
        suma += num; //suma = suma + num;
                
    }
    printf("suma = %.2lf", suma);

    return 0;
}