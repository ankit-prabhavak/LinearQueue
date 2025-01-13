#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the queue

// Queue structure
typedef struct Queue {
    int arr[MAX];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initQueue(Queue* queue) {
    queue->front = -1;  // Queue is initially empty
    queue->rear = -1;
}

// Function to check if the queue is full
int isFull(Queue* queue) {
    return queue->rear == MAX - 1;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == -1;
}

// Function to add an element to the queue (enqueue)
void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full! Cannot enqueue %d.\n", value);
        return;
    }

    // If the queue is empty, set both front and rear to 0
    if (isEmpty(queue)) {
        queue->front = 0;
    }

    // Increment rear to add element
    queue->rear++;
    queue->arr[queue->rear] = value;
    printf("Enqueued %d\n", value);
}

// Function to remove an element from the queue (dequeue)
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }

    int value = queue->arr[queue->front];
    
    // If there's only one element left, reset the queue to empty
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        // Move front pointer to the next element
        queue->front++;
    }

    printf("Dequeued %d\n", value);
    return value;
}

// Function to get the element at the front of the queue
int front(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->arr[queue->front];
}

// Function to get the element at the rear of the queue
int rear(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->arr[queue->rear];
}

// Function to traverse and display all elements in the queue
void traverse(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Nothing to display.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

// Function to get the current size of the queue
int size(Queue* queue) {
    if (isEmpty(queue)) {
        return 0;
    }

    return queue->rear - queue->front + 1;
}

int main() {
   
    Queue queue;
    initQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);

    traverse(&queue);  // Output: 10 20 30 40 50

    printf("Front element: %d\n", front(&queue));  // Output: 10
    printf("Rear element: %d\n", rear(&queue));  // Output: 50

    dequeue(&queue);  // Output: Dequeued 10
    dequeue(&queue);  // Output: Dequeued 20
    printf("Peek: %d\n", rear(&queue));  // Output: 50

    traverse(&queue);  // Output: 30 40 50

    printf("Size of queue: %d\n", size(&queue));  // Output: 3

    return 0;
}
