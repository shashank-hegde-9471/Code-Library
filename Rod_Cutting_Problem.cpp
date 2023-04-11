#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int rc[N + 1] = {0};

    //O(n*n) solution
    //To find the maximum product with n cuts
    for(int i = 2; i <= N; i++)
    {
        for(int j = 1; j <= i / 2; j++)
        {
            int x = max(rc[i],j * (i - j));
            rc[i] = max(x,j * rc[i - j]);
        }

        cout << rc[i] << endl;
    }

    //O(1) solution
    //To find the maximum product with 2 cuts
    if(N % 2 == 0)
        cout << N * N / 4 << endl;
    else
        cout << (N / 2) * ((N / 2) + 1) << endl;
}

