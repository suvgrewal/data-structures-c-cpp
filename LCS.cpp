#include <iostream>
#include <vector>

using namespace std;

int R_LCS(char A[], char B[], int i, int j)
{
    // Recursive LCS
    // A is subset array
    // B is character array
    if (i == 0 || j == 0) // basecase if either i or j is 0
    {
        return 0;
    }
    
    if (A[i - 1] == B[j - 1])
    {
        return 1 + R_LCS(A, B, i - 1, j - 1);
    }
    
    else
    {
        return max(R_LCS(A, B, i - 1, j), R_LCS(A, B, i, j - 1)); // get max of reducing i by 1 or j by 1
    }
}

int M_LCS(char A[], char B[], int i, int j, vector<vector<int>>& L)
{
    // pass L by reference to use memoization table/cache
    if (i == 0 || j == 0) // base case
    {
        L[i][j] = 0;
        return 0;
    }
    
    if (L[i][j] != -1)    // if value already cached
    {
        return L[i][j];
    }
    
    if (A[i - 1] == B[j - 1])     // if match (-1 due to 0 idx)
    {
        L[i][j] = 1 + M_LCS(A, B, i - 1, j - 1, L);
    }
    
    else
    {
        L[i][j] = max(M_LCS(A, B, i - 1, j, L), M_LCS(A, B, i, j - 1, L));
    }
    
    return L[i][j];
}

int T_LCS(char A[], char B[], int n, int m)
{
    vector<vector<int>> L(n + 1, vector<int>(m + 1, 0));
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (A[i - 1] == B[j - 1])
            {
                L[i][j] = 1 + L[i - 1][j - 1]; // if matching add one to previous diagonal element
            }
            else
            {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }
    
    return L[n][m];
}

int main()
{
    int n = 3;
    int m = 5;
    
    vector<vector<int>> L(n + 1, vector<int>(m + 1, -1));
    
    char A[] = {'a', 'c', 'e'};
    char B[] = {'a', 'b', 'c', 'd', 'e'};
    
    int max_match_R_LCS = R_LCS(A, B, n, m);
    
    int max_match_M_LCS = M_LCS(A, B, n, m, L);
    
    int max_match_T_LCS = T_LCS(A, B, n, m);
    
    cout << "Max match recursive LCS: " << max_match_R_LCS << endl;
    
    cout << "Max match memoiziation LCS: " << max_match_M_LCS << endl;
    
    cout << "Max match tabulation LCS: " << max_match_T_LCS << endl;
    
    return 0;
}