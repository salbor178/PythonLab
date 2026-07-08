#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define LIM 4

struct posicion
{
    int x;
    int y;
};

struct nodo
{
    struct posicion pos;
    struct nodo* prox;
};

struct nodo* crearNodo(int x, int y)
{
    struct nodo* nuevoNodo = malloc(sizeof(struct nodo));
    if(nuevoNodo == NULL)
    {
        printf("Error de asignacion de memoria.");
        exit(1);
    }
    nuevoNodo->pos.x = x;
    nuevoNodo->pos.y = y;
    nuevoNodo->prox = NULL;
    return nuevoNodo;
}

void insertarAlInicio(struct nodo** primero, int x, int y)
{
    struct nodo* nuevoNodo = crearNodo(x, y);
    nuevoNodo->prox = *primero;
    *primero = nuevoNodo;
}

void insertarAlFinal(struct nodo** primero, int x, int y)
{
    struct nodo* nuevoNodo = crearNodo(x, y);
    if (primero == NULL)
    {
        *primero = nuevoNodo;
        return;
    }
    struct nodo* reco = crearNodo(x, y);
    while (reco->prox != NULL)
    {
        reco = reco->prox;
    }
    reco->prox = nuevoNodo;
}

void BorrarNodo(struct nodo** primero, int x, int y)
{
    struct nodo* reco = *primero;
    struct nodo* anterior = NULL;

    while (reco != NULL && reco->pos.x != x && reco->pos.y != y)
    {
        anterior = reco;
        reco = reco->prox;
    }

    if (reco == NULL)
    {
        printf("Posicion no encontrada para borrar");
    }
    if (anterior == NULL)
    {
        anterior->prox = reco->prox;
    }
    free(reco);    
}

int buscarNodo(struct nodo* primero, int x, int y) //posicion
{
    struct nodo* reco = primero;
    while (reco != NULL)
    {
        if (reco->pos.x == x && reco->pos.y == y)
            return (1);
    }
    return (0);    
}

void imprimirLista(struct nodo* primero)
{
    struct nodo* reco = primero;
    while (reco != NULL)
    {
        printf("-> (%i;%i) ",reco->pos.x, reco->pos.y);
    }
}

void liberarLista(struct nodo* primero)
{
    struct nodo* reco;
    while (primero != NULL)
    {
        reco = primero;
        primero = primero->prox;
        free(reco);
    }
}

int main(void)
{
    struct nodo* primero = NULL;
    insertarAlFinal(&primero, 1, 1);
    insertarAlFinal(&primero, 1, 2);
    insertarAlFinal(&primero, 1, 3);
    insertarAlFinal(&primero, 1, 4);

    printf("Lista de posiciones:\n");
    imprimirLista(primero);

    buscarNodo(primero, 1, 3);

    BorrarNodo(&primero, 1, 3);

    buscarNodo(primero, 1, 3);

    liberarLista(primero);

    return (0);
}

