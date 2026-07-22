/*
思路：最多只能用一张优惠券，遇到可以满减的就减，记录最小值

时间：O(m)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    int ans = n;
    for (int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b;
        if (a <= n) ans = min(ans, n - b);
    }
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