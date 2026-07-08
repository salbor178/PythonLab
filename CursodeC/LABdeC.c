#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <math.h>

#define OBSTACULO_PROB 25 /* probabilidad % por defecto de obstáculo */
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

/* variables del mapa (dinámicas) */
static Nodo *mapa = NULL; /* acceso: mapa[f * cols + c] */
static int filas = 0;
static int cols = 0;
static int obst_prob = OBSTACULO_PROB;

/* movimientos 4-direcciones */
const int d4[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

/* helpers para acceso y validación */
int es_valido(int f, int c) {
    return f >= 0 && f < filas && c >= 0 && c < cols;
}
Nodo *celda(int f, int c) {
    return &mapa[f * cols + c];
}

/* heurística Manhattan */
int heuristica_manhattan(int f1, int c1, int f2, int c2) {
    return abs(f1 - f2) + abs(c1 - c2);
}

/* extraer min f (búsqueda lineal) */
void extraer_min_f(int *out_f, int *out_c) {
    int mejor_f = INF;
    int mf = -1, mc = -1;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < cols; ++j) {
            Nodo *n = celda(i,j);
            if (n->abierto && !n->cerrado) {
                if (n->f < mejor_f) {
                    mejor_f = n->f;
                    mf = i; mc = j;
                }
            }
        }
    }
    *out_f = mf; *out_c = mc;
}

/* reconstruir ruta marcando mark_route */
int reconstruir_ruta(int fin_f, int fin_c, int *mark_route) {
    Nodo *nfin = celda(fin_f, fin_c);
    if (nfin->g == INF) return 0;
    int f = fin_f, c = fin_c, len = 0;
    while (!(celda(f,c)->padre_f == -1 && celda(f,c)->padre_c == -1)) {
        mark_route[f * cols + c] = 1;
        int pf = celda(f,c)->padre_f;
        int pc = celda(f,c)->padre_c;
        f = pf; c = pc;
        ++len;
        if (len > filas * cols) break;
    }
    mark_route[f * cols + c] = 1; /* marcar inicio */
    return 1;
}

/* (Re)inicializar estructura del mapa en memoria */
int reservar_mapa(int nf, int nc) {
    if (nf <= 0 || nc <= 0) return 0;
    Nodo *nuevo = realloc(mapa, sizeof(Nodo) * nf * nc);
    if (!nuevo) return 0;
    mapa = nuevo;
    filas = nf; cols = nc;
    return 1;
}

/* generar mapa aleatorio (obstaculos y costes) */
void generar_mapa_aleatorio(void) {
    if (filas == 0 || cols == 0) {
        printf("Antes de generar, seleccione tamaño del mapa (opción 1).\n");
        return;
    }
    /* seed una sola vez */
    static int seeded = 0;
    if (!seeded) { srand((unsigned)time(NULL)); seeded = 1; }

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < cols; ++j) {
            Nodo *n = celda(i,j);
            n->padre_f = -1;
            n->padre_c = -1;
            n->g = INF;
            n->f = INF;
            n->h = 0;
            n->abierto = 0;
            n->cerrado = 0;
            int p = rand() % 100;
            if (p < obst_prob) {
                n->tipo = OBSTACULO;
                n->coste = INF;
            } else {
                n->tipo = LIBRE;
                n->coste = 1 + (rand() % 4);
            }
        }
    }
}

/* establecer obstaculo o quitarlo */
void set_obstaculo(int f, int c, int poner) {
    if (!es_valido(f,c)) {
        printf("Coordenadas fuera de rango.\n");
        return;
    }
    Nodo *n = celda(f,c);
    if (poner) {
        n->tipo = OBSTACULO;
        n->coste = INF;
    } else {
        n->tipo = LIBRE;
        n->coste = 1;
    }
}

/* imprimir mapa (mark_route puede ser NULL) */
void imprimir_mapa(int inicio_f, int inicio_c, int fin_f, int fin_c, int *mark_route) {
    if (filas == 0 || cols == 0) {
        printf("Mapa no inicializado. Seleccione tamaño y genere mapa.\n");
        return;
    }
    char s = 'S';
    char g = 'G';
    char asdt = 'o';
    char hast = 'X';
    char punto = '.';
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == inicio_f && j == inicio_c) { printf(" %c ", s); continue; }
            if (i == fin_f && j == fin_c) { printf(" %c ", g); continue; }
            if (mark_route && mark_route[i * cols + j]) { printf(" %c ", asdt); continue; }
            if (celda(i,j)->tipo == OBSTACULO) printf(" %c ", hast);
            else printf(" %c ", punto);
        }
        putchar('\n');
    }
}

