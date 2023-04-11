#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b;
    cin >> a >> b;
    long long temp = a ^ b,count = 1;
    cout << temp << endl;
    while(temp)
    {
        temp = temp >> 1;
        count = count << 1;
    }

    cout << count - 1 << endl;
}
