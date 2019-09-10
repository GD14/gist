#include <bits/stdc++.h>
using namespace std;

string toString(vector<vector<int>>& a)
{
    int n = a.size();
    string ans = "";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans = ans + to_string(a[i][j]);
    return ans;
}

bool work(vector<vector<int>>& board, int n, int m)
{
    set<string> visited;
    string target = "";
    for (int i = 1; i < n * n; i++)
        target += to_string(i);
    target += "0";

    vector<vector<int>> currBoard(board);
    queue<vector<vector<int>>> q;
    q.push(currBoard);
    int step = 0;
    int r[4] = { -1, 0, 1, 0 };
    int c[4] = { 0, 1, 0, -1 };

    while (!q.empty()) {

        int sz = q.size();
        while (sz--) {
            currBoard = q.front();
            q.pop();
            string currString = toString(currBoard);
            if (visited.find(currString) != visited.end())
                continue;
            visited.insert(currString);
            if (currString == target)
                return true;
            int x = -1;
            int y = -1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    if (currBoard[i][j] == 0) {
                        x = i;
                        y = j;
                    }
                if (x != -1)
                    break;
            }
            for (int i = 0; i < 4; ++i) {
                int new_r = x + r[i];
                int new_c = y + c[i];
                if (new_r >= 0 && new_r < n && new_c >= 0 && new_c < n) {
                    swap(currBoard[new_r][new_c], currBoard[x][y]);
                    if (visited.find(toString(currBoard)) == visited.end()) {
                        q.push(currBoard);
                    }
                    swap(currBoard[new_r][new_c], currBoard[x][y]);
                }
            }
        }
        ++step;
        if (step > m)
            return false;
    }
    return false;
}

int main(int argc, char* argv[])
{
    int t;
    int n, m;
    cin >> t;
    while (t > 0) {
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        }

        if (work(a, n, m))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        t--;
    }
    return 0;
}