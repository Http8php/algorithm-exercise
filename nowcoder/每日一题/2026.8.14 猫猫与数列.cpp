/*
标签：快速幂、模拟

思路：因为通项是幂的形式，增长很快，答案不会很大
a_{n-2}^{a_{n-1}}<=10^18 -> a_{n-1}lg(a_{n-2})<=18
直接模拟即可

时间：O(logq)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll fp(ll a, ll b)
{
    ll ans = 1;
    while (b > 0)
    {
        if (b & 1) ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}
void solve()
{
    int p, q;
    cin >> p >> q;
    ll a1 = p, a2 = q;
    int ans = 2;
    while (a2 * log10(a1) <= 18)
    {
        ll t = fp(a1, a2);
        a1 = a2, a2 = t;
        ans++;
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