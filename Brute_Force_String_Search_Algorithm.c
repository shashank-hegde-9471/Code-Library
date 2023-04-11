#include<stdio.h>
#include<string.h>

int brute_force(char T[100],char P[100])
{
    int n,m;
    n = strlen(T);
    m = strlen(P);
    for(int i = 0; i <= n - m; i++)
    {
        int j = 0;
        while(j < m && P[j] == T[i + j])
        {
            j++;
        }

        if(j == m)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    char T[100] = "PRATEEK",P[100] = "b",z;
   /* printf("Enter the text\n");
    scanf("%s",T);
    printf("Enter the pattern\n");
    scanf("%s",P);*/
    z = brute_force(T,P);
    printf("Pattern found at index %d\n",z);
}
