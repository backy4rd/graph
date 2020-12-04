#define MAX_STACK 500

typedef struct {
    int data[MAX_STACK];
    int size;
} Stack;

void make_null_stack(Stack* stack) {
    stack->size = 0;
}

void push(Stack* stack, int x) {
    stack->data[stack->size] = x;
    stack->size++;
}

int pop(Stack* stack) {
    int top = stack->data[stack->size - 1];
    stack->size--;

    return top;
}

int is_stack_empty(Stack stack) {
    return stack.size == 0;
}
