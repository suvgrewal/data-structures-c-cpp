// Queue.h
// Tree
#include <stdio.h>
#include <stdlib.h>

#ifndef Queue_h
#define Queue_h

struct Node
{
    // node for a binary tree
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue
{
    int size;
    int front;
    int rear;
    Node **Q;
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *)); // creaete array dynamically from heap
}

void enqueue(struct Queue *q, struct Node * x)
{
    // check queue full
    if (q->rear == (q->size - 1))
    {
        printf("Queue is Full");
    }
    
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

Node * dequeue(struct Queue *q)
{
    Node *x = NULL;
    
    // check if Queue is empty
    if (q->front == q->rear)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    
    return x;
}

int isEmpty(struct Queue q)
{
    return q.front == q.rear;
}

#endif Queue_h