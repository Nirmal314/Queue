#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct
{
    int data[MAX];
    int front, rear;
} queue;

void init(queue *queue)
{
    queue->front = queue->rear = -1;
    printf("Queue initiallized.\n\n");
}
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
        printf("\nQueue created of size %d.\n", size);
        printf("Queue initiallized.\n\n");
        return queue;
    }
}

void enqueue(queue *queue, int val)
{
    if (queue->rear == MAX - 1)
    {
        printf("\nQueue overflow.\n\n");
    }
    else if (queue->front && queue->rear == -1)
    {
        queue->front = queue->rear = 0;
        queue->data[queue->rear] = val;
        printf("\n%d enqueued !\n\n", val);
    }
    else
    {
        queue->rear++;
        queue->data[queue->rear] = val;
        printf("\n%d enqueued !\n\n", val);
    }
}
int dequeue(queue *queue)
{
    int val;
    if (queue->front && queue->rear == -1 || queue->front > queue->rear)
    {
        printf("\nQueue underflow.\n\n");
        return 0;
    }
    else
    {
        val = queue->data[queue->front];
        queue->front++;
        printf("\n%d dequeued !\n\n", val);
        return val;
    }
}
int peek(queue *queue)
{
    int val;
    if (queue->front && queue->rear == -1 || queue->front > queue->rear)
    {
        printf("\nQueue underflow.\n\n");
    }
    else
    {
        val = queue->data[queue->front];
        printf("\nFront value is %d.\n\n", val);
        return val;
    }
}
void display(queue *queue)
{
    printf("\n");
    for (int i = queue->front; i <= queue->rear; i++)
    {
        printf("%d <- ", queue->data[i]);
    }
    printf("\n\n");
}
void change(queue *queue, int pos, int val)
{
    int index = queue->front + pos - 1;
    int bef;
    if (index >= queue->front && index <= queue->rear)
    {
        bef = queue->data[index];
        queue->data[index] = val;
        printf("\nValue changed to %d from %d !\n\n", val,bef);
    }
    else
    {
        printf("\nInvalid position.\n\n");
    }
}

void main()
{
    queue *queue = malloc(sizeof(queue) * MAX);
    init(queue);
    // queue *queue = createQueue(3);
    int en, deq, c, p, pos, val;
    while (1)
    {
        printf("1.Enqueue\n2.Dequeue\n3.Peek\n4.Change\n5.Display\n6.Exit\n");
        printf("\nWhich operation you want to perform ? : ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Enter value : ");
            scanf("%d", &en);
            enqueue(queue, en);
            break;
        case 2:
            deq = dequeue(queue);
            break;
        case 3:
            p = peek(queue);
            break;
        case 4:
            printf("Enter position : ");
            scanf("%d", &pos);
            printf("Enter new value : ");
            scanf("%d", &val);
            change(queue, pos, val);
            break;
        case 5:
            display(queue);
            break;
        case 6:
            printf("\nYour final queue is : \n");
            display(queue);
            exit(0);
            break;
        default:
            printf("\nInvalid entry !\n\n");
            break;
        }
    }
}
