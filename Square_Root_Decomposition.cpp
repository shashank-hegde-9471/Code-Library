#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000
#define SQRSIZE 100

int arr[MAXN];
int block[SQRSIZE];
int blk_sz;


void update(int idx, int val)
{
    int blockNumber = idx / blk_sz;
    block[blockNumber] += val - arr[idx];
    arr[idx] = val;
}

int query(int l, int r)
{
    int sum = 0;
    while (l < r and l % blk_sz != 0 and l != 0)
    {
        sum += arr[l];
        l++;
    }
    while (l + blk_sz - 1 <= r)
    {
        sum += block[l / blk_sz];
        l += blk_sz;
    }
    while (l <= r)
    {
        sum += arr[l];
        l++;
    }
    return sum;
}

void preprocess(int input[], int n)
{
    int blk_idx = -1;
    blk_sz = sqrt(n);

    for (int i = 0; i < n; i++)
    {
        arr[i] = input[i];
        if (i % blk_sz == 0)
        {
            blk_idx++;
        }
        block[blk_idx] += arr[i];
    }
}

int main()
{
    int N;
    cin >> N;
    int a[N];
    for(int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    preprocess(a, N);

    int z,b,c,d,e,f,g,h;
    cin >> z >> b;

    cout << query(z, b) << endl;
    cin >> c >> d;
    cout << query(c, d) << endl;
    cin >> e >> f;
    update(e, f);
    cin >> g >> h;
    cout << query(g, h) << endl;
    return 0;
}
