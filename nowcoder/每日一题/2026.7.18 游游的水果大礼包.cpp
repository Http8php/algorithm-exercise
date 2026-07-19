/*
知识点：枚举

思路：枚举两个大礼包各自的数量，记录最大值

时间：O(min(n / 2, m))
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, m, a, b;
    cin >> n >> m >> a >> b;
    ll ans = 0;
    for (ll x = 0; x <= min(n / 2, m); x++)
    {
        ll y = min(n - x * 2, (m - x) / 2);
        ans = max(ans, x * a + b * y);
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