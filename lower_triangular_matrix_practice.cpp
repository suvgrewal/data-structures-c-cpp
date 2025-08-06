#include <iostream>

using namespace std;

struct Matrix
{
    int *A;
    int n;
};

void Set(struct Matrix *m, int i, int j, int x)
{
    // set lower triangular matrix values for row major representation
    if (i >= j)
    {
        m->A[ (i * (i - 1)) / 2 + (j - 1)] = x; // -> for pointer
    }
}

int Get(struct Matrix m, int i, int j)
{
    // get lower triangular matrix values for row major representation
    if (i >= j)
    {
        return m.A[ (i * (i - 1)) / 2 + (j - 1)];
    }
    else
    {
        return 0;
    }
}

void Display(struct Matrix m)
{
    // display lower triangular matrix for row major representation
    int i, j;
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            if (i >= j)
            {
                printf("%d ", m.A[(i * (i - 1)) / 2 + (j - 1)]);
            }
            else
            {
                printf("0 ");
            }
        }
        
        printf("\n");
    }
}

class LowerTri
{
private:
    int *A;
    int n;
public:
    LowerTri()
    {
        // default constructor
        n = 2;
        A = new int[2];
    }
    LowerTri(int n)
    {
        // constructor
        this->n = n;
        A = new int[(n * (n + 1)) / 2];;
    }
    ~LowerTri()
    {
        // destructor
        delete []A;
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int GetDimension();
};

void LowerTri::Set(int i, int j, int x)
{
    // setter for LT matrix given row major indices
    if (i >= j)
    {
        A[(i * (i - 1) / 2) + j - 1] = x;
    }
}

int LowerTri::Get(int i, int j)
{
    // getter for LT matrix given row major indices
    if (i>=j)
        return A[(i * (i - 1) / 2) + j - 1];
    return 0;
}

void LowerTri::Display()
{
    // display for LT matrix given row major indices
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i >= j)
            {
                cout << A[(i * (i + 1)) / 2 + j] << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << "\n";
    }
}

int LowerTri::GetDimension()
{
    // get size of n dimension of LT matrix
    return n;
}

int main()
{
    #if 0
    struct Matrix m;
    int i, j, x;
    
    printf("Enter Dimension");
    scanf("%d", &m.n);
    
    m.A = (int *)malloc( ( (m.n * (m.n+1)) / 2) * sizeof(int)); // allocate (n * (n + 1) )/ 2 * size of int for array
    
    printf("enter all elements");
    for(i = 1; i <= m.n; i++)
    {
        for(j = 1; j <= m.n; j++)
        {
            scanf("%d", &x);
            Set(&m, i, j, x);
        }
    }
    
    printf("\n\n");
    
    Display(m);
    
    #endif
    
    #if 1
    int d;
    cout << "Enter Dimensions";
    cin >> d;
    
    LowerTri lm(d);
    
    int x;
    cout << "Enter All Elements";
    for(int i = 1; i <= d; i++)
    {
        for(int j = 1; j <= d; j++)
        {
            cin >> x;
            lm.Set(i, j, x);
        }
    }
    
    lm.Display();
    
    cout << "\n\n" << endl;
    
    #endif
    return 0;
}