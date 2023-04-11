#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin >> N;
    int a[N];
    for(int i = 0;i < N;i++)
    {
        cin >> a[i];
    }

    int count[N],flag = 0,h = 0;

    for(int i = 0;i < N;i++)
    {
        count[i] = 1;
    }
    for(int i = 1;i < N;i++)
    {
        if(a[i - 1] < a[i] && a[i] - a[i - 1] == 1)
        {
            count[h]++;
        }

        else
        {
            h++;
        }
    }

    int max = 0;
    for(int i = 0;i < N;i++)
    {
        if(count[i] > max)
        {
            max = count[i];
        }
    }

    cout << max<< endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
