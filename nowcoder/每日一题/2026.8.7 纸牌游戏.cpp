/*
思路：四张手牌，考虑分类讨论，设a1>=a2,b1>=b2
1.a1,a2>max(b1, b2) Alex必赢，一共2×2种
2.a2=b1
2a.b2是最小牌 Alex能赢一把，回合顺序无影响，2种
2b.其他情况赢不了，0种
3.a1,b1>a2,b2
3a.a1>b1,a2>b2 2种
3b.a1=b1,a2>b2 2种
3c.a1>b1,a2=b2 2种
3d.其他情况要么平局要么输，0种

时间：O(1)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    vector<int>a(2), b(2);
    for (int i = 0; i < 2; i++) cin >> a[i];
    for (int i = 0; i < 2; i++) cin >> b[i];
    if (a[0] < a[1]) swap(a[0], a[1]);
    if (b[0] < b[1]) swap(b[0], b[1]);
    if (a[1] > b[0])
    {
        cout << 4 << '\n';
    }
    else if (a[1] == b[0])
    {
        if (a[0] > b[0] || a[0] > b[1])
        {
            cout << 4 << '\n';
        }
        else
        {
            cout << 0 << '\n';
        }
    }
    else
    {
        if (a[0] > b[0] && a[1] >= b[1])
        {
            cout << 2 << '\n';
        }
        else if (a[0] >= b[0] && a[1] > b[1])
        {
            cout << 2 << '\n';
        }
        else
        {
            cout << 0 << '\n';
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}