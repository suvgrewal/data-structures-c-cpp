#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

void push(int x)
{
    struct Node *t;
    
    t = (struct Node*)malloc(sizeof(struct Node));
    
    if (t == NULL)
    {
        printf("Stack is full\n");
    }
    else
    {
        t->data = x; // init data of t
        t->next = top; // t's next is current top node
        top = t; // make t the new top node
    }
}

int pop()
{
    int x = -1;
    struct Node *t;
    
    // check if stack is empty
    if(top == NULL)
    {
        printf("Stack is Empty\n");
    }
    
    // delete element
    else
    {
        t = top;
        x = t->data; // obtain data at node
        top = top->next; // set top to next pointer
        free(t); // free memory of t
    }
    
    return x;
}

void create(int A[], int n)
{
    int i;
    
    struct Node *t;
    
    for (i = 0; i < n; i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        
        t->data = A[i];
        
        if (i == 0)
        {
            top = t;
            t->next = NULL;
        }
        
        else
        {
            t->next = top;
            top = t;
        }
    }
}

void Display()
{
    struct Node *t;
    t = top;
    
    printf("\n");
    
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    
    printf("\n");
}

int peek()
{
    int x = -1;
    
    if (top == NULL)
    {
        printf("Stack is Empty\n");
        return x;
    }
    
    else
    {
        x = top->data;
    }
    
    return x;
}

int isEmpty()
{
    if (top == NULL)
    {
        return 1;
    }
    
    return 0;
}

int stackTop()
{
    int x = -1;
    
    if (!isEmpty())
    {
        x = top->data;
    }
    
    return x;
}

int main()
{
    push(10);
    push(20);
    push(30);
    
    Display();
    
    printf("%d ", pop());
    Display();
    
    printf("%d ", pop());
    Display();
    
    printf("%d ", pop());
    Display();
    
    printf("%d ", pop());
    Display();
    
    return 0;
}