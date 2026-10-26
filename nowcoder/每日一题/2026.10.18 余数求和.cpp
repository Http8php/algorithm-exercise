/*
标签：整除分块

思路：对于n>k的部分，k%i=k，所以贡献是(n-k)*k
对于n<=k的部分，考虑把模数拆开，变成k-i*floor(k/i)
floor(k/i)是整除分块的形式，令v=floor(k/l)
在[l, r=floor(k/v)]中，每个数贡献都是v，令len=r-l+1
总贡献为len*k-v*(l+r)*len/2
因为len+l+r=2r+1，奇数，所以分母两个数一定一奇一偶，能被2整除

时间：O(k^{1/2})
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, k, ans = 0;
    cin >> n >> k;
    ll lim = min(n, k);
    for (ll l = 1, r = 0; l <= lim; l = r + 1)
    {
        ll v = k / l;
        if (v == 0) break;
        r = min(lim, k / v);
        ans += (r - l + 1) * k - v * (l + r) * (r - l + 1) / 2;
    }
    if (n > k) ans += (n - k) * k;
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