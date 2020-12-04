#include <stdio.h>
#include "../graph/ds_cung_cohuong.c"
#include "../data_structure/stack.c"
#include "../data_structure/list.c"
#define INFINITY 9999999

void ranking_graph(Graph graph, int rank[]) {
    int degs[graph.n + 1];
    Stack s1, s2;
    make_null_stack(&s1);

    for (int i = 1; i <= graph.n; i++) {
        degs[i] = in_degree(graph, i);
        if (degs[i] == 0) {
            push(&s1, i);
        }
    }

    for (int current_rank = 0; !is_stack_empty(s1); current_rank++) {
        make_null_stack(&s2);
        while (!is_stack_empty(s1)) {
            int u = pop(&s1);
            rank[u] = current_rank;

            for (int v = 1; v <= graph.n; v++) {
                if (adjacent(graph, u, v)) {
                    degs[v]--;
                    if (degs[v] == 0) {
                        push(&s2, v);
                    }
                }
            }
        }

        s1 = s2;
    }
}

List topo_sort(int rank[], int n) {
    int highest_rank = -1;
    List topo;
    make_null_list(&topo);

    for (int i = 1; i <= n; i++) {
        if (highest_rank < rank[i]) highest_rank = rank[i];
    }
    for (int i = 0; i <= highest_rank; i++) {
        for (int v = 1; v <= n; v++) {
            if (rank[v] == i) {
                push_back(&topo, v);
            }
        }
    }

    return topo;
}

void organize_construction(Graph graph, int d[], int rank[], int earliest[], int latest[]) {
    Graph temp = graph;

    // add alpha and beta
    for (int i = 1; i <= graph.n; i++) {
        if (in_degree(graph, i) == 0) {
            add_edge(&temp, 0, i);
        }
        if (out_degree(graph, i) == 0) {
            add_edge(&temp, i, graph.n + 1);
        }

    }

    d[0] = 0; // alpha job
    List topo = topo_sort(rank, graph.n);
    push_back(&topo, graph.n + 1); // insert beta job as hight rank

    // calculate earliest start time
    for (int i = 1; i <= topo.size; i++) {
        int v = element_at(topo, i);
        earliest[v] = 0;
        for (int u = 1; u <= temp.n; u++) {
            if (adjacent(temp, u, v) && earliest[v] < d[u] + earliest[u]) {
                earliest[v] = d[u] + earliest[u];
            }
        }
    }

    // calculate latest start time
    for (int i = topo.size; i >= 1; i--) {
        int u = element_at(topo, i);
        int latest_time = INFINITY;
        for (int v = 1; v <= temp.n; v++) {
            if (adjacent(temp, u, v) && latest_time > latest[v] - d[u]) {
                latest_time = latest[v] - d[u];
            }
        }

        if (latest_time == INFINITY) {
            latest[u] = earliest[u];
        } else {
            latest[u] = latest_time;
        }
    }
}

int main() {
    freopen("./input", "r", stdin);
    Graph G;
    int n;
    scanf("%d", &n);
    int d[n + 1];
    init_graph(&G, n);

    for (int u = 1; u <= n; u++) {
        int v;
        scanf("%d", &d[u]);

        do {
            scanf("%d", &v);
            if (v != 0) {
                add_edge(&G, v, u);
            }
        } while (v != 0);
    }

    int rank[n + 1], earliest[n + 2], latest[n + 2];

    ranking_graph(G, rank);
    organize_construction(G, d, rank, earliest, latest);

    printf("%d\n", earliest[n + 1]); // earliest time to complete the construction
    for (int i = 1; i <= n; i++) {
        printf("%d-%d\n", earliest[i], latest[i]);
    }
    printf("0-0\n"); // print alpha
    printf("%d-%d\n", earliest[n + 1], latest[n + 1]); // print beta

    printf("\n");
    return 0;
}
