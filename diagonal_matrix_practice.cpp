#include <iostream>

using namespace std;

struct Matrix
{
    int A[10];
    int n;
};

class Diagonal
{
private:
    int *A;
    int n;
    
public:
    Diagonal()
    {
        // default constructor
        n = 2;
        A = new int[2];
    }
    Diagonal(int n)
    {
        // constructor
        this->n = n;
        A = new int[n];
    }
    ~Diagonal()
    {
        // destructor
        delete []A;
    }
    
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};

void Diagonal::Set(int i, int j, int x)
{
    // set a particular value in matrix at indices i, j
    if (i == j)
    {
        A[i - 1] = x;
    }
}

int Diagonal::Get(int i, int j)
{
    // get a particular value in matrix at indices i, j
    if (i == j)
    {
        return A[i-1];
    }
    return 0;
}

void Diagonal::Display()
{
    // display entire matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                cout << A[i] << " ";
            }
            else
            {
                cout << "0 ";
            }
            cout << endl; // new line
        }
    }
}

void Set(struct Matrix *m, int i, int j, int x)
{
    if (i == j)
    {
        m->A[i-1]=x;
    }
}

int Get(struct Matrix m, int i, int j)
{
    if (i == j)
    {
        return m.A[i-1];
    }
    else
    {
        return 0;
    }
}

void Display(struct Matrix m)
{
    int i, j;
    for (i = 0; i < m.n; i++)
    {
        for (j = 0; j < m.n; j++)
        {
            if (i == j)
            {
                printf("%d ", m.A[i]);
            }
            else
            {
                printf("0 ");
            }
        }
        
        printf("\n");
    }
}

int main()
{
    #if 0
    struct Matrix m;
    m.n = 4;
    
    Set(&m, 1, 1, 5);
    Set(&m, 2, 2, 8);
    Set(&m, 3, 3, 9);
    Set(&m, 4, 4, 12);
    printf("%d \n", Get(m,2,2)); // get
    
    Display(m);
    #endif
    
    #if 0
    Diagonal d(4);
    
    d.Set(1, 1, 5);
    d.Set(2,2,8);
    d.Set(3,3,9);
    d.Set(4,4,12);
    
    d.Display();
    #endif
    
    return 0;
}