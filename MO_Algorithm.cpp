#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2,MOD = 1e9 + 7;
int rootN;

struct Q
{
    int idx,l,r;
};

Q q[N];

bool compare(Q q1,Q q2)
{
    if(q1.l/rootN == q2.l/rootN)
        return q1.r > q2.r;
    else
        return q1.l/rootN < q2.l/rootN;
}

int main()
{
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
    }

    rootN = sqrtl(n);

    //Sum of numbers in given range (L,R)

    int queries;
    cin >> queries;
    for(int i = 0;i < queries;i++)
    {
        int l,r;
        cin >> l >> r;
        q[i].l = l;
        q[i].r = r;
        q[i].idx = i;
    }

    sort(q,q + queries,compare);
    for(int i = 0;i < queries;i++)
    {
        cout << q[i].l << " " << q[i].r << " " << q[i].idx << endl;
    }
    vector<int>ans(queries);
    int cur_ans = 0,cur_l = 0,cur_r = -1,l,r;
    for(int i = 0;i < queries;i++)
    {
        l = q[i].l;
        r = q[i].r;
        l--;
        r--;

        while(cur_r < r)
        {
            cur_r++;
            cur_ans += a[cur_r];
        }

        while(cur_l > l)
        {
            cur_l--;
            cur_ans += a[cur_l];
        }

        while(cur_l < l)
        {
            cur_ans -= a[cur_l];
            cur_l++;
        }

        while(cur_r > r)
        {
            cur_ans -= a[cur_r];
            cur_r--;
        }

        ans[q[i].idx] = cur_ans;
    }

    for(int i = 0;i < queries;i++)
    {
        cout << q[i].l << " " << q[i].r << " " << q[i].idx << " " << ans[i] << endl;
    }
}

/*
9
1 5 -2 6 8 -7 2 1 11
3
7 8
1 6
2 7
*/
