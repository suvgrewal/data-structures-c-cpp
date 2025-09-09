#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int Prims(vector<vector<int>> cost, int n)
{
    int minCost = 0;
    int* near = new int[n + 1];
    bool* selected = new bool[n + 1];
    for (int i = 0; i < (n+1); i++) // init selected to false
    {
        selected[i] = false;
    }
    
    int u = 1;
    int v;
    int min = INT_MAX;
    
    for (int i = 1; i <= n; i++) // find minimum cost to start
    {
        if (cost[1][i] < min)
        {
            min = cost[1][i];
            v = i; // set v to new minimum
        }
    }
    
    selected[u] = selected[v] = true; // indicate selected indices
    
    minCost += cost[u][v];
    
    // initialize near array depending on cost to connect to specific vertex u or i
    for (int i = 1; i <= n; i++)
    {
        if (cost[u][i] <= cost[v][i])
        {
            near[i] = u;
        }
        else
        {
            near[i] = v;
        }
    }
    
    for (int i = 1; i <= n - 2; i++)
    {
        min = INT_MAX;
        for (int j = 1; j <= n; j++)
        {
            // check not selected & cost is a new minimum based of near array
            if (selected[j] == false && cost[j][near[j]] < min)
            {
                min = cost[j][near[j]];
                v = j;
            }
        }
            
        u = near[v];
        minCost += cost[u][v];
        selected[v] = true;
        
        for (int k = 1; k <= n; k++)
        {
            if (selected[k] == false && cost[k][v] < cost[k][near[k]])
            {
                near[k] = v;
            }
        }
    }
    
    return minCost;
}

int main() 
{
    int n = 7;
    vector<vector<int>> cost = {
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX}, // 0 (unused)
        {INT_MAX, INT_MAX, 28, INT_MAX, INT_MAX, INT_MAX, 10, INT_MAX},           // 1
        {INT_MAX, 28, INT_MAX, 16, INT_MAX, INT_MAX, INT_MAX, 14},                // 2
        {INT_MAX, INT_MAX, 16, INT_MAX, 12, INT_MAX, INT_MAX, INT_MAX},           // 3
        {INT_MAX, INT_MAX, INT_MAX, 12, INT_MAX, 22, INT_MAX, 18},                // 4
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 22, INT_MAX, 25, 24},                // 5
        {INT_MAX, 10, INT_MAX, INT_MAX, INT_MAX, 25, INT_MAX, 19},                // 6
        {INT_MAX, INT_MAX, 14, INT_MAX, 18, 24, 19, INT_MAX}                      // 7
    };

    int costMST = Prims(cost, n);

    cout << "Minimum Cost = " << costMST << endl;
    return 0;
}
