#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct
{
    int data[MAX];
    int front, rear;
} queue;

queue *createQueue(int size)
{
    if (size <= 0)
    {
        printf("Size can't be negative or zero.\n");
    }
    else
    {
        queue *queue = malloc(sizeof(size * sizeof(queue)));
        queue->front = queue->rear = -1;
        printf("Queue created of size %d.\n", size);
        printf("Queue initiallized.\n");
        return queue;
    }
}

void enqueue(queue *queue, int val)
{
    if (queue->rear == MAX - 1)
    {
        printf("Queue overflow.\n");
    }
    else if (queue->front && queue->rear == -1)
    {
        queue->front = queue->rear = 0;
        queue->data[queue->rear] = val;
    }
    else
    {
        queue->rear++;
        queue->data[queue->rear] = val;
    }
}
int dequeue(queue *queue)
{
    int val;
    if (queue->front && queue->rear == -1 || queue->front > queue->rear)
    {
        printf("Queue underflow.\n");
    }
    else
    {
        val = queue->data[queue->front];
        queue->front++;
        return val;
    }
}
int peek(queue *queue)
{
    int val;
    if (queue->front && queue->rear == -1 || queue->front > queue->rear)
    {
        printf("Queue underflow.\n");
    }
    else
    {
        val = queue->data[queue->front];
        return val;
    }
}
void display(queue *queue)
{
    for (int i = queue->front; i <= queue->rear; i++)
    {
        printf("%d <- ", queue->data[i]);
    }
    printf("\n");
}
void change(queue *queue, int pos, int val)
{
    int index = queue->front + pos - 1;
    if (index >= queue->front && index <= queue->rear)
    {
        queue->data[index] = val;
    }
    else
    {
        printf("Invalid position.\n");
    }
}
void main()
{
    queue *queue = createQueue(2);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 20);
}
