/*
思路：实时维护两个向量，计算它们的叉积，就能知道相对旋转位置

单组时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<ll>x(n + 1), y(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }
    ll px = x[2] - x[1], py = y[2] - y[1];
    for (int i = 3; i <= n; i++)
    {
        ll cx = x[i] - x[i-1], cy = y[i] - y[i-1];
        ll res = px * cy - py * cx;
        if (res == 0) cout << "STRAIGHT ";
        else if (res < 0) cout << "RIGHT ";
        else cout << "LEFT ";
        px = cx, py = cy;
    }
    cout << '\n';
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