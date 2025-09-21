#include <iostream>
using namespace std;

const int N = 9;
int S[N][N] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

bool isValid(int r, int c, int val)
{
    for (int i = 0; i < N; i++)
    {
        if (S[r][i] == val)
        {
            return false;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (S[i][c] == val)
        {
            return false;
        }
    }

    int blockRow = r - (r % 3);
    int blockCol = c - (c % 3);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (S[blockRow + i][blockCol + j] == val) 
            {
                return false;
            }
        }
    }

    return true;
}

bool Sudoku(int r, int c)
{
    if (r == 9)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << S[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }

    int nextR = (c == 8) ? r + 1 : r;
    int nextC = (c == 8) ? 0 : c + 1;

    if (S[r][c] != 0)
    {
        return Sudoku(nextR, nextC);
    }

    for (int i = 1; i <= 9; i++)
    {
        if (isValid(r, c, i))
        {
            S[r][c] = i;
            if (Sudoku(nextR, nextC)) 
            {
                return true;
            }
            S[r][c] = 0;
        }
    }

    return false;
}

int main()
{
    if (!Sudoku(0, 0))
    {
        cout << "No solution exists" << endl;
    }
    return 0;
}
