#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct nodo
{
    int info;
    struct nodo *sig;
    struct nodo *ant;
};

struct nodo *raiz = NULL;

void liberar()
{
    struct nodo *reco = raiz;
    struct nodo *bor;
    while (reco != NULL)
    {
        bor = reco;
        reco = reco -> sig;
        free(bor);
    }
}

int vacia()
{
    if (raiz == NULL)
        return 1;
    else 
    return 0;
}

void imprimir()
{
    struct nodo *reco = raiz;
    printf("Lista completa.\n");
    while (reco != NULL)
    {
        printf(" %i ", reco -> info);
        reco = reco ->sig;
    }
    printf("\n");    
}

int cantidad()
{
    struct nodo *reco=raiz;
    int cant = 0;
    while (reco != NULL)
    {
        cant++;
        reco = reco->sig;
    }
    return cant;
}

void insertar(int pos, int x)
{
    if (pos <= cantidad()+1)
    {
        struct nodo *nuevo;
        nuevo = malloc(sizeof(struct nodo));
        nuevo->info = x;
        nuevo->sig = NULL;
        nuevo->ant = NULL;
        if (pos == 1)
        {
            nuevo -> sig = raiz;
            if (raiz != NULL)
            {
                raiz -> ant=nuevo;
            }
            raiz = nuevo;                  
        }
        else
        {
            if (pos = cantidad()+1)
            {
                struct nodo *reco = raiz;
                while (reco -> sig != NULL)
                {
                    reco = reco -> sig;
                }
                reco->sig = nuevo;
                reco->ant = reco;
            }
            else
            {
                struct nodo *reco = raiz;
                for (int f = 0; f < pos-2; f++)
                {
                    reco = reco -> sig;
                }
                struct nodo *siguiente=reco->sig;
                reco -> sig = nuevo;
                nuevo->ant = reco;
                nuevo ->sig = siguiente;
                siguiente -> ant = nuevo;
            }
            
        }
        
    }
    
}

int main()
{
    insertar(1,10);//pos - valor
    insertar(2,20);
    insertar(3,30);
    imprimir();

    liberar();

    getch();
    return 0;
}