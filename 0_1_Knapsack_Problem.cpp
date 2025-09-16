#include <iostream>
#include <vector>

using namespace std;

int R_Knap(int n, int m, int *w, int *p)
{
    // recursive knap problem solution
    if (n == 0 || m == 0)
    {
        return 0;
    }
    
    int no = R_Knap(n - 1, m, w, p);                   // if not included
    int yes = R_Knap(n - 1, m - w[n - 1], w, p) + p[n - 1];    // if included
    
    return no > yes ? no : yes;
}

int M_Knap(int n, int m, int* w, int* p, vector<vector<int>>& T)
{
    // memoization method for Knapsack problem
    if (n == 0 || m == 0) // if gotten to final row/column
    {
        T[n][m] = 0;
        return 0;
    }
    
    if (T[n][m] != -1) // if not empty (value already cached)
    {
        return T[n][m];
    }
    
    if (w[n - 1] <= m)
    {
        int no = M_Knap(n - 1, m, w, p, T);
        int yes = M_Knap(n - 1, m - w[n - 1], w, p, T) + p[n - 1];
        T[n][m] = no > yes ? no : yes;
    }
    
    else
    {
        T[n][m] = M_Knap(n - 1, m, w, p, T);
    }
    
    return T[n][m];
}

int T_Knap(int n, int m, int* w, int* p) {
    vector<vector<int>> T(n + 1, vector<int>(m + 1, 0)); // init vector of 0s

    for (int i = 1; i <= n; i++) {                       // loop over one item at a time
        for (int j = 1; j <= m; j++)                     // loop to max weight allowed
        {
            if (w[i - 1] <= j)
            {

                T[i][j] = max(
                    T[i - 1][j],                         // not using item
                    p[i - 1] + T[i - 1][j - w[i - 1]]    // using item
                );
            }
            else
            {
                T[i][j] = T[i - 1][j];
            }
        }
    }
    
    return T[n][m]; // final cell has max profit
}

int main()
{
    int n = 4;
    int m = 5;
    
    vector<vector<int>> T(n + 1, vector<int>(m + 1, -1));
    
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            T[i][j] = -1;
        }
    }
    
    int w[] = {1, 2, 1, 2};    // weight array 
    int p[] = {6, 5, 3, 8};    // profit array

    int max_profit_recursive = R_Knap(n, m, w, p);
    
    int max_profit_memoization = M_Knap(n, m, w, p, T);
    
    int max_profit_tabulation = T_Knap(n, m, w, p);
    
    cout << "Max profit from recursive: " << max_profit_recursive << endl;
    
    cout << "Max profit from memoization: " << max_profit_memoization << endl;
    
    cout << "Max profit from tabulation: " << max_profit_tabulation << endl;
}