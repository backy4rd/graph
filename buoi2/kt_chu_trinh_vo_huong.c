#include <stdio.h>
#include "../graph/dinh_dinh.c"

int is_vertex_make_cycle(Graph G, int vertex, int parent, int mark[]) {
    mark[vertex] = 1;

    for (int i = 1; i <= G.n; i++) {
        if (adjacent(G, i, vertex) && mark[i] != 2 && i != parent) {
            if (mark[i] == 0) {
                if (is_vertex_make_cycle(G, i, vertex, mark)) return 1;
            } else return 1;
        }
    }

    mark[vertex] = 2;
    return 0;
}

int is_graph_have_cycle(Graph graph) {
    int mark[graph.n + 1];
    for (int i = 1; i <= graph.n + 1; i++) {
        mark[i] = 0;
    }

    for (int i = 1; i <= graph.n; i++) {
        if (mark[i] == 0) {
            int cycle = is_vertex_make_cycle(graph, i, -1, mark);
            if (cycle) return 1;
        }
    }

    return 0;
}

int main() {
    freopen("./input", "r", stdin);
    Graph G;
    int m, n;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);

        add_edge(&G, x, y);
    }

    int cycle = is_graph_have_cycle(G);

    if (cycle) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}
