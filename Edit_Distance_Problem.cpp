#include<bits/stdc++.h>
using namespace std;

int main()
{
    string src,dest;
    cin >> src >> dest;
    int len1 = src.size(),len2 = dest.size();
    int ED[len1 + 1][len2 + 1];
    for(int i = 0;i <= len1;i++)
    {
        ED[i][0] = i;
    }

    for(int j = 0;j <= len2;j++)
    {
        ED[0][j] = j;
    }

    for(int i = 1;i <= len1;i++)
    {
        for(int j = 1;j <= len2;j++)
        {
            ED[i][j] = 0;
        }
    }

    for(int i = 1;i <= len1;i++)
    {
        for(int j = 1;j <= len2;j++)
        {
            if(src[i - 1] == dest[j - 1])
            {
                ED[i][j] = ED[i - 1][j - 1];
            }

            else
            {
                int m = min(ED[i - 1][j],ED[i][j - 1]);
                m = min(m,ED[i - 1][j - 1]);
                ED[i][j] = m + 1;
            }
        }
    }


    cout << ED[len1][len2] << endl;
}