/* A* principal */
int a_star(int inicio_f, int inicio_c, int fin_f, int fin_c) {
    if (!es_valido(inicio_f,inicio_c) || !es_valido(fin_f,fin_c)) return 0;
    if (celda(inicio_f,inicio_c)->tipo == OBSTACULO) return 0;
    if (celda(fin_f,fin_c)->tipo == OBSTACULO) return 0;

    for (int i = 0; i < filas; ++i)
        for (int j = 0; j < cols; ++j) {
            Nodo *n = celda(i,j);
            n->padre_f = -1;
            n->padre_c = -1;
            n->g = INF;
            n->f = INF;
            n->h = 0;
            n->abierto = 0;
            n->cerrado = 0;
        }

    Nodo *start = celda(inicio_f,inicio_c);
    start->g = start->coste;
    start->h = heuristica_manhattan(inicio_f,inicio_c,fin_f,fin_c);
    start->f = start->g + start->h;
    start->abierto = 1;
    start->padre_f = -1; start->padre_c = -1;

    while (1) {
        int cf, cc;
        extraer_min_f(&cf, &cc);
        if (cf == -1) return 0; /* open vacío */
        if (cf == fin_f && cc == fin_c) return 1;

        Nodo *actual = celda(cf,cc);
        actual->cerrado = 1;

        for (int k = 0; k < 4; ++k) {
            int nf = cf + d4[k][0];
            int nc = cc + d4[k][1];
            if (!es_valido(nf,nc)) continue;
            Nodo *vec = celda(nf,nc);
            if (vec->tipo == OBSTACULO) continue;
            if (vec->cerrado) continue;

            int tentative_g = actual->g + vec->coste;
            if (!vec->abierto || tentative_g < vec->g) {
                vec->padre_f = cf;
                vec->padre_c = cc;
                vec->g = tentative_g;
                vec->h = heuristica_manhattan(nf,nc,fin_f,fin_c);
                vec->f = vec->g + vec->h;
                vec->abierto = 1;
            }
        }
    }
    return 0;
}

/* Menú y lectura segura */
void mostrar_menu(void) {
    printf("\n--- MENU ---\n");
    printf("1) Seleccionar tamano del mapa (filas, columnas)\n");
    printf("2) Generar Mapa Aleatorio (con probabilidad %d%%)\n", obst_prob);
    printf("3) Quitar o Agregar Obstaculos al mapa\n");
    printf("4) Mostrar Mapa (antes del recorrido)\n");
    printf("5) Seleccionar posicion de Inicio y Meta\n");
    printf("6) Iniciar Busqueda del Camino (A*)\n");
    printf("0) Salir\n");
    printf("Elija una opcion: ");
}

int leer_entero(void) {
    int x;
    if (scanf("%d", &x) != 1) {
        int c; while ((c = getchar()) != EOF && c != '\n');
        return INT_MIN;
    }
    return x;
}

