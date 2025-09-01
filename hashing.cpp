#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int hash(int key)
{
    return key % SIZE;
}

int probe(int H[], int key)
{
    int index = hash(key);
    int i = 0;
    while (H[(index + i) % SIZE] != 0) // while space is not free
    {
        i++;
    }
    
    return (index + i) % SIZE;
}

void Insert(int H[], int key)
{
    int index = hash(key);
    
    if (H[index] != 0) // if occupied
    {
        index = probe(H, key);
    }
    
    H[index] = key;
}

void PrintHashTable(int H[])
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", H[i]);
    }
}

int Search(int H[], int key)
{
    int index = hash(key); // key to get index from has function
    
    int i = 0;
    while (H[index + i] != key && (index + i) < (2 * SIZE))
    {
        i++;
    }
    
    if (!((index + i) < (2 * SIZE))) // if past 2 * SIZE, meaning key not found
    {
        return -1;
    }
    
    return (index + i) % SIZE;
}

int main()
{
    int HT[SIZE] = {0}; // hashtable
    
    Insert(HT, 12);
    Insert(HT, 25);
    Insert(HT, 35);
    Insert(HT, 26);
    
    printf("%d \n", Search(HT, 19));
    
    PrintHashTable(HT);
    
    return 0;
}