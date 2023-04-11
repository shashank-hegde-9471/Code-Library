#include <bits/stdc++.h>

using namespace std;

string superReducedString(string s) {
    string temp = "";
    temp.push_back(s[0]);
    // int flag = 0;
    for(int i = 1;i < s.size();i++)
    {
        if(s[i] == temp[temp.size() - 1])
            temp.pop_back();
        else
        {
            temp.push_back(s[i]);
        }
    }

    if(temp.size() == 0)
        return "Empty String";

    return temp;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
