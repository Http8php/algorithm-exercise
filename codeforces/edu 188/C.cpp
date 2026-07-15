/*
知识点：容斥原理

思路：单独考虑每个人，设小A每x天来，小B每y天来，小C每z天来，一共n天
S：总共 floor(n / x) P：A+B floor(n / lcm(x, y)) lcm表示最小公倍数，这些天两个人才会同时来
同理 Q：A+C floor(n / lcm(x, z)) R：A+B+C floor(n / lcm(x, y, z))
因为二人包含了三人，真正的二人：(P - R) + (Q - R)
立马算出单人：S - P - Q + R
每人可得 单 × 6 + 双 × 3 + 三 × 2

时间：O(1)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll calc(ll n, ll x, ll y, ll z)
{
    ll s = n / x, p = n / lcm(x, y), q = n / lcm(x, z), r = n / lcm(x, lcm(y, z));
    return (s - p - q + r) * 6 + (p + q - 2 * r) * 3 + r * 2;
}
void solve()
{
    ll a, b, c, m;
    cin >> a >> b >> c >> m;
    cout << calc(m, a, b, c) << " " << calc(m, b, a, c) << " " << calc(m, c, a, b) << '\n';
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