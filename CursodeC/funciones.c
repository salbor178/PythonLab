#include<stdio.h>

int calculadora(int a, int b);

int main ()
{
    int n1, n2, resp;
    printf("Ingrese dos numeros: ");
    scanf("%d %d",&n1, &n2);

    resp=calculadora(n1, n2);
    printf("resp = %d", resp);

    return 0;
}

int calculadora(int a, int b)
{
    int result;
    result=a+b;
    return result;
}