
#define MAX_LIST 500

typedef struct {
    int data[MAX_LIST];
    int size;
} List;

void make_null_list(List *list) {
    list->size = 0;
}

int is_empty(List list) {
	return list.size == 0;
}

void push(List *list, int key) {
    list->data[list->size] = key;
    list->size++;
}

int element_at(List list, int position) {
	return list.data[position - 1];
}
