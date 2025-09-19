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
    
    return max;
}

int Kadane(int A[], int n)
{
    int start = 0;    // start of subarray of max
    int end = 0;      // ending point of max subarray
    int subStart = 0; // start of current subarray
        
    int maxSub = A[0];
    int prevSum = A[0];
    
    for (int i = 0; i < n; i++)
    {
        if (prevSum < 0)
        {
            prevSum = A[i];
        }
        else
        {
            prevSum = prevSum + A[i];
        }
        
        if (prevSum > maxSub)
        {
            maxSub = prevSum;
            start = subStart;
            end = i;
        }
    }
    
    return maxSub;
}

int CrossSum(int l, int mid, int h, int A[])
{
    int leftSub = INT_MIN;
    int sum = 0;
    
    for (int i = mid; i >= l; i--)
    {
        sum = sum + A[i];
        if (sum > leftSub)
        {
            leftSub = sum;
        }
    }
    
    int rightSub = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= h; i++)
    {
        sum = sum + A[i];
        if (sum > rightSub)
        {
            rightSub = sum;
        }
        
    }
    
    return leftSub + rightSub;
}

int MaxSub(int l, int h, int A[])
{
    // Divide & Conquer approach to MaxSubArray Problem
    if (l == h)
    {
        return A[l];
    }
    
    int mid = (l + h) / 2;
    
    int leftMax = MaxSub(l, mid, A);
    int rightMax = MaxSub(mid + 1, h, A);
    
    int cSum = CrossSum(l, mid, h, A);
    
    return max(leftMax, max(rightMax, cSum));
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

    int maxSub = MaxSub(A, n);
    cout << "MaxSub result: " << maxSub << " (from " << start_idx << " to " << end_idx << ")\n";

    int dp = DPSum(A, n);
    cout << "DPSum result: " << dp << "\n";
    
    int kadane = Kadane(A, n);
    cout << "Kadane result: " << kadane << "\n";
    
    int divideConquer = MaxSub(0, n - 1, A);
    cout << "Divide and Conquer result: " << divideConquer << "\n";

    return 0;
}