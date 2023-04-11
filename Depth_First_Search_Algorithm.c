#include<stdio.h>
#include<stdlib.h>

int visited[10];
void dfs(int m[6][6],int v,int source)
{
    visited[source] = 1;
    for(int i = 0;i < v;i++)
    {
        if(m[source][i] == 1 && visited[i] == 0)
        {
            printf("%d ",i);
            dfs(m,v,i);
        }
    }
}

int main()
{
    int v = 6,source;
    int m[6][6] = {{0,1,0,0,0,0},{1,0,1,0,0,0},{0,1,0,0,0,0},{0,0,0,0,0,1},{0,0,0,0,0,1},{0,0,0,1,1,0}};
    printf("Enter the source vertex\n");
    scanf("%d",&source);
    for(int i = 0;i < v;i++)
    {
        visited[i] = 0;
    }
    printf("DFS Traversal\n");
    printf("%d ",source);
    dfs(m,v,source);
    for(int i = 0;i < v;i++)
    {
        if(visited[i] == 0)
        {
            printf("%d ",i);
            dfs(m,v,i);
        }
    }
}
