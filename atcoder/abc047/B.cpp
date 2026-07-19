/*
思路：不需要真的去涂色，只要记录最后缩圈边界即可

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int w, h, n;
    cin >> w >> h >> n;
    int l = 0, r = w, u = h, d = 0;
    for (int i = 0, x, y, a; i < n; i++)
    {
        cin >> x >> y >> a;
        if (a == 1) l = max(l, x);
        else if (a == 2) r = min(r, x);
        else if (a == 3) d = max(d, y);
        else u = min(u, y);
    }
    int ans = (r - l) * (u - d);
    // 需要特判，不然ans可能为负数
    if (l > r || d > u) ans = 0;
    cout << ans;
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