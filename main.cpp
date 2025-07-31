#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");
    for(i=0;i<arr.length;i++)
    {
        printf("%d ",arr.A[i]);
    } // end for
} // end Display

 // end Display
void Append(struct Array *arr,int x)
{
    if(arr->length<arr->size)
    {
        arr->A[arr->length++]=x;
    } // end if
} // end Append

void Insert(struct Array *arr,int index,int x)
{
    int i;
    if(index>=0 && index <=arr->length)
    {
        for(i=arr->length;i>index;i--) 
        {
            arr->A[i]=arr->A[i-1];
        } // end for
        arr->A[index]=x;
        arr->length++;
    } // end if
} // end Insert

int Delete(struct Array *arr,int index)
{
    int x=0;
    int i;

    if(index>=0 && index<arr->length)
    {
        x=arr->A[index];
        for(i=index;i<arr->length-1;i++)
        {
            arr->A[i]=arr->A[i+1];
        } // end for
        arr->length--;
        return x;
    } // end if

    return 0;
} // end Delete

void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
} // end swap

int LinearSearch(struct Array *arr,int key)
{
    int i;
    for(i=0;i<arr->length;i++)
    {
        if(key==arr->A[i])
        {
            swap(&arr->A[i],&arr->A[0]);
            return i;
        } // end if
    } // end for
    return -1;
} // end LinearSearch

int BinarySearch(struct Array arr,int key)
{
    int l,mid,h;
    l=0;
    h=arr.length-1;

    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==arr.A[mid])
        {
            return mid;
        } // end if
        else if(key<arr.A[mid])
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

int Get(struct Array arr,int index)
{
    if(index>=0 && index<arr.length)
    {
        return arr.A[index];
    } // end if
    return -1;
} // end Get

void Set(struct Array *arr,int index,int x)
{
    if(index>=0 && index<arr->length)
    {
        arr->A[index]=x;
    } // end if
} // end Set

int Max(struct Array arr)
{
    int max=arr.A[0];
    int i;
    for(i=1;i<arr.length;i++)
    {
        if(arr.A[i]>max)
        {
            max=arr.A[i];
        } // end if
    } // end for
    return max;
} // end Max

int Min(struct Array arr)
{
    int min=arr.A[0];
    int i;
    for(i=1;i<arr.length;i++)
    {
        if(arr.A[i]<min)
        {
            min=arr.A[i];
        } // end if
    } // end for
    return min;
} // end Min

int Sum(struct Array arr)
{
    int s=0;
    int i;
    for(i=0;i<arr.length;i++)
    {
        s+=arr.A[i];
    } // end for

    return s;
} // end Sum

float Avg(struct Array arr)
{
    return (float)Sum(arr)/arr.length;
} // end Avg

void Reverse(struct Array *arr)
{
    int *B;
    int i,j;

    B=(int *)malloc(arr->length*sizeof(int));
    for(i=arr->length-1,j=0;i>=0;i--,j++)
    {
        B[j]=arr->A[i];
    } // end for
    
    for(i=0;i<arr->length;i++)
    {
        arr->A[i]=B[i];
    } // end for

} // end Reverse

void Reverse2(struct Array *arr)
{
    int i,j;
    for(i=0,j=arr->length-1;i<j;i++,j--)
    {
        swap(&arr->A[i],&arr->A[j]);
    } // end for
} // end Reverse2

void InsertSort(struct Array *arr,int x)
{
    int i=arr->length-1;
    if(arr->length==arr->size)
    {
        return;
    } // end if
    while(i>=0 && arr->A[i]>x)
    {
        arr->A[i+1]=arr->A[i];
        i--;
    } // end while
    arr->A[i+1]=x;
    arr->length++;
} // end InsertSort

int isSorted(struct Array arr)
{
    int i;
    for(i=0;i<arr.length-1;i++)
    {
        if(arr.A[i]>arr.A[i+1])
        {
            return 0;
        } // end if
    } // end for
    return 1;
} // end isSorted

