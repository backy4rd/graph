
#define MAX_N 100

typedef struct {
    int A[MAX_N][MAX_N];
    int n, m;
} Graph;

void init_graph(Graph* pG, int n) {
    pG->n = n;
    for (int i = 1; i < MAX_N; i++) {
        for (int j = 1; j < MAX_N; j++) {
            pG->A[i][j] = 0;
        }
    }
}

void add_edge(Graph* pG, int x, int y) {
    pG->A[x][y]++;
    pG->m++;
}

int degree(Graph G, int x) {
    int deg = 0;
    for (int i = 1; i <= G.n; i++) {
        deg += G.A[x][i];
    }

    return deg;
}

int adjacent(Graph G, int x, int y) {
    return G.A[x][y] != 0;
}
