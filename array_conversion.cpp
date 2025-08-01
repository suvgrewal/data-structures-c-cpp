#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Array
{
    private:
        // private data members
        int *A;
        int size;
        int length;
        
        void swap(int *x, int *y); // private as the function is only useful inside the class
    public:
        // public functions
        Array()
        {
            // default constructor
            size = 10;
            length = 0;
            A = new int[size];
        }
        Array(int sz)
        {
            // constructor
            size = sz;
            length = 0;
            A = new int[size];
        }
        ~Array()
        {
            // destructor
            delete []A;
        }
        
        void Display();
        void Append(int x);
        void Insert(int index, int x);
        int Delete(int index);

        int LinearSearch(int key);
        int BinarySearch(int key);
        // int RBinSearch(int a[], int l, int h, int key);
        int Get(int index);
        void Set(int index, int x);
        int Max();
        int Min();
        int Sum();
        float Avg();
        void Reverse();
        void Reverse2();
        void InsertSort(int x);
        int isSorted();
        void Rearrange();
        Array* Merge(Array *arr2);
        Array* Union(Array *arr2);
        Array* Intersection(Array *arr2);
        Array* Difference(Array *arr2);
};

void Array::Display()
{
    int i;
    printf("\nElements are\n");
    for(i=0;i<length;i++)
    {
        printf("%d ",A[i]);
    } // end for
} // end Display

 // end Display
void Array::Append(int x)
{
    if(length<size)
    {
        A[length++]=x;
    } // end if
} // end Append

void Array::Insert(int index,int x)
{
    int i;
    if(index>=0 && index <=length)
    {
        for(i=length;i>index;i--) 
        {
            A[i]=A[i-1];
        } // end for
        A[index]=x;
        length++;
    } // end if
} // end Insert

int Array::Delete(int index)
{
    int x=0;
    int i;

    if(index>=0 && index<length)
    {
        x=A[index];
        for(i=index;i<length-1;i++)
        {
            A[i]=A[i+1];
        } // end for
        length--;
        return x;
    } // end if

    return 0;
} // end Delete

void Array::swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
} // end swap

int Array::LinearSearch(int key)
{
    int i;
    for(i=0;i<length;i++)
    {
        if(key==A[i])
        {
            swap(&A[i],&A[0]);
            return i;
        } // end if
    } // end for
    return -1;
} // end LinearSearch

int Array::BinarySearch(int key)
{
    int l,mid,h;
    l=0;
    h=length-1;

    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==A[mid])
        {
            return mid;
        } // end if
        else if(key<A[mid])
        {
            h=mid-1;
        } // end else if
        else
        {
            l=mid+1;
        } // end else
    } // end while
    return -1;
} // end BinarySearch

#if 0
int RBinSearch(int a[],int l,int h,int key)
{
    int mid;

    if(l<=h)
    {
        mid=(l+h)/2;
        if(key==a[mid])
        {
            return mid;
        } // end if
        else if(key<a[mid])
        {
            return RBinSearch(a,l,mid-1,key);
        } // end else if
        else
        {
            return RBinSearch(a,mid+1,h,key);
        } // end else
    } // end if
    return -1;
} // end RBinSearch
#endif

int Array::Get(int index)
{
    if(index>=0 && index<length)
    {
        return A[index];
    } // end if
    return -1;
} // end Get

void Array::Set(int index,int x)
{
    if(index>=0 && index<length)
    {
        A[index]=x;
    } // end if
} // end Set

int Array::Max()
{
    int max=A[0];
    int i;
    for(i=1;i<length;i++)
    {
        if(A[i]>max)
        {
            max=A[i];
        } // end if
    } // end for
    return max;
} // end Max

int Array::Min()
{
    int min=A[0];
    int i;
    for(i=1;i<length;i++)
    {
        if(A[i]<min)
        {
            min=A[i];
        } // end if
    } // end for
    return min;
} // end Min

int Array::Sum()
{
    int s=0;
    int i;
    for(i=0;i<length;i++)
    {
        s+=A[i];
    } // end for

    return s;
} // end Sum

float Array::Avg()
{
    return (float)Sum()/length;
} // end Avg

void Array::Reverse()
{
    int *B;
    int i,j;

    B=(int *)malloc(length*sizeof(int));
    for(i=length-1,j=0;i>=0;i--,j++)
    {
        B[j]=A[i];
    } // end for
    
    for(i=0;i<length;i++)
    {
        A[i]=B[i];
    } // end for

} // end Reverse

