#define MAX_LIST 500

typedef int ElementType;

typedef struct {
    ElementType data[MAX_LIST];
    int size;
} List;

void make_null_list(List *list) {
    list->size = 0;
}

int is_list_empty(List list) {
    return list.size == 0;
}

void push_back(List *list, ElementType key) {
    list->data[list->size] = key;
    list->size++;
}

int element_at(List list, int position) {
    return list.data[position - 1];
}

int position(List list, ElementType target) {
    for (int i = 1; i <= list.size; i++) {
        if (element_at(list, i) == target) {
            return i;
        }
    }

    return -1;
}
