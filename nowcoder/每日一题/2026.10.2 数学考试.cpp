/*
标签：动态规划、dp优化

思路：由于是一题一题写的，所以可以考虑dp
设dp[i][j]为写到第i题，压力值为j时获得的最大分数
如果j压力值可达，往j-w, j, j+q三个方向转移，前提是落在[0, k]内
有特殊的空间限制，发现i的状态只和i-1有关，用滚动数组优化

时间：O(nk)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll>dp(k + 1);
    for (int i = 0; i < n; i++)
    {
        ll a, b, q, w;
        cin >> a >> b >> q >> w;
        vector<ll>ndp(k + 1, -1);
        for (int j = 0; j <= k; j++)
        {
            if (dp[j] != -1)
            {
                ll x = dp[j] + (j > b ? 0 : a * j);
                int l = j - w;
                if (l >= 0)
                {
                    ndp[l] = max(ndp[l], x);
                }
                int r = j + q;
                if (r <= k)
                {
                    ndp[r] = max(ndp[r], x);
                }
                ndp[j] = max(ndp[j], x);
            }
        }
        dp = ndp;
    }
    ll ans = 0;
    for (int i = 0; i <= k; i++)
    {
        ans = max(ans, dp[i]);
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