#include <stdio.h>
#include "../graph/ds_cung_cohuong_trongso.c"
#define INFINITY 100000

int pi[MAX_M];
int p[MAX_M];

void bellman_ford(Graph g, int x) {
    for (int i = 1; i <= g.n; i++) {
        pi[i] = INFINITY;
    }
    p[x] = -1;
    pi[x] = 0;

    for (int i = 1; i <= g.n; i++) {
        for (int j = 0; j < g.m; j++) {
            int u = g.edges[j].u;
            int v = g.edges[j].v;
            int w = g.edges[j].w;
            if (pi[u] + w < pi[v]) {
                pi[v] = pi[u] + w;
                p[v] = u;
            }
        }
    }
}

int main() {
    freopen("./input", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    Graph G;
    init_graph(&G, n);
    for (int i = 1; i <= m; i++) {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        add_edge(&G, x, y, w);
    }

    bellman_ford(G, 1);

    for (int i = 1; i <= G.n; i++) {
        printf("pi[%d] = %d, p[%d] = %d\n", i, pi[i], i, p[i]);
    }
/* pi[1] = 0, p[1] = -1 */


}
