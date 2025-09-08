#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge
{
    int u, v, w; // u & v vertices with cost w per edge
};

class DisjointSet {
    vector<int> parent;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1); // resize to pad 0
        
        for (int i = 0; i < n + 1; i++)
        {
            parent[i] = i; // init elements to be parents of themselves
        }
    }

    int find(int x)
    {
        // find representative of the set of a given element; root of the tree
        
        // if x is its own parent
        if (parent[x] == x) 
        {
            return x;
        }
        
        // recursive traversal to find repr of parent
        return parent[x] = find(parent[x]);
    }

    void unite(int u, int v)
    {
        // find root of each subset
        int urep = find(u);
        int vrep = find(v);
        
        if (urep != vrep) // check u & v have different roots for their respective subsets (avoid cycle)
        {
            parent[vrep] = urep; // set v's root as u's parent
        }
    }
};

int kruskal(int n, vector<Edge>& edges, vector<Edge>& mst) {
    DisjointSet ds(n);
    vector<bool> selected(edges.size(), false);

    int edgeCount = 0;
    int minCost = 0;

    while (edgeCount < n - 1) {
        int min = INT_MAX;
        int index = -1;

        // find the smallest edge that is not selected
        for (int i = 0; i < (int)edges.size(); i++) {
            if (!selected[i] && edges[i].w < min) {
                min = edges[i].w; // set new min & index to check
                index = i;
            }
        }

        if (index == -1) // no edge found
        {
            break;
        }
        
        // obtain u & v values of edge
        int u = edges[index].u;
        int v = edges[index].v;
        
        // check edge doesn't create a cycle
        if (ds.find(u) != ds.find(v)) {
            ds.unite(u, v); // create union of disjointed subsets
            minCost += edges[index].w;
            mst.push_back(edges[index]);
            edgeCount++;
        }

        // indicate edge has already been selected
        selected[index] = true;
    }

    return minCost;
}

int main()
{
    int n = 7;
    vector<Edge> edges = {
        {1, 2, 28},
        {1, 6, 10},
        {2, 7, 14},
        {2, 3, 16},
        {3, 4, 12},
        {4, 5, 22},
        {5, 6, 25},
        {4, 7, 18},
        {5, 7, 24},
        {7, 6, 19}
    };

    vector<Edge> mst; // minimum spanning tree
    int cost = kruskal(n, edges, mst); // pass in num elements, edges, & mst to change

    cout << "Minimum Cost: " << cost << endl;
    cout << "Edges in MST:" << endl;
    for (int j = 0; j < (int)mst.size(); j++)
    {
        cout << mst[j].u << " - " << mst[j].v << " : " << mst[j].w << endl; // output minimum spanning tree
    }

    return 0;
}