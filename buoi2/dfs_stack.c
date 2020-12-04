#include <stdio.h>
#include "../graph/dinh_dinh.c"
#include "../data_structure/stack.c"

void dfs(Graph G, int x, int visited[]) {
    Stack stack;
    make_null_stack(&stack);
    push(&stack,x);

    while(!is_stack_empty(stack)) {
        int top = pop(&stack);
        if(visited[top]!=0) continue;

        printf("%d\n",top);
        visited[top] = 1;
        for (int i = 1; i <= G.n; i++) {
            if (adjacent(G, i, top) && !visited[i]) {
                push(&stack, i);
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

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(G, i, visited);
        }
    }


    printf("\n");
    return 0;
}
