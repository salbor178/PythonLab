/*  
automatic
external
static
register(casi en desuso)
*/

// automatic(variable local) (variable declaradas dentro de un bloque)
/*
#include<stdio.h>

int main(void)
{
    int i;
    for (int i = 0; i < 5; i++)
    {
        printf("curso de c \n");
    }
    printf("%d", i);
    return 0;
    
}
*/
// external (variable global)
/*
#include<stdio.h>

void pantalla();

int n = 3; // variable global

int main()
{
    ++n;
    pantalla();
    return 0;
}

void pantalla()
{
    ++n;
    printf("n = %d", n);
}
*/
// static()

#include<stdio.h>

void pantalla();

int main()
{
    pantalla();
    pantalla();
}
void pantalla()
{
    static int c=1;
    c += 5;
    printf("%d ", c);
}