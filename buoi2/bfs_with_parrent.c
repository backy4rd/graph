#include <stdio.h>
#include "../graph/dinh_dinh.c"
#include "../data_structure/queue.c"

void bfs(Graph graph, int vertex, int visited[], int parent[]) {
    Queue queue;
    make_null_queue(&queue);

    push(&queue, vertex);
    visited[vertex] = 1;
    while (!is_empty(queue)) {
        int a = shift(&queue);

        for (int i = 1; i <= graph.n; i++) {
            if (adjacent(graph, a, i) && !visited[i]) {
                visited[i] = 1;
                parent[i] = a;
                push(&queue, i);
            }
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
            bfs(G, i, visited, parent);
        }
    }

    for (int i = 1; i <= G.n; i++) {
        printf("%d %d\n", i, parent[i]);
    }


    printf("\n");
    return 0;
}

