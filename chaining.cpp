#include <stdio.h>
#include <stdlib.h>
#include "Chains.h"

int hash(int key)
{
    return key % 10;
}

void Insert(struct Node *H[], int key)
{
    int index = hash(key);
    SortedInsert(&H[index], key);
}

int main()
{
    struct Node *HT[10]; // hash table
    int i;
    struct Node *temp;
    int key = 22;
    
    for (int i = 0; i < 10; i++)
    {
        HT[i] = NULL;
    }
    
    Insert(HT, 12);
    Insert(HT, 22);
    Insert(HT, 42);
    
    temp = Search(HT[hash(key)], key);
    
    printf("%d ", temp->data);
    
    return 0;
}