void Rearrange(struct Array *arr)
{
    int i,j;
    i=0;
    j=arr->length-1;

    while(i<j)
    {
        while(arr->A[i]<0)i++;
        {
            while(arr->A[j]>=0)j--;
            {
                if(i<j)
                {
                    swap(&arr->A[i],&arr->A[j]);
                } // end if
            } // end while
        } // end while
    } // end while
} // end Rearrange

struct Array* Merge(struct Array *arr1,struct Array
*arr2)
{
    int i,j,k;
    i=j=k=0;

    struct Array *arr3=(struct Array
    *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
        {
            arr3->A[k++]=arr1->A[i++];
        } // end if
        else
        {
            arr3->A[k++]=arr2->A[j++];
        } // end else
    } // end while
    for(;i<arr1->length;i++)
    {
        arr3->A[k++]=arr1->A[i];
    } // end for
    for(;j<arr2->length;j++)
    {
        arr3->A[k++]=arr2->A[j];
    } // end for
    arr3->length=arr1->length+arr2->length;
    arr3->size=10;

    return arr3;
} // end Merge

struct Array* Union(struct Array *arr1,struct Array
*arr2)
{
    int i,j,k;
    i=j=k=0;

    struct Array *arr3=(struct Array
    *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
        arr3->A[k++]=arr1->A[i++];
        else if(arr2->A[j]<arr1->A[i])
        arr3->A[k++]=arr2->A[j++];
        else
        {
        arr3->A[k++]=arr1->A[i++];
        j++;
        }
    } // end while
    
    for(;i<arr1->length;i++)
    {
        arr3->A[k++]=arr1->A[i];
    } // end for
    
    for(;j<arr2->length;j++)
    {
        arr3->A[k++]=arr2->A[j];
    } // end for

    arr3->length=k;
    arr3->size=10;

    return arr3;
} // end Union

struct Array* Intersection(struct Array *arr1,struct
Array *arr2)
{
    int i,j,k;
    i=j=k=0;

    struct Array *arr3=(struct Array
    *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
    if(arr1->A[i]<arr2->A[j])
    i++;
    else if(arr2->A[j]<arr1->A[i])
    j++;
    else if(arr1->A[i]==arr2->A[j])
    {
    arr3->A[k++]=arr1->A[i++];
    j++;
    }
    }

    arr3->length=k;
    arr3->size=10;

    return arr3;
} // end Intersection

struct Array* Difference(struct Array *arr1,struct
Array *arr2)
{
    int i,j,k;
    i=j=k=0;

    struct Array *arr3=(struct Array
    *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
        { 
            arr3->A[k++]=arr1->A[i++];
        } // end if
        else if(arr2->A[j]<arr1->A[i])
        {
            j++;
        } // end else if
        else
        {
            i++;
            j++;
        } // end else
    } // end while
    
    for(;i<arr1->length;i++)
    {
        arr3->A[k++]=arr1->A[i];
    } // end for

    arr3->length=k;
    arr3->size=10;

    return arr3;
} // end Array

int main()
{
    struct Array arr1;
    int ch;
    int x,index;

    printf("Enter Size of Array");
    scanf("%d",&arr1.size);
    arr1.A=(int *)malloc(arr1.size*sizeof(int));
    arr1.length=0;
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
                Insert(&arr1,index,x);
                break;
            case 2:
                printf("Enter index ");
                scanf("%d",&index);
                x=Delete(&arr1,index);
                printf("Deleted Element is %d\n",x);
                break;
            case 3:
                printf("Enter element to search ");
                scanf("%d",&x);
                index=LinearSearch(&arr1,x);
                printf("Element index %d",index);
                break;
            case 4:
                printf("Sum is %d\n",Sum(arr1));
                break;
            case 5:
                Display(arr1);

        } // end switch
    }while(ch<6); // end of do while
    
    return 0;
} // end Main