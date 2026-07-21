/*
知识点：动态规划

思路：双生英雄的设定让选择变多——都选、只选一位，不选，考虑分组背包
把双生英雄打包成三个选项，就是01背包了

时间：O(4 * nc)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node
{
    int cost, cnt;
    ll val;
};
void solve()
{
    int n, c, m;
    cin >> n >> c >> m;
    vector<int>a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }
    vector<int>id(n + 1);
    vector<pair<int, int> >co(m + 1);
    vector<ll>ex(m + 1);
    for (int i = 1, u, v; i <= m; i++)
    {
        ll w;
        cin >> u >> v >> w;
        id[u] = i;
        id[v] = i;
        co[i] = {u, v};
        ex[i] = w;
    }
    vector<vector<node> >g;
    vector<int>vis(m + 1);
    for (int i = 1; i <= n; i++)
    {
        int idx = id[i];
        if (idx == 0) g.push_back({{a[i], 1, b[i]}});
        else
        {
            if (vis[idx]) continue;
            vis[idx] = 1;
            auto [u, v] = co[idx];
            // 打包
            g.push_back({{a[u], 1, b[u]}, {a[v], 1, b[v]}, {a[u] + a[v], 2, b[u] + b[v] + ex[idx]}});
        }
    }
    vector<vector<ll> >dp(c + 1, vector<ll>(5, -1));
    dp[0][0] = 0;
    for (auto x : g)
    {
        // 滚动数组优化
        auto ndp = dp;
        for (auto [cost, cnt, val] : x)
        {
            for (int i = c; i >= cost; i--)
            {
                for (int j = 4; j >= cnt; j--)
                {
                    if (ndp[i-cost][j-cnt] != -1)
                    {
                        dp[i][j] = max(dp[i][j], ndp[i-cost][j-cnt] + val);
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= c; i++)
    {
        for (int j = 0; j <= 4; j++)
        {
            ans = max(ans, dp[i][j]);
        }
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