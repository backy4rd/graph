#define MAX_QUEUE 500

typedef struct {
    int data[MAX_QUEUE];
    int front;
    int rear;
} Queue;


void make_null_queue(Queue *queue) {
    queue->front = 0;
    queue->rear = 0;
}

int is_empty(Queue queue) {
	return queue.front == queue.rear;
}

void push(Queue *queue, int key) {
    queue->data[queue->rear] = key;
    queue->rear++;
}

int shift(Queue *queue) {
    int front = queue->data[queue->front];
    queue->front++;

    if (is_empty(*queue)) {
        make_null_queue(queue);
    }

    return front;
}
