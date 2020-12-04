#include <stdio.h>
#include "../graph/ds_cung.c"
#include "../data_structure/list.c"
#include "../data_structure/disjoint_set.c"

int main() {
    freopen("./input", "r", stdin);
    Graph graph;
    int m, n;
    scanf("%d%d", &n, &m);
    init_graph(&graph, n);
    int set[n + 1];
    make_null_set(set, n + 1);


    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);

        add_edge(&graph, x, y);
        if (!union_set(set, x, y)) {
            printf("IMPOSSIBLE");
            return 0;
        }
    }

    List a, b;
    make_null_list(&a);
    make_null_list(&b);
    push_back(&a, graph.edges[0].u);
    push_back(&b, graph.edges[0].v);

    for (int i = 1; i < m; i++) {
        int u = graph.edges[i].u;
        int v = graph.edges[i].v;

        if (position(a, u) != -1) {
            push_back(&b, v);
        } else {
            push_back(&a, v);
        }
    }

    for (int i = 1; i <= a.size; i++) {
        printf("%d ", element_at(a, i));
    }
    printf("\n");
    for (int i = 1; i <= b.size; i++) {
        printf("%d ", element_at(b, i));
    }


    return 0;
}
