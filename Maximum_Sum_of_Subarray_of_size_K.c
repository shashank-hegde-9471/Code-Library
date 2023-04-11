#include<stdio.h>

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int *a,int l,int r)
{
    int i = l;
    int j = r + 1;
    int p = a[l];

    do
    {
        do
        {
            i++;
        }while(a[i] < p);

        do
        {
            j--;
        }while(a[j] > p);

        swap(&a[i],&a[j]);
    }while(i <= j);

    swap(&a[i],&a[j]);
    swap(&a[l],&a[j]);
    return j;
}

void quicksort(int *a,int l,int r)
{
    if(l < r)
    {
        int s = Partition(a,l,r);
        quicksort(a,l,s - 1);
        quicksort(a,s + 1,r);
    }
}

int main()
{
    int N,k;
    scanf("%d%d",&N,&k);
    int a[N];
    for(int i = 0;i < N;i++)
    {
        scanf("%d",&a[i]);
    }

    quicksort(a,0,N - 1);
    int sum = 0,i = 0;
    while(k--)
    {
        sum = sum + a[N - i - 1];
        i++;
    }

    printf("%d",sum);
}
