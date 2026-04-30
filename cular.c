#include <stdio.h>
#include <string.h>

#define CAPACITY 20

typedef struct {
    char data[CAPACITY];
    int write_index;  
    int read_index;
    int current_size;   
} CircularQueue;

void initQueue(CircularQueue *queue) {
    queue->write_index = 0;
    queue->read_index = 0;
    queue->current_size = 0;
}

int isEmpty(const CircularQueue *queue) {
    return queue->current_size == 0;
}

int isFull(const CircularQueue *queue) {
    return queue->current_size == CAPACITY;
}

void enqueue(CircularQueue *queue, char val) {
    if (isFull(queue)) {
        printf("Error: Queue Overflow\n");
        return;
    }
    queue->data[queue->write_index] = val;
    queue->write_index = (queue->write_index + 1) % CAPACITY;
    queue->current_size++;
}

char dequeue(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Error: Queue Underflow\n");
        return '\0';
    }
    char val = queue->data[queue->read_index];
    queue->read_index = (queue->read_index + 1) % CAPACITY;
    queue->current_size--;
    return val;
}

int main() {
    CircularQueue myQueue;
    initQueue(&myQueue);

    char inputName[50];
    printf("Enter your name: ");
    scanf("%49s", inputName);
   
    strcat(inputName, "CE-ESY");

    for (int i = 0; i < (int)strlen(inputName); i++) {
        enqueue(&myQueue, inputName[i]);
    }
    while (!isEmpty(&myQueue)) {
        char ch = dequeue(&myQueue);
        printf("%c", ch);
    }
    printf("\n");

    return 0;
}
