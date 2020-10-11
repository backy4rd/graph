#define MAX_N 100

typedef struct {
    int data[MAX_N];
    int size;
} List;

typedef struct {
    List adj[MAX_N];
    int n, m;
} Graph;

// ---------List-----------
void make_null(List* pL) {
    pL->size = 0;
}

void push_back(List* pL, int x) {
    pL->data[pL->size] = x;
    pL->size++;
}

int element_at(List L, int p) {
    return L.data[p - 1];
}

int size(List L) {
    return L.size;
}
// -----------------------

void init_graph(Graph* pG, int n) {
    pG->n = n;
    for (int i = 0; i < MAX_N; i++) {
        make_null(&pG->adj[i]);
    }
}

void add_edge(Graph* pG, int x, int y) {
    push_back(&pG->adj[x], y);
    push_back(&pG->adj[y], x);
    pG->m++;
}

int degree(Graph G, int x) {
    return size(G.adj[x]);
}

int adjacent(Graph G, int x, int y) {
    for (int i = 1; i <= size(G.adj[x]); i++) {
        if (element_at(G.adj[x], i) == y) {
            return 1;
        }
    }

    return 0;
}
