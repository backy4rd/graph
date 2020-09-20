#include <stdio.h>

// uncomment each one to test library
/* #include "./ds_cung.c" */
/* #include "./dinh_dinh.c" */
#include "./ds_ke.c"

int main() {
    freopen("./input", "r", stdin);
    Graph G;
    int m, n;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);

        add_edge(&G, x, y);
    }

    // must fasle
    printf("0 <~~> 1: %s\n", adjacent(G, 0, 1) ? "true" : "false");

    // must true
    printf("6 <~~> 7: %s\n", adjacent(G, 6, 7) ? "true" : "false");

    // must equal 6
    printf("deg 4: %d\n", degree(G, 4));

    // must print 0 1 4
    printf("neighbours 5: ");
    neighbours(G, 5);

    printf("\n");
    return 0;
}
