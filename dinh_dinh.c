#include <stdio.h>
#define MAX_N 100

typedef struct {
    int matrix[MAX_N][MAX_N];
    int n, m;
} Graph;

void init_graph(Graph* pG, int n) {
    pG->n = n;
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            pG->matrix[i][j] = 0;
        }
    }
}

void add_edge(Graph* pG, int x, int y) {
    pG->matrix[x][y]++;
    pG->matrix[y][x]++;
    pG->m++;
}

int degree(Graph G, int x) {
    int deg = 0;
    for (int i = 0; i < G.n; i++) {
        deg += G.matrix[x][i];
    }

    return deg;
}

int adjacent(Graph G, int x, int y) {
    return G.matrix[x][y] != 0;
}

void neighbours(Graph G, int x) {
    for (int i = 0; i < G.n; i++) {
        if (adjacent(G, x, i)) {
            printf("%d ",i);
        }
    }
}
