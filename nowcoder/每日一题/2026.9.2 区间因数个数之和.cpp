/*
标签：整除分块

思路：处理[l,r]之间的因子数量，可以分别算出[1,n]和[1,l-1]的因子数量
根据前缀和思想，答案是f(r)-f(l-1)
发现[floor(n/i),floor(n/v)]的区间内，答案均为v=floor(n/i)
这样将整个区间分成根号个区间，就可以快速处理了

时间：O(sqrt(r))
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll calc(ll n)
{
    ll res = 0;
    for (ll l = 1, r; l <= n; l = r + 1)
    {
        ll v = n / l;
        r = n / v;
        res += (r - l + 1) * v;
    }
    return res;
}
void solve()
{
    ll l, r;
    cin >> l >> r;
    cout << calc(r) - calc(l - 1);
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