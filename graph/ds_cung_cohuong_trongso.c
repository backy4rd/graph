#define MAX_M 500

typedef struct {
    int u, v, w;
} Edge;

typedef struct {
    Edge edges[MAX_M];
    int n, m;
} Graph;

void init_graph(Graph* pG, int n) {
    pG->n = n;
    pG->m = 0;
}

void add_edge(Graph* pG, int x, int y, int w) {
    pG->edges[pG->m] = (Edge){x, y, w};
    pG->m++;
}

int degree(Graph G, int x) {
    int deg = 0;
    for (int i = 1; i <= G.m; i++) {
        if (G.edges[i].u == x) deg++;
        if (G.edges[i].v == x) deg++;
    }

    return deg;
}

int adjacent(Graph G, int x, int y) {
    for (int i = 0; i < G.m; i++) {
        if (G.edges[i].u == x && G.edges[i].v == y) {
            return 1;
        }
    }

    return 0;
}

int get_weigth(Graph G, int x, int y) {
    for (int i = 0; i < G.m; i++) {
        if (G.edges[i].u == x && G.edges[i].v == y) {
            return G.edges[i].w;
        }
    }
    return -1;
}
