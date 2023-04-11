#include<stdio.h>

int max(int a,int b)
{
    if(a > b)
    {
        return a;
    }

    else
    {
        return b;
    }
}

int min(int a,int b)
{
    if(a < b)
    {
        return a;
    }

    else
    {
        return b;
    }
}

int platforms(float arr[],float b[],int N)
{
    int platform = 1,result = 1;
    for(int i = 0;i < N;i++)
    {
        platform = 1;
        for(int j = i + 1;j < N;j++)
        {
            if(max(arr[i],arr[j]) <= min(b[i],b[j]))
            {
                platform++;
            }
        }

        result = max(result,platform);
    }

    return result;
}

int main()
{
    int N;
    scanf("%d",&N);
    float a[N],b[N];
    for(int i = 0;i < N;i++)
    {
        scanf("%f%f",&a[i],&b[i]);
    }

    printf("%d ",platforms(a,b,N));
}
