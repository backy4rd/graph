/* #include <stdio.h> */
/* #include "../data_structure/disjoint_set.c" */

/* int main() { */
/*     freopen("./input", "r", stdin); */
/*     int m, n; */
/*     scanf("%d%d", &n, &m); */

/*     int chu_trinh = 0; */
/*     int set[n + 1]; */
/*     make_null_set(set, n + 1); */

/*     for (int i = 1; i <= m; i++) { */
/*         int x, y; */
/*         scanf("%d%d", &x, &y); */
/*         if (!union_set(set, x, y)) { */
/*             chu_trinh = 1; */
/*             break; */
/*         } */
/*     } */

/*     if (chu_trinh) { */
/*         printf("YES"); */
/*     } else { */
/*         printf("NO"); */
/*     } */

/*     return 0; */
/* } */

#include <stdio.h>
#include "../graph/dinh_dinh.c"

int main() {
    freopen("./input", "r", stdin);
    int m, n;
    scanf("%d%d", &n, &m);

    Graph G;
    init_graph(&G, n);

    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);

        add_edge(&G, x, y);
    }

    int total_deg = 0;
    for (int i = 1; i <= G.n; i++) {
        total_deg += degree(G, i);
    }

    printf("%d %d\n", total_deg, G.n);

    if (total_deg / 2 < G.n) {
        printf("NO");
    } else {
        printf("YES");
    }

    return 0;
}
