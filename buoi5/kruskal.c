#include <stdio.h>
#include "../graph/ds_cung_trongso.c"
#include "../data_structure/disjoint_set.c"

void swap_edge(Edge* a, Edge* b) {
    Edge temp = *a;
    *a = *b;
    *b = temp;
}

void sort_graph(Graph* graph) {
    for (int i = 0; i < graph->m; i++) {
        for (int j = i + 1; j < graph->m; j++) {
            int u1 = graph->edges[i].u;
            int v1 = graph->edges[i].v;
            int w1 = graph->edges[i].w;
            int u2 = graph->edges[j].u;
            int v2 = graph->edges[j].v;
            int w2 = graph->edges[j].w;

            if (w1 > w2) {
                swap_edge(&graph->edges[i], &graph->edges[j]);
            } else if (w1 == w2 && u1 > u2) {
                swap_edge(&graph->edges[i], &graph->edges[j]);
            } else if (w1 == w2 && u1 == u2 && v1 > v2) {
                swap_edge(&graph->edges[i], &graph->edges[j]);
            }
        }
    }
}

int kruskal(Graph graph, Graph* tree) {
    int set[graph.m + 1];
    int min_weight = 0;

    init_graph(tree, graph.n);
    make_null_set(set, graph.m + 1);
    sort_graph(&graph);

    for (int i = 0; i < graph.m && tree->m < graph.n; i++) {
        int u = graph.edges[i].u;
        int v = graph.edges[i].v;
        int w = graph.edges[i].w;

        if (union_set(set, u, v)) {
            min_weight += w;
            int u1 = u < v ? u : v;
            int v1 = u > v ? u : v;
            add_edge(tree, u1, v1, w);
        }
    }

    return min_weight;
}

int main() {
    freopen("./input", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    Graph G, tree;
    init_graph(&G, n);
    for (int i = 1; i <= m; i++) {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        add_edge(&G, x, y, w);
    }

    int min_weight = kruskal(G, &tree);

    printf("%d\n", min_weight);
    for (int i = 0; i < tree.m; i++) {
        printf("%d %d %d\n", tree.edges[i].u, tree.edges[i].v, tree.edges[i].w);
    }
}

