/*
标签：模拟

思路：分别检查每行每列和两条对角线有没有满足两个1一个*即可

时间：O(1)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
char a[4][4];
void solve()
{
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= 3; i++)
    {
        int cnt = 0;
        bool ok = false;
        int x = -1, y = -1;
        for (int j = 1; j <= 3; j++)
        {
            cnt += (a[i][j] == '1');
            if (a[i][j] == '*')
            {
                ok = true;
                x = i, y = j;
            }
        }
        if (cnt == 2 && ok)
        {
            cout << "Yes\n";
            cout << x << " " << y;
            return;
        }
    }
    for (int i = 1; i <= 3; i++)
    {
        int cnt = 0;
        bool ok = false;
        int x = -1, y = -1;
        for (int j = 1; j <= 3; j++)
        {
            cnt += (a[j][i] == '1');
            if (a[j][i] == '*')
            {
                ok = true;
                x = j, y = i;
            }
        }
        if (cnt == 2 && ok)
        {
            cout << "Yes\n";
            cout << x << " " << y;
            return;
        }
    }
    int cnt = 0;
    bool ok = false;
    int x = -1, y = -1;
    for (int i = 1; i <= 3; i++)
    {
        cnt += (a[i][i] == '1');
        if (a[i][i] == '*')
        {
            ok = true;
            x = i, y = i;
        }
    }
    if (cnt == 2 && ok)
    {
        cout << "Yes\n";
        cout << x << " " << y;
        return;
    }
    cnt = 0;
    ok = false;
    x = -1, y = -1;
    cnt = (a[1][3] == '1') + (a[2][2] == '1') + (a[3][1] == '1');
    if (a[1][3] == '*')
    {
        ok = true;
        x = 1, y = 3;
    }
    if (a[2][2] == '*')
    {
        ok = true;
        x = 2, y = 2;
    }
    if (a[3][1] == '*')
    {
        ok = true;
        x = 3, y = 1;
    }
    if (cnt == 2 && ok)
    {
        cout << "Yes\n";
        cout << x << " " << y;
        return;
    }
    cout << "No";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}