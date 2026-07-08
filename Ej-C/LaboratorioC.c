#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define LIM 4

struct nodo
{
    int x;
    int y;
    struct nodo *sig;
};

void cargarNodo(struct nodo *posActual);


struct nodo *raiz = NULL;

void avzDer(struct nodo *posActual) // sumar 1 a x
{
    cargarNodo(posActual); // sumar nodo a la pila que genera el camino
    posActual->x = posActual->x + 1;
}

void avzIzq(struct nodo *posActual) // restar 1 a x
{
    cargarNodo(posActual); // sumar nodo a la pila que genera el camino
    posActual->x = posActual->x - 1;
}

void avzArr(struct nodo *posActual) // sumar 1 a y
{
    cargarNodo(posActual);
    posActual->y = posActual->y + 1;
}

void avzAba(struct nodo *posActual) // restar uno a y
{
    cargarNodo(posActual);
    posActual->y = posActual->y - 1;
}

int visitado(struct nodo posSig)
{
    struct nodo *reco = raiz;
    if(reco != NULL)
    {
        while (reco->sig != NULL)
        {
            if(posSig.x == reco->x && posSig.y == reco->y) // existe en la cola o lista si fue visitado
                return 1;
            reco = reco->sig;
        }
    }
    return 0;
}

void buscarCamino(struct nodo *posAct, struct nodo meta)
{
    int sigDerX, sigIzqX, sigArrY, sigAbaY;
    while (posAct->x != meta.x && posAct->y != meta.y)
    {
        struct nodo posSigDer;
        posSigDer.x = posAct->x + 1;
        posSigDer.y = posAct->y;
        
        struct nodo posSigIzq;
        posSigIzq.x = posAct->x - 1;
        posSigIzq.y = posAct->y;
        
        struct nodo posSigArr;
        posSigArr.x = posAct->x;
        posSigArr.y = posAct->y + 1;
        
        struct nodo posSigAba;
        posSigAba.x = posAct->x;
        posSigAba.y = posAct->y - 1;

        sigDerX = posAct->x + 1;
        sigIzqX = posAct->x - 1;
        sigArrY = posAct->y + 1;
        sigAbaY = posAct->y - 1;
        if (sigDerX <= LIM && sigDerX >= 1 && !visitado(posSigDer))
        {
            avzDer(posAct);
        }
        else if (sigIzqX <= LIM && sigIzqX >= 1 && !visitado(posSigIzq))
        {
            avzIzq(posAct);
        }
        else if (sigArrY <= LIM && sigArrY >= 1 && !visitado(posSigArr))
        {
            avzArr(posAct);
        }
        else if (sigAbaY <= LIM && sigAbaY >= 1 && !visitado(posSigAba))
        {
            avzAba(posAct);
        } 
    }
}

void cargarNodo(struct nodo *posActual)
{
    struct nodo *nuevo;
    nuevo = malloc(sizeof(struct nodo));
    nuevo->sig = NULL;
    nuevo->x = posActual->x;
    nuevo->y = posActual->y;
    if (raiz == NULL)
    {
        raiz = nuevo;
    }
    else
    {
        struct nodo *reco=raiz;
        while(reco->sig != NULL)
        {
            reco = reco->sig;
        }
        reco->sig = nuevo;
    }
}

void liberar()
{
    struct nodo *reco = raiz;
    struct nodo *bor;
    while (reco != NULL)
    {
        bor = reco;
        reco= reco->sig;
        free(bor);
    }
    raiz = NULL;
}

int cantidad()
{
    struct nodo *reco = raiz;
    int cant = 0;
    while (reco != NULL)
    {
        cant++;
        reco = reco -> sig;
    }
    return cant; 
}

void imprimirCamino()
{
    struct nodo *reco = raiz;
    printf("El camino recorrido para llegar a la meta fue: \n");
    if(reco != NULL)
    {
            while (reco->sig != NULL)
        {
            printf("-> (%i;%i) ", reco->x, reco->y);
            reco = reco->sig;
        }
    }
}

int main()
{
    struct nodo meta;
    meta.x = 1;
    meta.y = 3;
    meta.sig = NULL;
    struct nodo *posActual;
    posActual = malloc(sizeof(struct nodo));
    posActual->x=1;
    posActual->y=1;
    posActual->sig=NULL;
    cargarNodo(posActual);
    buscarCamino(posActual, meta);

    imprimirCamino();

    liberar();
    getch();
    return 0;
}