#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <math.h>

#define FILAS 50
#define COLS 50
#define OBSTACULO_PROB 25 /* probabilidad % de celda ocupada por obstáculo */
#define INF INT_MAX

typedef enum { LIBRE = 0, OBSTACULO = 1 } TipoCelda;

typedef struct {
    int f, g, h;        /* f = g + h, g = coste desde inicio, h = heurística */
    int padre_f, padre_c;
    TipoCelda tipo;
    int coste;          /* coste para entrar en la celda */
    int abierto;        /* bandera: 0 = no en open, 1 = en open */
    int cerrado;        /* bandera: 1 = ya expandido/closed */
} Nodo;

/* mapa estático de nodos */
Nodo mapa[FILAS][COLS];

/* movimientos 4-direcciones (cambiar a 8 si querés diagonales) */
const int d4[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

/* Helpers */
int es_valido(int f, int c) {
    return f >= 0 && f < FILAS && c >= 0 && c < COLS;
}

int heuristica_manhattan(int f1, int c1, int f2, int c2) {
    return abs(f1 - f2) + abs(c1 - c2);
}

/* Priority: extraer el nodo en open con menor f (búsqueda lineal, suficiente para mapas pequeños) */
void extraer_min_f(int *out_f, int *out_c) {
    int mejor_f = INF;
    int mf = -1, mc = -1;
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (mapa[i][j].abierto && !mapa[i][j].cerrado) {
                if (mapa[i][j].f < mejor_f) {
                    mejor_f = mapa[i][j].f;
                    mf = i; mc = j;
                }
            }
        }
    }
    *out_f = mf; *out_c = mc;
}

/* Reconstruir ruta desde destino hasta inicio rellenando la matriz mark_route */
int reconstruir_ruta(int fin_f, int fin_c, int mark_route[FILAS][COLS]) {
    if (mapa[fin_f][fin_c].g == INF) return 0;
    int f = fin_f, c = fin_c, len = 0;
    while (!(mapa[f][c].padre_f == -1 && mapa[f][c].padre_c == -1)) {
        mark_route[f][c] = 1;
        int pf = mapa[f][c].padre_f;
        int pc = mapa[f][c].padre_c;
        f = pf; c = pc;
        ++len;
        if (len > FILAS * COLS) break; /* seguridad */
    }
    mark_route[f][c] = 1; /* marcar inicio */
    return 1;
}

/* Generar mapa aleatorio con obstáculos y costes */
void generar_mapa_aleatorio(void) {
    srand((unsigned)time(NULL));
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            mapa[i][j].padre_f = -1;
            mapa[i][j].padre_c = -1;
            mapa[i][j].g = INF;
            mapa[i][j].f = INF;
            mapa[i][j].h = 0;
            mapa[i][j].abierto = 0;
            mapa[i][j].cerrado = 0;
            /* asignar obstáculo según probabilidad */
            int p = rand() % 100;
            if (p < OBSTACULO_PROB) {
                mapa[i][j].tipo = OBSTACULO;
                mapa[i][j].coste = INF; /* intransitable */
            } else {
                mapa[i][j].tipo = LIBRE;
                /* coste aleatorio para atravesar la celda: 1..4 */
                mapa[i][j].coste = 1 + (rand() % 4);
            }
        }
    }
}
/* Imprimir mapa con leyenda S inicio, G fin, # obstáculo, . libre, * ruta */
void imprimir_mapa(int inicio_f, int inicio_c, int fin_f, int fin_c, int mark_route[FILAS][COLS]) {
    char s = 'S';
    char g = 'G';
    char asdt = 'o';
    char hast = 'X';
    char punto = '.';

    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (i == inicio_f && j == inicio_c) { printf(" %c ", s); continue; }
            if (i == fin_f && j == fin_c) { printf(" %c ", g); continue; }
            if (mark_route[i][j]) { printf(" %c ", asdt); continue; }
            if (mapa[i][j].tipo == OBSTACULO) printf(" %c ", hast);
            else printf(" %c ", punto);
        }
        putchar('\n');
    }
}

