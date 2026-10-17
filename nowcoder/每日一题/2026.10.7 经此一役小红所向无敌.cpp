/*
思路：小红的血量可以看作无限，所以必然光或对立先track lost
用ceil(h/b), ceil(k/a)计算两人血条均大于0时可以撑几个回合
最后一回合谁的血条大于0谁放大招，分三种情况计算伤害

时间：O(1)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll a, b, h, k;
    cin >> a >> h >> b >> k;
    ll c1 = (h + b - 1) / b, c2 = (k + a - 1) / a;
    ll ans = 0;
    if (c1 > c2) ans = a * 10 + c2 * (a + b);
    else if (c1 < c2) ans = b * 10 + c1 * (a + b);
    else ans = c1 * (a + b);
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