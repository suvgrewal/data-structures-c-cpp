#include <stdio.h>
#include <stdlib.h>

void Insert(int A[], int n)
{
    int i = n, temp;
    temp = A[i];
    
    // can only insert at last element
    while (i > 1 && temp > A[i/2]) // don't need to consider root
    {
        // if greater than parent copy parent value
        A[i] = A[i/2];
        i = i/2;
    }
    
    A[i] = temp;
}

int Delete(int A[], int n)
{
    int i, j, x, temp, val;
    val = A[1];
    x = A[n]; // can only delete last element
    A[1] = A[n];
    i = 1;
    j = i * 2;
    
    while (j < (n-1)) // n - 1 as one element removed
    {
        if (A[j + 1] > A[j]) // if right child greater than left child
        {
            j = j + 1; // point on right child
        }
        
        if (A[i] < A[j])
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * j; // move to child
        }
        else
        {
            break;
        }
    }
    
    return val; // return deleted val
    
}

int main()
{
    int H[] = {0, 10, 20, 30, 25, 5, 40, 35};
    // after heap: 40, 25, 35, 10, 5, 20, 30
    
    int i;
    
    for (i = 2; i <= 7; i++)
    {
        Insert(H, i);
    }
    
    for (i = 1; i <= 7; i++)
    {
        printf("%d ", H[i]);
    }
    
    printf("\n");
    
    return 0;
}