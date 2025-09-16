#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// matrix chain multiplication

int *d;
vector<vector<int>> dp;
int n;

int R_MCM(int i, int j)
{
    // recursion
    if (i == j)
    {
        return 0;
    }
    
    int minCost = INT_MAX;
    
    for (int k = i; k < j; k++)
    {
        int cost = R_MCM(i, k) + R_MCM(k + 1, j) + d[i - 1] * d[k] * d[j];
        minCost = min(minCost, cost);
    }
    
    return minCost;
}

int M_MCM(int i, int j)
{
    // memoization
    if (i == j)
    {
        return 0;
    }
    
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    
    int minCost = INT_MAX;
    
    for (int k = i; k < j; k++)
    {
        int cost = M_MCM(i, k) + M_MCM(k + 1, j) + d[i - 1] * d[k] * d[j];
        minCost = min(minCost, cost);
    }
    
    dp[i][j] = minCost;
    
    return minCost;
}

int T_MCM()
{
    // tabulation
    vector<vector<int>> t(n + 1, vector<int>(n + 1, 0));
    
    for (int l = 2; l <= n; l++)
    {
        for (int i = 1; i <= n - l + 1; i++)
        {
            int j = i + l - 1;
            t[i][j] = INT_MAX;
            
            for (int k = i; k < j; k++)
            {
                int cost = t[i][k] + t[k + 1][j] + d[i - 1] * d[k] * d[j];
                t[i][j] = min(t[i][j], cost);
            }
        }
    }
    
    return t[1][n];
}

int main()
{
    int d0 = 3;
    int d1 = 2;
    int d2 = 4;
    int d3 = 2;
    int d4 = 5;

    int dims[] = {d0, d1, d2, d3, d4};
    d = dims;
    n = 4;

    int R_MinCost = R_MCM(1, n);

    dp = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
    int M_MinCost = M_MCM(1, n);

    int T_MinCost = T_MCM();

    cout << "R_MinCost: " << R_MinCost << endl;
    cout << "M_MinCost: " << M_MinCost << endl;
    cout << "T_MinCost: " << T_MinCost << endl;

    return 0;
}
