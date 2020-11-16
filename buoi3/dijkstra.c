#include <stdio.h>
#include "../graph/dinh_dinh_trongso.c"
#define INFINITY 100000

int visited[MAX_N];
int pi[MAX_N];
int p[MAX_N];

void find_path(int p[], int x) {
    if (p[x] == -1) {
        printf("%d ", x);
        return;
    }
    find_path(p, p[x]);
    printf("%d ", x);
}

void dijkstra(Graph g, int x) {
    for (int i = 1; i <= g.n; i++) {
        visited[i] = 0;
        pi[i] = INFINITY;
    }
    p[x] = -1;
    pi[x] = 0;

    for (int i = 1; i <= g.n; i++) {
        int min_pi = INFINITY;
        int min_p;
        for (int j = 1; j <= g.n; j++) {
            if (pi[j] < min_pi && visited[j] == 0) {
                min_pi = pi[j];
                min_p = j;
            }
        }

        visited[min_p] = 1;
        for (int j = 1; j <= g.n; j++) {
            if (adjacent(g, min_p, j) && !visited[j]) {
                if (pi[min_p] + g.A[min_p][j] < pi[j]) {
                    pi[j] = pi[min_p] + g.A[min_p][j];
                    p[j] = min_p;
                }
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

    dijkstra(G, 1);

    /* for (int i = 1; i <= G.n; i++) { */
    /*     printf("%d ", pi[i]); */
    /* } */
    /* printf("%d", pi[n]); */

    /* find_path(p, 6); */

    return 1;
}
