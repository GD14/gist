#include <bits/stdc++.h>
using namespace std;
int a[10][10];
int n;
void removeZero()
{
    for (int i = 2; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            int k = i;
            while (k >= 2 && a[k - 1][j] == 0) {
                swap(a[k - 1][j], a[k][j]);
                k = k - 1;
            }
        }
    }
}
void mergeNum()
{
    removeZero();
    for (int i = 2; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            if (a[i][j] == 0)
                continue;
            if (a[i - 1][j] == a[i][j]) {
                a[i - 1][j] *= 2;
                a[i][j] = 0;
            }
        }
        removeZero();
    }
}
void turnUp(int n)
{
    int tmp[10][10];
    if (n == 1)
        return;
    if (n == 2) {
        for (int i = 1; i <= 4; i++)
            for (int j = 1; j <= 4; j++)
                tmp[i][j] = a[4 - i + 1][j];
    }
    if (n == 3) {
        for (int i = 1; i <= 4; i++)
            for (int j = 1; j <= 4; j++)
                tmp[i][j] = a[4 - j + 1][i];
    }
    if (n == 4) {
        for (int i = 1; i <= 4; i++)
            for (int j = 1; j <= 4; j++)
                tmp[i][j] = a[j][4 - i + 1];
    }
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            a[i][j] = tmp[i][j];
}
void turnBack(int n)
{
    int tmp[10][10];
    if (n == 1)
        return;
    if (n == 2) {
        for (int i = 1; i <= 4; i++)
            for (int j = 1; j <= 4; j++)
                tmp[i][j] = a[4 - i + 1][j];
    }
    if (n == 3) {
        for (int i = 1; i <= 4; i++)
            for (int j = 1; j <= 4; j++)
                tmp[i][j] = a[j][4 - i + 1];
    }
    if (n == 4) {
        for (int i = 1; i <= 4; i++)
            for (int j = 1; j <= 4; j++)
                tmp[i][j] = a[4 - j + 1][i];
    }

    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            a[i][j] = tmp[i][j];
}
int main(int argc, char* argv[])
{
    cin >> n;
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            cin >> a[i][j];
    turnUp(n);
    /*
    cout << "-----" << endl;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << "----" << endl;
    **/
    mergeNum();
    turnBack(n);
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}