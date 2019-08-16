#include <bits/stdc++.h>
using namespace std;
string work(string s)
{
    if (s.empty())
        return "";
    string str(2 * s.size() + 1, '#');
    for (int i = 0; i < s.size(); i++)
        str[2 * i + 1] = s[i];

    vector<int> p(str.size() + 1, 0);
    int c = 0;
    int k = 0;

    for (int i = 1; i < str.size(); i++) {
        if (i <= c + p[c]) {
            int x = 2 * c - i;
            p[i] = min(c + p[c] - i, p[x]);
        }
        while (i - p[i] >= 0 && i + p[i] < str.size() && str[i - p[i]] == str[i + p[i]])
            p[i]++;
        p[i]--;
        if (i + p[i] > c + p[c])
            c = i;
        if (p[i] > p[k])
            k = i;
    }

    string result;
    for (int i = k - p[k]; i <= k + p[k]; i++)
        if (str[i] != '#')
            result += str[i];
    return result;
}
int main(int argc, char* argv[])
{
    string s1 = "abcdedcb";
    cout << work(s1) << endl;
    return 0;
}