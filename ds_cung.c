#include <stdio.h>
#define MAX_M 500

typedef struct {
    int u, v;
} Edge;

typedef struct {
    Edge edges[MAX_M];
    int n, m;
} Graph;

void init_graph(Graph* pG, int n) {
    pG->n = n;
    pG->m = 0;
}

void add_edge(Graph* pG, int x, int y) {
    pG->edges[pG->m] = (Edge){x, y};
    pG->m++;
}

int degree(Graph G, int x) {
    int count = 0;
    for (int i = 0; i < G.m; i++) {
        if (G.edges[i].u == x) count++;
        if (G.edges[i].v == x) count++;
    }

    return count;
}

int adjacent(Graph G, int x, int y) {
    for (int i = 0; i < G.m; i++) {
        if (
            (G.edges[i].u == x && G.edges[i].v == y) ||
            (G.edges[i].u == y && G.edges[i].v == x)
        ) {
            return 1;
        }
    }

    return 0;
}

void neighbours(Graph G, int x) {
    for (int i = 0; i < G.m; i++) {
        if (G.edges[i].u == x) {
            printf("%d ", G.edges[i].v);
        } else if (G.edges[i].v == x) {
            printf("%d ", G.edges[i].u);
        }
    }
}

