#include<stdio.h>
#include<stdlib.h>

int N;

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int a[N])
{
    for(int i = 0; i <= N - 2; i++)
    {
        for(int j = 0; j <= N-2-i; j++)
        {
            if(a[j] > a[j + 1])
            {
                swap(&a[j],&a[j + 1]);
            }
        }
    }

    for(int i = 0; i < N; i++)
    {
        printf("%d ",a[i]);
    }
}

void selection_sort(int a[N])
{
    for(int i = 0; i <= N - 2; i++)
    {
        int min = i;
        for(int j = i + 1; j <= N - 1; j++)
        {
            if(a[j] < a[min])
            {
                min = j;
            }

        }

        swap(&a[i],&a[min]);
    }

    for(int i = 0; i < N; i++)
    {
        printf("%d ",a[i]);
    }
}

void insertion_sort(int a[N])
{
    for(int i = 1; i <= N - 1; i++)
    {
        int v = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > v)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }

        a[j + 1] = v;
    }

    for(int i = 0; i < N; i++)
    {
        printf("%d ",a[i]);
    }
}

int main()
{
    printf("Enter the number of elements\n");
    scanf("%d",&N);
    int a[N],choice;
    printf("Enter the elements\n");
    for(int i = 0; i < N; i++)
    {
        scanf("%d",&a[i]);
    }

    while(1)
    {
        printf("\n1- bubble\n2- selection\n3- insertion\n4- heap\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            bubble_sort(a);
            break;
        case 2:
            selection_sort(a);
            break;
        case 3:
            insertion_sort(a);
            break;
        case 4:
            heap_sort(a);
            break;
        default:
            exit(0);
        }
    }

}
