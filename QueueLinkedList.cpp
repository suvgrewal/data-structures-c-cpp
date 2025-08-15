#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

void enqueue(int x)
{
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));
    if (t == NULL)
    {
        printf("Queue is Full\n");
    }
    else
    {
        t->data = x;
        t->next = NULL;
        
        if (front == NULL)
        { 
            // if t is the first node queued
            front = rear = t;
        }
        else
        {
            rear->next = t; // set next for last node as t
            rear = t; // set rear as the new node t
        }
    }
}

int dequeue()
{
    int x = -1;
    struct Node *t;
    
    if (front == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        x = front->data; // obtain front's data
        t = front; // set temp variable to current front
        front = front->next; // move front to next node or position in queue
        free(t); // free memory to avoid memory leak
    }
    return x;
}

void Display()
{
    struct Node *p;
    
    p = front;
    
    while (p) // until p is null
    {
        printf("%d ", p->data);
        p = p->next;
    }
    
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    
    Display();
    
    return 0;
}