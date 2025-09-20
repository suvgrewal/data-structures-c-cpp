#include <iostream>
using namespace std;

const int N = 7;

int M[N][N] = {
    {1, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0},
    {0, 1, 0, 1, 1, 1, 0},
    {0, 1, 1, 0, 0, 1, 0},
    {0, 0, 1, 0, 0, 1, 0},
    {0, 0, 1, 1, 1, 1, 1}
};

int sol[2][N*N]; // array of row, cols rat goes to
int path = 0;

void printPath()
{
    cout << "Path found:" << endl;
    for (int i = 0; i < path; i++)
    {
        cout << "(" << sol[0][i] << "," << sol[1][i] << ") ";
    }
    cout << endl;
}

void rim(int i, int j)
{
    if (i == N - 1 && j == N - 1) // if reached destination
    {
        sol[0][path] = i;
        sol[1][path] = j;
        path++;
        printPath();
        path--;
        return;
    }

    // mark cell as visited
    M[i][j] = 0;
    sol[0][path] = i;
    sol[1][path] = j;
    path++;

    // move right (1)
    if (j + 1 < N && M[i][j + 1] == 1)
    {
        rim(i, j + 1);
    }

    // move down (2)
    if (i + 1 < N && M[i + 1][j] == 1)
    {
        rim(i + 1, j);
    }

    // move left (3)
    if (j - 1 >= 0 && M[i][j - 1] == 1)
    {
        rim(i, j - 1);
    }

    // move up (4)
    if (i - 1 >= 0 && M[i - 1][j] == 1)
    {
        rim(i - 1, j);
    }

    // backtrack
    M[i][j] = 1;
    path--;
}

int main()
{
    rim(0, 0); // start from top-left
    return 0;
}