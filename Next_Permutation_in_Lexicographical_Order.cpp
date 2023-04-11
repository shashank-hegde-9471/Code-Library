#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a;
    cin >> a;
    int first = -1;
    for(int i = a.size() - 1;i >= 0;i--)
    {
        if(a[i] < a[i + 1])
        {
            first = i;
        }
    }

    int max = -1,idx = -1;
    for(int i = 0;i < a.size();i++)
    {
        if(int(a[i]) > max)
        {
            max = int(a[i]);
            idx = i;
        }
    }

    int max1 = 0,second = -1;
    for(int i = first;i < a.size();i++)
    {
        if(int(a[i]) > max1 && idx != i)
        {
            max1 = int(a[i]);
            second = i;
        }
    }

    swap(a[first],a[second]);

    vector<int>b;
    for(int i = first + 1;i < a.size();i++)
    {
        b.push_back(a[i]);
    }

    reverse(b.begin(),b.end());
    int cnt = 0;
    for(int i = first + 1;i < a.size();i++)
    {
        a[i] = b[cnt++];
    }

    cout << a << endl;
}
