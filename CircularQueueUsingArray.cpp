#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0; // 0 for circular queue
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueue(struct Queue *q, int x)
{
    // check queue full
    if ((q->rear + 1) && q->size == q-> front)
    {
        printf("Queue is Full");
    }
    
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q)
{
    int x = -1;
    
    // check if Queue is empty
    if (q->front == q->rear)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        q->front = (q->front + 1) % q->size; // account for + 1 as first element is uninit
        x = q->Q[q->front];
    }
    
    return x;
}

void Display(struct Queue q)
{
    int i = q.front + 1; // account for + 1 as first element is uninit
    
    do
    {
        printf("%d ", q.Q[i]);
        i = (i + 1) % q.size;
    } while(i != (q.rear + 1) % q.size);
    
    printf("\n");
}

int main()
{
    struct Queue q;
    
    create(&q, 5);
    
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    
    Display(q);
    
    dequeue(&q);
    
    Display(q);
    dequeue(&q);
    
    Display(q);
    dequeue(&q);
    
    Display(q);
    dequeue(&q);
    
    Display(q);
    dequeue(&q);
    
    Display(q);
    dequeue(&q);
    
    Display(q);
    
    return 0;
}