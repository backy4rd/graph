#include <stdio.h>
#include "../graph/ds_cung_cohuong.c"
#include "../data_structure/list.c"

void ranking_graph(Graph graph, int rank[]) {
    int degs[graph.n + 1];
    List s1, s2;
    make_null_list(&s1);

    for (int i = 1; i <= graph.n; i++) {
        degs[i] = in_degree(graph, i);
        if (degs[i] == 0) {
            push_back(&s1, i);
        }
    }

    for (int current_rank = 0; !is_list_empty(s1); current_rank++) {
        make_null_list(&s2);
        for (int i = 1; i <= s1.size; i++) {
            int u = element_at(s1, i);
            rank[u] = current_rank;

            for (int v = 1; v <= graph.n; v++) {
                if (adjacent(graph, u, v)) {
                    degs[v]--;
                    if (degs[v] == 0) {
                        push_back(&s2, v);
                    }
                }
            }
        }

        s1 = s2;
    }
}

int main() {
    freopen("input", "r", stdin);
    Graph G;
    int m, n;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);

        add_edge(&G, x, y);
    }

    int rank[G.n + 1];
    ranking_graph(G, rank);

    for (int i = 1; i <= G.n; i++) {
        printf("%d\n", rank[i]);
    }

    return 0;
}
