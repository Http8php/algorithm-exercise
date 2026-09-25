/*
标签：构造

思路：不考虑区间长度，直接构造[x, nx]这个区间，这是最短的
最长的区间是[1, nx+x-1]这个区间，如果k不在这个范围，不可能有方案
有多余的k，放在[1, x)和(nx, nx+x-1]即可

时间：O(1)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, k, x;
    cin >> n >> k >> x;
    ll len = n * x - (x - 1);
    if (k < len || k > len + 2 * (x - 1))
    {
        cout << -1;
        return;
    }
    ll res = k - len;
    if (res <= x - 1)
    {
        ll l = x, r = n * x + res;
        if (r >= 2e9)
        {
            cout << -1;
            return;
        }
        cout << l << " " << r;
    }
    else
    {
        ll l = x - (res - x + 1), r = n * x + x - 1;
        if (r >= 2e9)
        {
            cout << -1;
            return;
        }
        cout << l << " " << r;
    }
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