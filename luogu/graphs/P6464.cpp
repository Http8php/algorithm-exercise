/*
标签：最短路

思路：首先n<=100，考虑用Floyd跑最短路
现在有一个传送门，可以把一条边的边权变成0
暴力做法是修改所有(i,j)边再次跑最短路，但是这样是n^5的
发现只修改一条边，中间点不必要遍历所有的点，经过(i,j)边即可
这样就优化掉一个n了

时间：O(n^4)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 0x3f3f3f3f;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int> >g(n + 1, vector<int>(n + 1, inf));
    for (int i = 0, u, v, w; i < m; i++)
    {
        cin >> u >> v >> w;
        g[u][v] = min(g[u][v], w);
        g[v][u] = min(g[v][u], w);
        g[u][u] = 0;
        g[v][v] = 0;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    int ans = inf;
    for (int u = 1; u <= n; u++)
    {
        for (int v = 1; v <= n; v++)
        {
            auto ng = g;
            ng[u][v] = ng[v][u] = 0;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    ng[i][j] = min(ng[i][j], ng[i][u] + ng[v][j]);
                    ng[i][j] = min(ng[i][j], ng[i][v] + ng[u][j]);
                }
            }
            int res = 0;
            for (int i = 1; i < n; i++)
            {
                for (int j = i; j <= n; j++)
                {
                    res += ng[i][j];
                }
            }
            ans = min(ans, res);
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