/* Programa principal */
int main(void) {
    int inicio_f = 0, inicio_c = 0;
    int fin_f = 0, fin_c = 0;
    int *mark_route = NULL;

    while (1) {
        mostrar_menu();
        int opc = leer_entero();
        if (opc == INT_MIN) { printf("Entrada invalida. Intente de nuevo.\n"); continue; }

        if (opc == 0) break;

        if (opc == 1) {
            printf("Ingrese numero de filas (>0): ");
            int nf = leer_entero();
            if (nf <= 0) { printf("Filas invalidas.\n"); continue; }
            printf("Ingrese numero de columnas (>0): ");
            int nc = leer_entero();
            if (nc <= 0) { printf("Columnas invalidas.\n"); continue; }
            if (!reservar_mapa(nf,nc)) { printf("Error al reservar memoria para el mapa.\n"); continue; }
            /* liberar/crear mark_route */
            free(mark_route);
            mark_route = calloc(filas * cols, sizeof(int));
            if (!mark_route) { printf("Advertencia: no se pudo reservar mark_route.\n"); }
            /* ajustar posiciones por defecto */
            inicio_f = 0; inicio_c = 0;
            fin_f = filas - 1; fin_c = cols - 1;
            printf("Tamaño de mapa establecido a %d x %d. Inicio=(%d,%d), Meta=(%d,%d)\n",
                   filas, cols, inicio_f, inicio_c, fin_f, fin_c);
        } else if (opc == 2) {
            if (filas == 0 || cols == 0) { printf("Primero seleccione el tamano del mapa (opcion 1).\n"); continue; }
            printf("Usar probabilidad por defecto %d%%? 1=Si 2=No: ", obst_prob);
            int r = leer_entero();
            if (r == 2) {
                printf("Ingrese probabilidad (%) de obstaculos [0-100]: ");
                int p = leer_entero();
                if (p < 0 || p > 100) { printf("Probabilidad invalida.\n"); continue; }
                obst_prob = p;
            }
            generar_mapa_aleatorio();
            /* asegurar inicio y fin libres */
            if (es_valido(inicio_f,inicio_c)) { celda(inicio_f,inicio_c)->tipo = LIBRE; celda(inicio_f,inicio_c)->coste = 1; }
            if (es_valido(fin_f,fin_c)) { celda(fin_f,fin_c)->tipo = LIBRE; celda(fin_f,fin_c)->coste = 1; }
            /* limpiar marcas */
            if (mark_route) for (int i = 0; i < filas*cols; ++i) mark_route[i] = 0;
            printf("Mapa aleatorio generado.\n");
        } else if (opc == 3) {
            if (filas == 0 || cols == 0) { printf("Primero seleccione el tamano del mapa (opcion 1).\n"); continue; }
            printf("Ingrese fila y columna (0..%d  0..%d): ", filas-1, cols-1);
            int f = leer_entero(); int c = leer_entero();
            if (!es_valido(f,c)) { printf("Coordenadas fuera de rango.\n"); continue; }
            printf("1) Poner obstaculo  2) Quitar obstaculo\nElija: ");
            int accion = leer_entero();
            if (accion == 1) { set_obstaculo(f,c,1); printf("Obstaculo puesto en (%d,%d).\n", f,c); }
            else if (accion == 2) { set_obstaculo(f,c,0); printf("Obstaculo quitado en (%d,%d).\n", f,c); }
            else printf("Accion invalida.\n");
        } else if (opc == 4) {
            if (filas == 0 || cols == 0) { printf("Primero seleccione el tamano del mapa (opcion 1).\n"); continue; }
            imprimir_mapa(inicio_f, inicio_c, fin_f, fin_c, NULL);
        } else if (opc == 5) {
            if (filas == 0 || cols == 0) { printf("Primero seleccione el tamano del mapa (opcion 1).\n"); continue; }
            printf("Ingrese fila y columna de inicio (0..%d 0..%d): ", filas-1, cols-1);
            int f1 = leer_entero(); int c1 = leer_entero();
            if (!es_valido(f1,c1)) { printf("Coordenadas inicio fuera de rango.\n"); continue; }
            printf("Ingrese fila y columna de meta (0..%d 0..%d): ", filas-1, cols-1);
            int f2 = leer_entero(); int c2 = leer_entero();
            if (!es_valido(f2,c2)) { printf("Coordenadas meta fuera de rango.\n"); continue; }
            inicio_f = f1; inicio_c = c1;
            fin_f = f2; fin_c = c2;
            /* asegurar que inicio y meta no sean obstaculos */
            celda(inicio_f,inicio_c)->tipo = LIBRE; celda(inicio_f,inicio_c)->coste = 1;
            celda(fin_f,fin_c)->tipo = LIBRE; celda(fin_f,fin_c)->coste = 1;
            printf("Inicio establecido en (%d,%d). Meta en (%d,%d).\n", inicio_f, inicio_c, fin_f, fin_c);
        } else if (opc == 6) {
            if (filas == 0 || cols == 0) { printf("Primero seleccione el tamano del mapa (opcion 1).\n"); continue; }
            if (!mark_route) {
                mark_route = calloc(filas * cols, sizeof(int));
                if (!mark_route) { printf("No se pudo reservar memoria para mark_route.\n"); continue; }
            }
            for (int i = 0; i < filas*cols; ++i) mark_route[i] = 0;
            int found = a_star(inicio_f, inicio_c, fin_f, fin_c);
            if (found) {
                reconstruir_ruta(fin_f, fin_c, mark_route);
                printf("Ruta encontrada. Coste total: %d\n", celda(fin_f,fin_c)->g);
                imprimir_mapa(inicio_f, inicio_c, fin_f, fin_c, mark_route);
            } else {
                printf("No se encontro ruta desde S hasta G.\n");
                imprimir_mapa(inicio_f, inicio_c, fin_f, fin_c, NULL);
            }
        } else {
            printf("Opcion invalida. Intente de nuevo.\n");
        }
    }

    free(mapa);
    return 0;
}