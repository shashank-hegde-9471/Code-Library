#include<stdio.h>

int main()
{
    int N,max = 0;
    scanf("%d",&N);
    int a[N];
    for(int i = 0;i < N;i++)
    {
        scanf("%d",&a[i]);
    }

    for(int i = 0;i < N;i++)
    {
        if(a[i] > max)
        {
            max = a[i];
        }
    }

    int b[max + 1];
    for(int i = 0;i < max + 1;i++)
    {
        b[i] = 0;
    }

    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < max + 1;j++)
        {
            if(a[i] == j)
            {
                b[j]++;
            }
        }
    }

    int c[N],j = 0;
    for(int i = 0;i < max + 1;i++)
    {
        while(b[i] != 0)
        {
            c[j] = i;
            j++;
            b[i]--;
        }
    }

    for(int i = 0;i < N;i++)
    {
        printf("%d ",c[i]);
    }
}
