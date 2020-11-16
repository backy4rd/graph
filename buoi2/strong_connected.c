#include <stdio.h>
#include "../graph/dinh_dinh_cohuong.c"

void dfs(Graph G, int vertex, int visited[]) {
    visited[vertex] = 1;

    for (int i = 1; i <= G.n; i++) {
        if (adjacent(G, i, vertex) && !visited[i]) {
            dfs(G, i, visited);
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

    int isStrongConnect = 1;

    for (int i = 1; i <= G.n; i++) {
        int visited[n + 1];
        for (int j = 1; j <= n; j++) {
            visited[j] = 0;
        }

        dfs(G, i, visited);


        for (int j = 1; j <= G.n; j++) {
            if (visited[j] == 0) {
                isStrongConnect = 0;
                i = G.n + 1;
                break;
            }
        }
    }


    if (isStrongConnect) {
        printf("strong connected");
    } else {
        printf("unconnected");
    }


    printf("\n");
}
