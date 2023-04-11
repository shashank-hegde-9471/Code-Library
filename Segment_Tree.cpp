#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int a[N];
    for(int i = 0;i < N;i++)
    {
        cin >> a[i];
    }

    int b[N * 2];
    for(int i = 0;i < N;i++)
    {
        b[i] = 0;
        b[i + N] = a[i];
    }


    //To find the biggest number in an array
    for(int i = N - 1;i > 0;i--)
    {
        b[i] = max(b[2 * i],b[(2 * i) + 1]);
    }

    cout << b[1] << endl;

    //To update the value in an array
    int i,value;
    cin >> i >> value;
    i += N;
    b[i] = value;
    int newValue;
    while(i > 1)
    {
        i /= 2;
        newValue = max(b[i * 2],b[(i * 2) + 1]);
        if(b[i] != newValue)
            b[i] = newValue;
        else
            break;
    }

    for(int i = 0;i < N * 2;i++)
    {
        cout << b[i] << " ";;
    }

    cout << endl;

    //To find the maximum number with given L and R
    int from,to;
    cin >> from >> to;
    from += N;
    to += N;
    int max1 = INT_MIN;
    while(from < to)
    {
        if((from & 1) == 1)
        {
            max1 = max(max1,b[from]);
            from++;
        }

        if((to & 1) == 1)
        {
            to--;
            max1 = max(max1,b[to]);
        }

        from /= 2;
        to /= 2;
    }

    cout << max1 << endl;
}
