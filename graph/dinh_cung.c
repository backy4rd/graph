#define MAX_N 100
#define MAX_M 500

typedef struct {
 int A[MAX_N][MAX_M];
 int n, m;
} Graph;

void init_graph(Graph *pG, int n, int m) {
    pG->n = n;
    pG->m = m;

    for (int i = 1; i < MAX_N; i++) {
        for (int j = 1; j < MAX_M; j++) {
            pG->A[i][j] = 0;
        }
    }
}

void add_edge(Graph* pG, int e, int x, int y) {
    pG->A[x][e]++;
    pG->A[y][e]++;
}

int degree(Graph G, int x) {
    int deg = 0;
    for (int i = 1; i <= G.m; i++) {
        deg += G.A[x][i];
    }

    return deg;
}

int adjacent(Graph G, int x, int y) {
    for (int i = 1; i <= G.m; i++) {
        if (G.A[x][i] != 0 && G.A[y][i] != 0) {
            return 1;
        }
    }

    return 0;
}
