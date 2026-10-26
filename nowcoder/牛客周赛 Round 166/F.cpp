/*
标签：动态规划

思路：不能相邻取订单，也就是第i个位置不能选，然后在[1,i-1]和[i+1,n]中分别各选k个
设pre[i][k]为前i个位置选k个位置的最小价格，suf[i][k]为后i个位置选k个位置的最小价格
pre[i][k] = min(pre[i-1][k], pre[i-2][k-1])
suf[i][k] = min(suf[i+1][k], suf[i+2][k-1])
初始k=0，最小价格为0
发现k只与k-1有关，于是可以滚动数组优化
由于要选2k个互不相邻的位置，需要4k+1个位置，枚举k，1<=k<=(n+1)/4
对于每个k，找到最小的pre[i-1][k]+suf[i+1][k]，这个值<=s就是合法的

时间：O(n^2)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, ans = 0;
    ll s;
    cin >> n >> s;
    vector<ll>a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    vector<ll>pre(n + 1), suf(n + 2);
    for (int k = 1; k <= (n + 1) / 4; k++)
    {
        vector<ll>np(n + 1, 1e18), ns(n + 2, 1e18);
        for (int i = 1; i <= n; i++)
        {
            np[i] = min(np[i-1], pre[max(0, i - 2)] + a[i]);
        }
        for (int i = n; i >= 1; i--)
        {
            ns[i] = min(ns[i+1], suf[min(n + 1, i + 2)] + b[i]);
        }
        ll res = 1e18;
        for (int i = 1; i <= n; i++)
        {
            res = min(res, np[i-1] + ns[i+1]);
        }
        if (res > s) break;
        ans = k;
        pre = np, suf = ns;
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