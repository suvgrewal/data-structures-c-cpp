#include <stdio.h>
#include <stdlib.h>

class Node
{
public:
    int data;
    Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
    Node() : Node(0) {} // Delegating constructor
};

class Stack
{
private:
    Node *top;
public:
    Stack()
    {
        // default argument constructor
        top = NULL;
    }
    ~Stack()
    {
        while (top != NULL)
        {
            Node* t = top;
            top = top->next;
            delete t;
        }
    }
    
    void push(int x);
    int pop();
    void Display();
    int peek();
    int isEmpty();
    int stackTop();
};

void Stack::push(int x)
{
    Node *t = new Node();
    
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

int Stack::pop()
{
    int x = -1;
    Node *t;
    
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
        delete t; // free memory of t
    }
    
    return x;
}

void Stack::Display()
{
    Node *t;
    t = top;
    
    printf("\n");
    
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    
    printf("\n");
}

int Stack::peek()
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

int Stack::isEmpty()
{
    if (top == NULL)
    {
        return 1;
    }
    
    return 0;
}

int Stack::stackTop()
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
    Stack *st = new Stack();
    st->push(10);
    st->push(20);
    st->push(30);
    
    st->Display();
    
    printf("%d ", st->pop());
    st->Display();
    
    printf("%d ", st->pop());
    st->Display();
    
    printf("%d ", st->pop());
    st->Display();
    
    printf("%d ", st->pop());
    st->Display();
    
    return 0;
}