#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void create2(int A[],int n)
{
    int i;
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;

    for(i = 1; i < n; i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int count(struct Node *p)
{
    int length = 0;
    while (p != NULL)
    {
        length++;
        p = p->next;
    }
    return length;
}

void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;

    if (index < 0 || index > count(p))
    {
        return;
    }

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
        }

        t->next = p->next;
        p->next = t;
    }
}

void SortedInsert(struct Node *p, int x)
{
    struct Node *t, *q = NULL;
    
    t = (struct Node*)malloc(sizeof(struct Node));
    
    t->data = x;
    t->next = NULL;

    if (first == NULL)
    {
        first = t;
    }
    else
    {
        while(p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int Delete(struct Node *p, int index)
{
    struct Node *q;
    int x = -1;
    int i;
    
    if (index < 1 || index > count(p))
    {
        return -1;
    }
    
    if (index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        delete q;
        return x;
    }
    
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        
        q->next = p->next;
        x = p->data;
        delete p;
        return x;
    }
}

int isSorted(struct Node *p)
{
    int x = -65536;
    
    while (p != NULL)
    {
        if (p->data < x)
        {
            return 0;
        }
        x = p->data;
        p = p->next;
    }
    
    return 1;
}

void RemoveDuplicate(struct Node *p)
{
    struct Node *q = p->next;
    
    while(q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);  // free memory
            q = p->next;
        }
    }
}

void Reverse1(struct Node *p)
{
    int *A, i = 0;
    struct Node *q;
    
    A = (int *)malloc(sizeof(int) * count(p));
    
    q = p;
    // get all elements into array
    while (q != NULL)
    {
        A[i] = q->data; // add data to array
        q = q->next; // move q pointer to next element
        i++; // increment index
    }
    
    q = p; // q at end of linked list
    i--; // adjust to be at end of array's indices
    while (q != NULL) // set data to array's data inverted
    {
        q->data = A[i]; 
        q = q->next;
        i--; // decrement to invert array
    }
}

void Reverse2(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;
    
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    
    first = q;
}

void Reverse3(struct Node *q, struct Node *p)
{
    if (p)
    {
        Reverse3(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

void Merge(struct Node *p, struct Node *q)
{
    struct Node *last; // pointer needed for merging
    
    // point at smaller or equal to q
    if (p->data <= q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }
    
    while (p && q)
    {
        if (p->data <= q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    
    // check if p is not done
    if (p)
    {
        last->next = p;
    }
    
    if (q)
    {
        last->next = q;
    }
}

void Concat(struct Node *p, struct Node *q)
{
    third = p; // make third pointer point on p (first linked list)
    
    while (p->next != NULL)
    {
        p = p->next; // move to last node of linked list p
    }
    
    p->next = q; // make final node of p have q's first node as its next node
}

// check loop
int isLoop(struct Node *f)
{
    struct Node *p, *q;
    
    p = q = f;
    do
    {
        // give p stride of 1 and q stride of 2
        p = p->next;
        q = q->next;
        q = (q!= NULL) ?  q->next : NULL; // if q is not null, then go next, else set it to next
    } while(p && q && p != q);
    
    if (p == q)
    {
        return 1; // is loop if p eventually was equal to q
    }
    return 0;
}
int main()
{
    struct Node *t1, *t2;
    int A[] = {10, 20, 30, 40, 50};
    
    create(A, 5);
    
    t1 = first->next->next;
    t2 = first->next->next->next->next;
    t2->next = t1; // create the loop
    
    if (isLoop(first))
    {
        printf("Is Loop");
    }
    else
    {
        printf("Is not loop");
    }

    return 0;
}