#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct nodo
{
    int info;
    struct nodo *sig;
};
struct nodo *raiz=NULL;

void insertarPrimero(int x)
{
    struct nodo *nuevo;
    nuevo=malloc(sizeof(struct nodo));
    nuevo -> info = x;
    nuevo -> sig = raiz;
    raiz = nuevo;
}

void liberar()
{
    struct nodo *reco = raiz;
    struct nodo *bor;
    while (reco != NULL)
    {
        bor = reco;
        reco = reco->sig;
        free(bor);
    }    
}

void imprimir(struct nodo *reco)
{
    if (reco != NULL)
    {
        imprimir(reco->sig);
        printf(" %i ",reco->info);
    }    
}

void imprimirIzquierdaDerecha()
{
    struct nodo *reco = raiz;
    while (reco != NULL)
    {
        printf(" %i ", reco->info);
        reco = reco->sig;
    }
    printf("\n");    
}

int main()
{
    insertarPrimero(10);
    insertarPrimero(4);
    insertarPrimero(5);
    imprimirIzquierdaDerecha();
    imprimir(raiz);

    liberar();

    getch();
    return 0;
}