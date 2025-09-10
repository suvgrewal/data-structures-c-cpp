#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int* Dijkstra(vector<vector<int>> cost, int n, int s)
{
    int min;
    int minCost = 0;
    int *d = new int[n + 1];
    bool *selected = new bool[n+1];
    for (int i = 0; i < n + 1; i++) // init selected with false
    {
        selected[i] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        d[i] = cost[s][i]; // initial distance array with distances of source
    }
    
    d[s] = 0;
    selected[s] = true;
    int m = 0;
    int u = 0;
    
    for (int k = 1; k < n; k++)
    {
        min = INT_MAX;
        for (int i = 1; i <= n; i++)
        {
            if (!selected[i] && d[i] < min) // check if not selected & distance is a new minimum
            {
                min = d[i];
                u = i; // new selected vertex's index
            }
        }
        selected[u] = true; // set selected vertex
        
        for (int v = 1; v <= n; v++)
        {
            // relaxation
            if (!selected[v] && cost[u][v] != INT_MAX && d[u] != INT_MAX && d[u] + cost[u][v] < d[v])
            {
                d[v] = d[u] + cost[u][v];
            }
        }
    }
    
    return d;
}

int main()
{
    int n = 6;
    int s = 1;
    vector<vector<int>> cost = {
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX}, // 0 (do NOT use)
        {INT_MAX, 0,       4,       2,       INT_MAX, INT_MAX, INT_MAX}, // 1
        {INT_MAX, 4,       0,       1,       5,       INT_MAX, INT_MAX}, // 2
        {INT_MAX, 2,       1,       0,       8,       10,      INT_MAX}, // 3
        {INT_MAX, INT_MAX, 5,       8,       0,       2,       6},       // 4
        {INT_MAX, INT_MAX, INT_MAX, 10,      2,       0,       3},       // 5
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 6,       3,       0}        // 6
    };

    int* d = Dijkstra(cost, n, s);

    cout << "Shortest distances from source vertex " << s << ":" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "To " << i << " = ";
        if (d[i] == INT_MAX)
        {
            cout << "INF";
        }
        else
        {
            cout << d[i];
        }
        cout << endl;
    }

    delete[] d;
    return 0;
}