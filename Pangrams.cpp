#include <bits/stdc++.h>

using namespace std;

string pangrams(string s) {
 int x = s.length();
    string z = "abcdefghijklmnopqrstuvwxyz";
    string v = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int h = z.length();
    int count[h];
    for(int i = 0;i < h;i++)
    {
        count[i] = 0;
    }

    for(int i = 0;i < x;i++)
    {
        for(int j = 0;j < h;j++)
        {
            if(s[i] == z[j] || s[i] == v[j])
            {
                if(count[j] == 1)
                    continue;
                count[j]++;
            }
        }
    }

    int sum = 0;
    for(int i = 0;i < h;i++)
    {
        sum = sum + count[i];
    }

    if(sum == 26)
    {
        return "pangram";
    }

    return "not pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
