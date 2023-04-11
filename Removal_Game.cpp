#include<bits/stdc++.h>
using namespace std;

const int N = 2010;
long long n,f[N][N],a[N];
long long dp(int l,int r)
{
    if(l > r)
        return 0;
    if(f[l][r])
        return f[l][r];
    f[l][r]=max(a[l] + min(dp(l + 2,r),dp(l + 1,r - 1)),a[r] + min(dp(l,r - 2),dp(l + 1,r - 1)));
    return f[l][r];
}
int main()
{
    cin >> n;
    for(int i = 0;i < n;i++)
        cin>>a[i];
    cout << dp(0,n-1) << endl;
}
