#include <iostream>
#include <cmath>
using namespace std;

bool valid(int k, int l, int x[])
{
    for (int i = 1; i < k; i++)
    {
        if (x[i] == l || abs(i - k) == abs(x[i] - l))
        {
            return false;
        }
    }
    return true;
}

void print(int x[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[i] == j)
            {
                cout << "Q ";
            }
            else
            {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << "\n" << endl;
}

void NQueens(int k, int x[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (valid(k, i, x))
        {
            x[k] = i;
            if (k == n)
            {
                print(x, n);
                return;
            }
            NQueens(k + 1, x, n);
        }
    }
}

int main()
{
    int n = 4;
    int x[5];
    
    NQueens(1, x, n);
    return 0;
}