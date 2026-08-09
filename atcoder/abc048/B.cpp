/*
思路：a <= kx <= b
ceil(a/x) <= k <= floor(b/x)
ans = r - l + 1

时间：O(1)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll a, b, x;
    cin >> a >> b >> x;
    ll ans = b / x - (a + x - 1) / x + 1;
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