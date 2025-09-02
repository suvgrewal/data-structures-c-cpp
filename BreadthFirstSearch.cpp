#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void BFS(int vtx, int A[][8], int n)
{
    queue<int> Q;                      // queue to manage vertices in BFS order
    vector<int> visited(n, 0);         // vector to hold vertices already visited
    vector<int> order;                 // vector to hold order to output in

    visited[vtx] = 1;
    Q.push(vtx);

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();                        // take out ele from front of queue                 
        order.push_back(u);             // push to end of order
        for (int v = 1; v < n; v++)
        {
            if (A[u][v] && !visited[v]) // if edge (1) and not visited yet
            {
                visited[v] = 1;
                Q.push(v);
            }
        }
    }

    for (size_t i=0; i<order.size(); i++)
    {
        cout << order[i];
        if (i+1 < order.size()) cout << ", ";
    }
    cout << endl;
}
 
int main (){
 
    int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
 
    cout << "Vertex: 1 -> " << flush;
    BFS(1, A, 8);
 
    cout << "Vertex: 4 -> " << flush;
    BFS(4, A, 8);
    
    return 0;
}