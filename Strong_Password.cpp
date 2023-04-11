#include<stdio.h>
#include<ctype.h>

int count[4] = {0,0,0,0},count1 = 0;
int flag[4] = {0,0,0,0};
int main()
{
    int N;
    scanf("%d",&N);
    char string[N];
    scanf("%s",string);
    char numbers[10] = "0123456789";
    char lower_case[26] = "abcdefghijklmnopqrstuvwxyz";
    char upper_case[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char special_characters[12] = "!@#$%^&*()-+";
    int j = 0;

    for(int i = 0;i < N;i++)
    {
        if(isdigit(string[i]))
        {
            flag[0] = 1;
            count[0]++;
        }

        else if(isupper(string[i]))
        {
            flag[1] = 1;
            count[1]++;
        }

        else if(islower(string[i]))
        {
            flag[2] = 1;
            count[2]++;
        }

        else{
            while(string[i] != special_characters[j])
            {
                j++;
            }

            if(string[i] == special_characters[j])
            {
                flag[3] = 1;
                count[3]++;
            }
        }
    }

    for(int i = 0;i < 4;i++)
    {
        if(count[i] == 0)
        {
            count1 = count1 + 1;
        }
    }

    if(N < 6){
    int M = 6 - N;
    if(M >= count1)
    {
        printf("%d ",M);
    }

    else{
        printf("%d ",count1);
    }
}

else {
    printf("%d ",count1);
}
}
