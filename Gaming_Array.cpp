#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int>a;
    for(int i = 0;i < N;i++)
    {
        int f;
        cin >> f;
        a.push_back(f);
    }

    int prev = a[0],cnt = 1;
    int max = *max_element(a.begin(),a.end());
    for(int i = 1;i < N;i++)
    {
        if(prev < a[i])
        {
            cnt++;
        }

        if(a[i] == max)
            break;

        prev = a[i];
    }

    if(cnt % 2 == 1)
        cout << "Player 1 wins" << endl;
    else
        cout << "Player 2 wins" << endl;
}
