#include<stdio.h>
#include<stdlib.h>

int visited[10];
void bfs(int m[10][10],int v,int source)
{
    int queue[20],front = 0,rear = 0,u;
    queue[rear] = source;
    visited[source] = 1;
    while(front <= rear)
    {
        u = queue[front];
        printf("%d ",u);
        front++;
        for(int i = 0;i < v;i++)
        {
            if(m[u][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                rear++;
                queue[rear] = i;
            }
        }
    }
}

int main()
{
    int m[10][10],source,v;
    printf("Enter the number of vertex\n");
    scanf("%d",&v);
    printf("Enter the matrix\n");
    for(int i = 0;i < v;i++)
    {
        for(int j = 0;j < v;j++)
        {
            scanf("%d",&m[i][j]);
        }
    }

    printf("Enter the source vertex\n");
    scanf("%d",&source);
    for(int i = 0;i < v;i++)
    {
        visited[i] = 0;
    }

    printf("BFS Traversal\n");
    printf("%d ",source);
    bfs(m,v,source);
}
