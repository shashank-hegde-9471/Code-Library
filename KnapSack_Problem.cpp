#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int N;
    cin >> N;

    int wt[N],val[N];
    for(int i = 0;i < N;i++)
    {
        cin >> wt[i] >> val[i];
    }

    int k;
    cin >> k;
    int K[N + 1][k + 1],jj = 0;
    for(int i = 0;i <= N;i++)
    {
        for(int j = 0;j <= k;j++)
        {
            if(i == 0 || j == 0)
                K[i][j] = 0;

            else if(wt[i - 1] <= j)
            {
                K[i][j] = max(val[i - 1] + K[i - 1][j - wt[i - 1]],K[i - 1][j]);
            }


            else
            {
                K[i][j] = K[i - 1][j];
            }

        }
    }

    cout << K[N][k] << endl;

    return 0;
}