/* A* principal: devuelve 1 si encontró ruta, 0 si no */
int a_star(int inicio_f, int inicio_c, int fin_f, int fin_c) {
    /* inicializar inicio */
    for (int i = 0; i < FILAS; ++i)
        for (int j = 0; j < COLS; ++j) {
            mapa[i][j].padre_f = -1;
            mapa[i][j].padre_c = -1;
            mapa[i][j].g = INF;
            mapa[i][j].f = INF;
            mapa[i][j].h = 0;
            mapa[i][j].abierto = 0;
            mapa[i][j].cerrado = 0;
        }

    if (!es_valido(inicio_f, inicio_c) || !es_valido(fin_f, fin_c)) return 0;
    if (mapa[inicio_f][inicio_c].tipo == OBSTACULO) return 0;
    if (mapa[fin_f][fin_c].tipo == OBSTACULO) return 0;

    mapa[inicio_f][inicio_c].g = mapa[inicio_f][inicio_c].coste;
    mapa[inicio_f][inicio_c].h = heuristica_manhattan(inicio_f, inicio_c, fin_f, fin_c);
    mapa[inicio_f][inicio_c].f = mapa[inicio_f][inicio_c].g + mapa[inicio_f][inicio_c].h;
    mapa[inicio_f][inicio_c].abierto = 1;
    mapa[inicio_f][inicio_c].padre_f = -1;
    mapa[inicio_f][inicio_c].padre_c = -1;

    while (1) {
        int cf, cc;
        extraer_min_f(&cf, &cc);
        if (cf == -1) return 0; /* open vacío -> no hay ruta */
        if (cf == fin_f && cc == fin_c) return 1; /* encontrado */

        /* mover nodo actual de open a closed */
        mapa[cf][cc].cerrado = 1;

        /* explorar vecinos */
        for (int k = 0; k < 4; ++k) {
            int nf = cf + d4[k][0];
            int nc = cc + d4[k][1];
            if (!es_valido(nf, nc)) continue;
            if (mapa[nf][nc].tipo == OBSTACULO) continue;
            if (mapa[nf][nc].cerrado) continue;

            /* coste de moverse: aquí se usa coste de entrar en la celda vecina */
            int tentative_g = mapa[cf][cc].g + mapa[nf][nc].coste;
            if (!mapa[nf][nc].abierto || tentative_g < mapa[nf][nc].g) {
                mapa[nf][nc].padre_f = cf;
                mapa[nf][nc].padre_c = cc;
                mapa[nf][nc].g = tentative_g;
                mapa[nf][nc].h = heuristica_manhattan(nf, nc, fin_f, fin_c);
                mapa[nf][nc].f = mapa[nf][nc].g + mapa[nf][nc].h;
                mapa[nf][nc].abierto = 1;
            }
        }
    }
    return 0;
}

/* Programa principal de prueba */
int main(void) {
    generar_mapa_aleatorio();

    int inicio_f = 0, inicio_c = 0;
    int fin_f = FILAS - 1, fin_c = COLS - 1;

    /* asegurarnos que inicio y fin no sean obstáculos */
    mapa[inicio_f][inicio_c].tipo = LIBRE;
    mapa[inicio_f][inicio_c].coste = 1;
    mapa[fin_f][fin_c].tipo = LIBRE;
    mapa[fin_f][fin_c].coste = 1;

    int mark_route[FILAS][COLS] = {0};

    int found = a_star(inicio_f, inicio_c, fin_f, fin_c);

    if (found) {
        reconstruir_ruta(fin_f, fin_c, mark_route);
        printf("Ruta encontrada. Coste total: %d\n", mapa[fin_f][fin_c].g);
    } else {
        printf("No se encontró ruta desde S hasta G.\n");
    }

    imprimir_mapa(inicio_f, inicio_c, fin_f, fin_c, mark_route);

    return 0;
}
