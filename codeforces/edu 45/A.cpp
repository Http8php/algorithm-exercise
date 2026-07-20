/*
思路：如果n%m不为0，就要建造或拆除
即两者中取价格少的情况

时间：O(1)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, m;
    int a, b;
    cin >> n >> m >> a >> b;
    ll res = n % m;
    if (res == 0)
    {
        cout << 0;
        return;
    }
    ll ans = min(res * b, (m - res) * a);
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