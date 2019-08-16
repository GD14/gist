
#include <bits/stdc++.h>
using namespace std;

int strStr(string str, string substr)
{
    if (str.empty())
        return -1;
    if (substr.empty())
        return 0;

    vector<int> p(str.size(), 0);
    int i = 0;
    int j = 0;
    for (i = 1; i < substr.size() - 1; i++) {
        while (j > 0 && substr[i] != substr[j])
            j = p[j];
        if (substr[i] == substr[j])
            j += 1;
        p[i + 1] = j;
    }
    j = 0;
    for (i = 0; i < str.size(); i++) {
        while (j > 0 && str[i] != substr[j])
            j = p[j];
        if (str[i] == substr[j])
            j = j + 1;
        if (j == substr.size())
        {
            return i + 1 - j;
        }
    }
    return -1;
}
int main(int argc, char* argv[])
{
    string s1 = "abcdefggd";
    string s2 = "ggd";
    cout << strStr(s1, s2) << endl;
    return 0;
}