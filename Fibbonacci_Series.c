/*Author : Vivek P M
Division : H
Date of Creation : 4-3-2021
Program to display fibbonacci series*/
#include<stdio.h>
int main()
{
    int N,i,t1=0,t2=1,nextt;

    printf("Enter number\n");
    scanf("%d",&N);

    for(i=1;i<=N;i++)
    {
    printf("%d\n",t1);
    nextt=t1+t2;
    t1=t2;
    t2=nextt;
    }

}
