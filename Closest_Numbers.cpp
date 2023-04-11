#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


void findmin(int *a,int N)
{
    int min = a[1] - a[0];
    for(int i = 2; i < N; i++)
    {
        if(min > a[i] - a[i - 1])
        {
            min = a[i] - a[i - 1];
        }
    }

    for(int i = 1; i < N; i++)
    {
        if(a[i] - a[i - 1] == min)
        {
            printf("%d %d ",a[i - 1],a[i]);
        }
    }
}

int partition(int a[], int l, int r)
{
    int pivot, i, j, t;
    pivot = a[l];
    i = l;
    j = r+1;

    while(1)
    {
        do ++i;
        while( a[i] <= pivot && i <= r );
        do --j;
        while( a[j] > pivot );
        if( i >= j ) break;
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    t = a[l];
    a[l] = a[j];
    a[j] = t;
    return j;
}

void quickSort(int a[], int l, int r)
{
    int j;

    if( l < r )
    {
        // divide and conquer
        j = partition( a, l, r);
        quickSort( a, l, j-1);
        quickSort( a, j+1, r);
    }

}

int main()
{
    int N;
    scanf("%d",&N);
    int a[N];
    for(int i = 0; i < N; i++)
    {
        scanf("%d",&a[i]);
    }

    quickSort(a,0,N - 1);

    findmin(a,N);
}
