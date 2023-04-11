#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int a[N];
    for(int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    int sum;
    cin >> sum;
    int dp[sum + 1] = {0};
    for(int i = 1; i <= sum; i++)
    {
        int m = INT_MAX;
        for(int j = 0; j < N; j++)
        {
            if(i - a[j] >= 0)
            {
                if(dp[i - a[j]] != 0 || i - a[j] == 0)
                {
                    m = min(dp[i - a[j]] + 1,m);
                }
            }
        }

        if(m == INT_MAX)
        {
            dp[i] = 0;
        }

        else
            dp[i] = m;
    }

    if(dp[sum])
    {
        cout << dp[sum] << endl;
    }

    else
        cout << -1 << endl;
}
