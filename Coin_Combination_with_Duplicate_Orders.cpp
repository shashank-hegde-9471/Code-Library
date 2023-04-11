#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int coins[N];
    for(int i = 0;i < N;i++)
    {
        cin >> coins[i];
    }

    int sum;
    cin >> sum;
    int dp[sum + 1] = {0};
    dp[0] = 1;
    for(int i = 1;i <= sum;i++)
    {
        for(int j = 0;j < N;j++)
        {
            if(i - coins[j] >= 0)
            {
                dp[i] += dp[i - coins[j]];
            }
        }
    }

    cout << dp[sum] << endl;
}
