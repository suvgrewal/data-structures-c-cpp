#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int start_idx;
int end_idx;

int NaiveMaxSub(int A[], int n)
{
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += A[k];
            }
            if (sum > maxSum)
            {
                maxSum = sum;
                start_idx = i;
                end_idx = j;
            }
        }
    }
    
    return maxSum;
}

int MaxSub(int A[], int n)
{
    int maxSum = INT_MIN;
    int start = 0;
    int end = 0;
    for (int i = 0; i < n; i ++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum = sum + A[j];
            
            if (sum > maxSum)
            {
                maxSum = sum;
                start_idx = i;
                end_idx = j;
            }
        }
    }
    
    return maxSum;
}

int DPSum(int A[], int n)
{
    int S[n];                   // sum array
    S[0] = A[0];
    for (int i = 1; i < n; i++) // find sums
    {
        if (S[i - 1] < 0)       // if previous sum is negative
        {
            S[i] = A[i];
        }
        else
        {
            S[i] = S[i - 1] + A[i];
        }
    }
    
    int max = S[0];
    for (int i = 1; i < n; i++) // scan through array of filtered sums to find max sum
    {
        if (S[i] > max)
        {
            max = S[i];
        }
    }
}

int main()
{
    int A[] = {-2, -3, 4, -1, -2, 1, 5, -3};   // array of elements to sum
    int n = sizeof(A) / sizeof(A[0]);          // num elements

    cout << "Testing array: ";
    
    for (int i = 0; i < n; i++) 
    {
        cout << A[i] << " ";
    }
    
    cout << "\n\n";

    int naive = NaiveMaxSub(A, n);
    cout << "NaiveMaxSub result: " << naive << " (from " << start_idx << " to " << end_idx << ")\n";

    int maxsub = MaxSub(A, n);
    cout << "MaxSub result: " << maxsub << " (from " << start_idx << " to " << end_idx << ")\n";

    int dp = DPSum(A, n);
    cout << "DPSum (Kadane) result: " << dp << "\n";

    return 0;
}