#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Bubble(int A[], int n)
{
    int i, j, flag = 0;
    
    for (i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(&A[j], &A[j+1]);
                flag = 1;
            }
        }
        
        if (flag == 0) // sorting done
        {
            break;
        }
    }
}

void PrintArray(int A[], int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    
    printf("\n");
}

void Insertion(int A[], int n)
{
    int i, j, x;
    
    for (i = 1; i < n; i++)
    {
        j = i - 1;
        x = A[i];
        while(j > -1 && A[j] > x)
        {
            A[j + 1] = A[j];
            j--;
        }
        
        A[j + 1] = x;
    }
}

void Selection(int A[], int n)
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        k = i;
        for (j = i; j < n; j++)
        {
            if (A[j] < A[k])
            {
                k = j;
            }
        }
        
        swap(&A[i], &A[k]);
    }
}

int partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l;
    int j = h;
    
    do
    {
        do
        {
            i++;
        } while (A[i] <= pivot); // keep going till finding a value equal to or higher than pviot
        do
        {
            j--;
        } while (A[j] > pivot);
        
        if (i < j)
        {
            swap(&A[i], &A[j]);
        }
    } while(i < j);
    
    swap(&A[l], &A[j]);
    
    return j;
}

void Quick(int A[], int l, int h)
{
    int j;
    
    if (l < h)
    {
        j = partition(A, l, h);
        Quick(A, l, j); // j acts as infinity
        Quick(A, j+1, h);
    }
}

int* Merge(int A[], int B[], int m, int n)
{
    int *C = (int *)malloc((m + n) * sizeof(int));
    
    int i = 0;
    int j = 0;
    int k = 0;
    
    while (i < m && j < n) // iterate until one finishes
    {
        if (A[i] < B[j])
        {
            C[k++] = A[i++];
        }
        
        else
        {
            C[k++] = B[j++]; // increment idx for B
        }
    }
    
    while (i < m) // finish up first array
    {
        C[k++] = A[i++];
    }
    while (j < n) // finish up second array
    {
        C[k++] = B[j++];
    }
    
    return C;
}

void Merge(int A[], int l, int mid, int h)
{
    int i = l;
    int j = mid + 1;
    int k = l;
    int B[100];
    
    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
        {
            B[k++] = A[i++];
        }
        else
        {
            B[k++] = A[j++];
        }
    }
    
    for (; i<= mid; i++)
    {
        B[k++] = A[i];
    }
    for (; j<= h; j++)
    {
        B[k++] = A[j];
    }
    
    for (int i = l; i <= h; i++)
    {
        // for transferring the elements
        A[i] = B[i];
    }
}

void IMergeSort(int A[], int n)
{
    int p, l, h, mid, i; // p: size of subarray; l: low; h: high; mid: middle; i: inner loop var
    
    for (p = 2; p <= n; p = p * 2) // double size of subarray (p) per loop iter
    {
        for (i = 0; i + p - 1 < n; i = i + p) // n total num
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            Merge(A, l, mid, h);
        }
    }
    
    if (p / 2 < n)
    {
        Merge(A, 0, p / 2 - 1, n - 1);
    }
}

void MergeSort(int A[], int l, int h)
{
    int mid;
    if (l < h)
    {
        mid = (l + h) / 2;
        MergeSort(A, l, mid);
        MergeSort(A, mid+1, h);
        Merge(A, l, mid, h);
    }
}

int findMax(int A[], int n)
{
    int max = -2147483648;
    int i;
    for(i = 0; i < n; i++)
    {
        max = (A[i] > max) ? A[i] : max;
    }
    
    return max;
}

int findMin(int A[], int n)
{
    int min = 2147483647;   
    
    int i;
    for(i = 0; i < n; i++)
    {
        min = (A[i] < min) ? A[i] : min;
    }
    
    return min;
}

void CountSort(int A[], int n)
{
    int i;
    int j;
    int max = findMax(A, n);;
//    int min = findMin(A, n);
    int *C; // count array C
    
//    int range = max - min + 1;
    
    C = (int *)malloc(sizeof(int) * (max + 1));
    
    for (i = 0; i < max + 1; i++)
    {
        C[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        C[A[i]]++; // increment count value at idx A[i] by 1
    }
    i = 0; j = 0;
    
    while (j < (max + 1))
    {
        if (C[j] > 0)
        {
            A[i++] = j; 
            C[j]--; // increment count at idx (value) j 
        }
        else
        {
            j++; // move to next idx (value)
        }
    }
}

void CountSortRadix(int A[], int n, int exp)
{
    int *output = (int *)malloc(n * sizeof(int));
    int count[10] = {0}; // init count array to 0s

    for (int i = 0; i < n; i++)
    {
        count[(A[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (A[i] / exp) % 10;
        output[count[digit] - 1] = A[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++)
    {
        A[i] = output[i]; // output copied to A
    }

    free(output); // free malloc
}

void RadixSort(int A[], int n)
{
    int max = findMax(A, n);

    for (int exp = 1; max / exp > 0; exp *= 10)
        CountSortRadix(A, n, exp);
}

void ShellSort(int A[], int n)
{
    int gap;
    int i;
    int j;
    int temp;
    
    for (gap = n/2; gap >= 1; gap /= 2) // ever iter reduce gap by 1/2
    {
        for (i = gap; i < n; i++)
        {
            temp = A[i];
            j = i - gap;
            while (j >= 0 && A[j] > temp)
            {
                A[j + gap] = A[j];
                j = j - gap;
            }
            A[j + gap] = temp;
        }
    }
}

int main()
{
    int A[] = {11, 13, 2, 2, 6, 9, 4, 5};
    int n = sizeof(A) / sizeof(A[0]);
    int i;
//    
////    Bubble(A, n);
////    Insertion(A, n);
////    Selection(A, n);
//    int low = 0;
//    int high = n;
//    Quick(A, low, high);
//    
//    PrintArray(A, n);
    
//    int A[] = {2, 10, 18, 20, 23};
//    int B[] = {4, 9, 19, 25};
//    
//    int m = 5; // num elements in A
//    int n = 4; // num elements in B
    
//    int *C = Merge(A, B, m, n);
//    PrintArray(C, m+n);
    
//    IMergeSort(A, n);
//    MergeSort(A,0,n-1);

//    CountSort(A, n);
//    RadixSort(A, n);
    
    ShellSort(A, n);
    PrintArray(A, n);
    
    return 0;
}