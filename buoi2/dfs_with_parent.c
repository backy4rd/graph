#include <stdio.h>
#include "../graph/dinh_dinh.c"

void dfs(Graph G, int vertex, int visited[], int parent[]) {
    visited[vertex] = 1;

    for (int i = 1; i <= G.n; i++) {
        if (adjacent(G, i, vertex) && !visited[i]) {
            parent[i] = vertex;
            dfs(G, i, visited, parent);
        }
    }
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

    int visited[n + 1];
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
    }

    int parent[n + 1];
    for (int i = 1; i <= n; i++) {
        parent[i] = 0;
    }


    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(G, i, visited, parent);
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", i, parent[i]);
    }


    printf("\n");
    return 0;
}

