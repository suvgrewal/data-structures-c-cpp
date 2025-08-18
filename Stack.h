// Stack.h
// Tree

#include <stdio.h>
#include <stdlib.h>


#ifndef Stack_h
#define Stack_h
struct Stack
{
    int size; // size of stack
    int top; // index of top of stack (-1 if empty, size-1 if full)
    struct Node **S; // pointer to stack array
};

void StackCreate(struct Stack *st, int size)
{
    st->size = size;
    st->top = -1;
    st->S = (struct Node **)malloc(st->size * sizeof(struct Node *)); // allocate array for stack
}

void push(struct Stack *st, struct Node *x)
{
    // check if space is available on the stack 
    if (st->top==st->size-1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        st->top++;
        st->S[st->top]=x;
    }
}

struct Node  *pop(struct Stack *st)
{
    struct Node *x = NULL;
    
    if(st->top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        x = st->S[st->top--];
    }
    
    return x;
}

int isEmptyStack(struct Stack st)
{
    if (st.top == -1)
    {
        return 1;
    }
    
    return 0;
}

int isFullStack(struct Stack st)
{
    if (st.top == st.size-1)
    {
        return 1;
    }
    
    return 0;
}

#endif