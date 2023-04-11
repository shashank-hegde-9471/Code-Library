#include<bits/stdc++.h>
using namespace std;
void reverseInGroups(vector<long long>& arr, int n, int k)
{
    int cnt = 0;
    if(k >= n)
    {
        reverse(arr.begin(),arr.end());
    }

    else
    {
        /*for(int i = 0; i < arr.size();)
        {
            vector<long long>a;
            for(int j = 0; j < k; j++)
            {
                if(cnt < n)
                    a.push_back(arr[cnt++]);
                else
                    break;
            }

            reverse(a.begin(),a.end());

            for(int l = 0; l < k; l++)
            {
                arr[i] = a[l];
                i++;
            }
        }*/

        for (int i = 0; i < n; i += k)
        {
            int left = i;
            int right = min(i + k - 1, n - 1);
            while (left < right)
                swap(arr[left++], arr[right--]);
        }
    }
}

int main()
{
    int N,k;
    cin >> N >> k;
    vector<long long>a;
    for(int i = 0; i < N; i++)
    {
        long long g;
        cin >> g;
        a.push_back(g);
    }

    reverseInGroups(a,N,k);
    for(int i = 0; i < N; i++)
    {
        cout << a[i] << " ";
    }
}
