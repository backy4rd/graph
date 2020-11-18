#include <stdio.h>
#include "../graph/dinh_dinh_trongso.c"
#include "../data_structure/list.c"
#define INFINITY 100000

int visited[MAX_N];

int distance_from(int u, List list, Graph graph) {
    int min_w = INFINITY;
    int min_v = -1;
    for (int i = 1; i <= list.size; i++) {
        int v = element_at(list, i);
        if (adjacent(graph, u, v) && min_w > graph.A[u][v]) {
            min_w = graph.A[u][v];
            min_v = v;
        }
    }
    return min_v;
}

int prim(Graph g, Graph* tree) {
    for (int i = 1; i <= g.n; i++) {
        visited[i] = 0;
    }
    
    int sum_weight = 0;
    List list;
    init_graph(tree, g.n);
    make_null_list(&list);
    
    push(&list, 1);
    visited[1] = 1;
    
    for (int i = 1; i < g.n; i++) {
        int min_w = INFINITY, min_u, min_v;

        for (int u = 1; u <= g.n; u++) {
            if (visited[u]) continue;
            
            int v = distance_from(u, list, g);
            if (v != -1 && g.A[u][v] < min_w) {
                min_w = g.A[u][v];
                min_u = u;
                min_v = v;
            }
        }
        
        push(&list , min_u);
        visited[min_u] = 1;
        add_edge(tree, min_u, min_v, min_w);
        sum_weight += min_w;
    }
    
    return sum_weight;
}

int main() {
    freopen("../input", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    Graph G, tree;
    init_graph(&G, n);
    for (int i = 1; i <= m; i++) {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        add_edge(&G, x, y, w);
    }

    int total_weight = prim(G, &tree);

    printf("%d\n", total_weight);
    for (int u = 1; u <= tree.n; u++) {
        int hasLine = 0;
        for (int v = 1; v <= u; v++) {
            if (adjacent(tree, u, v)) {
                printf("%d %d %d", v, u, tree.A[u][v]);
                hasLine = 1;
            }
        }
        if (hasLine) printf("\n");
    }

    return 1;
}
