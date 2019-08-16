#include <bits/stdc++.h>
using namespace std;

string Add(string& s1, string& s2)
{
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    string res = "";
    int n1 = s1.size();
    int n2 = s2.size();
    int carry = 0;

    for (int i = 0; i < max(n1, n2); i++) {
        int t = carry;
        if (i < n1)
            t += s1[i] - '0';
        if (i < n2)
            t += s2[i] - '0';
        int x = t % 10;
        carry = t / 10;
        res = to_string(x) + res;
    }
    if (carry != 0)
        res = to_string(carry) + res;
    return res;
}
string add(string& a1, string& a2)
{
    // please write your code here.
    int x1 = a1.find('.');
    int x2 = a2.find('.');
    if (x1 == string::npos && x2 == string::npos) {
        return Add(a1, a2);
    } else if (x1 != string::npos && x2 != string::npos) {
        string s1 = a1.substr(0, x1);
        string k1 = a1.substr(x1 + 1);

        string s2 = a2.substr(0, x2);
        string k2 = a2.substr(x2 + 1);
        int n=max(k1.size(),k2.size());
        string ans1=Add(s1,s2);
        for(int i=k1.size();i<n;i++)
            k1+="0";
        for(int i=k2.size();i<n;i++)
            k2+="0";
        string ans2=Add(k1,k2);

        if(ans2.size()>n)
        {
            string one="1";
            ans1=Add(ans1,one);
            ans1=ans1+"."+ans2.substr(1);
        }else ans1=ans1+"."+ans2;
        return ans1;
    } else if (x1 != string::npos) {
        string s1 = a1.substr(0, x1);
        string k1 = a1.substr(x1 + 1);
        auto ans = Add(s1, a2);
        ans = ans + "." + k1;
        return ans;
    } else {
        string s2 = a2.substr(0, x2);
        string k2 = a2.substr(x2 + 1);
        auto ans = Add(a1, s2);
        ans = ans + "." + k2;
        return ans;
    }
}

// please don't modify any code below.
int main(void)
{
    string a1, a2, a3;
    cin >> a1 >> a2;
    a3 = add(a1, a2);
    cout << a3 << endl;
    return 0;
}