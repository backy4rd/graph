#include <stdio.h>
#include "../graph/ds_cung_cohuong_trongso.c"

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

    int total = 0;
    for (int i = 0; i < m; i++) {
        total += G.edges[i].w;
    }

    if (total < 0) {
        printf("negative cycle");
    } else {
        printf("ok");
    }
}