void Array::Reverse2()
{
    int i,j;
    for(i=0,j=length-1;i<j;i++,j--)
    {
        swap(&A[i],&A[j]);
    } // end for
} // end Reverse2

void Array::InsertSort(int x)
{
    int i=length-1;
    if(length==size)
    {
        return;
    } // end if
    while(i>=0 && A[i]>x)
    {
        A[i+1]=A[i];
        i--;
    } // end while
    A[i+1]=x;
    length++;
} // end InsertSort

int Array::isSorted()
{
    int i;
    for(i=0;i<length-1;i++)
    {
        if(A[i]>A[i+1])
        {
            return 0;
        } // end if
    } // end for
    return 1;
} // end isSorted

void Array::Rearrange()
{
    int i,j;
    i=0;
    j=length-1;

    while(i<j)
    {
        while(A[i]<0)i++;
        {
            while(A[j]>=0)j--;
            {
                if(i<j)
                {
                    swap(&A[i],&A[j]);
                } // end if
            } // end while
        } // end while
    } // end while
} // end Rearrange

Array* Array::Merge(Array *arr2)
{
    int i,j,k;
    i=j=k=0;

    Array *arr3=(Array
    *)malloc(sizeof(Array));

    while(i<length && j<length)
    {
        if(A[i]<A[j])
        {
            A[k++]=A[i++];
        } // end if
        else
        {
            A[k++]=A[j++];
        } // end else
    } // end while
    for(;i<length;i++)
    {
        A[k++]=A[i];
    } // end for
    for(;j<length;j++)
    {
        A[k++]=A[j];
    } // end for
    length=length+length;
    size=10;

    return arr3;
} // end Merge

Array* Array::Union(Array
*arr2)
{
    int i,j,k;
    i=j=k=0;

    Array *arr3=(Array
    *)malloc(sizeof(Array));

    while(i<length && j<length)
    {
        if(A[i]<A[j])
        A[k++]=A[i++];
        else if(A[j]<A[i])
        A[k++]=A[j++];
        else
        {
        A[k++]=A[i++];
        j++;
        }
    } // end while
    
    for(;i<length;i++)
    {
        A[k++]=A[i];
    } // end for
    
    for(;j<length;j++)
    {
        A[k++]=A[j];
    } // end for

    length=k;
    size=10;

    return arr3;
} // end Union

Array* Array::Intersection(Array *arr2)
{
    int i,j,k;
    i=j=k=0;

    Array *arr3 = (struct Array
    *)malloc(sizeof(Array));

    while(i<length && j<length)
    {
    if(A[i]<A[j])
    i++;
    else if(A[j]<A[i])
    j++;
    else if(A[i]==A[j])
    {
    A[k++]=A[i++];
    j++;
    }
    }

    length=k;
    size=10;

    return arr3;
} // end Intersection

Array* Array::Difference(Array *arr2)
{
    int i,j,k;
    i=j=k=0;

    Array *arr3=(struct Array
    *)malloc(sizeof(struct Array));

    while(i<length && j<length)
    {
        if(A[i]<A[j])
        { 
            A[k++]=A[i++];
        } // end if
        else if(A[j]<A[i])
        {
            j++;
        } // end else if
        else
        {
            i++;
            j++;
        } // end else
    } // end while
    
    for(;i<length;i++)
    {
        A[k++]=A[i];
    } // end for

    length=k;
    size=10;

    return arr3;
} // end Array

int main()
{
    Array *arr1;
    int ch, sz;
    int x,index;

    printf("Enter Size of Array");
    scanf("%d",&sz);
    arr1=new Array(sz);

    do
    {
        printf("\n\nMenu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6.Exit\n");

        printf("enter you choice ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter an element and index");
                scanf("%d%d",&x,&index);
                arr1->Insert(index,x);
                break;
            case 2:
                printf("Enter index ");
                scanf("%d",&index);
                x=arr1->Delete(index);
                printf("Deleted Element is %d\n",x);
                break;
            case 3:
                printf("Enter element to search ");
                scanf("%d",&x);
                index=arr1->LinearSearch(x);
                printf("Element index %d",index);
                break;
            case 4:
                printf("Sum is %d\n",arr1->Sum());
                break;
            case 5:
                arr1->Display();

        } // end switch
    }while(ch<6); // end of do while
    
    return 0;
} // end Main