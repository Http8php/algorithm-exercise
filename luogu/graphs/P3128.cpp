/*
标签：lca、树上差分

思路：树上差分模板题

时间：O(20 * n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e4 + 10;
vector<vector<int> >g(N);
int dep[N], f[N][20], d[N];
void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    f[u][0] = fa;
    for (int i = 1; i <= 19; i++)
    {
        f[u][i] = f[f[u][i-1]][i-1];
    }
    for (int v : g[u])
    {
        if (v == fa) continue;
        dfs(v, u);
    }
}
int lca(int a, int b)
{
    if (dep[a] < dep[b]) swap(a, b);
    for (int i = 19; i >= 0; i--)
    {
        if (dep[f[a][i]] >= dep[b])
        {
            a = f[a][i];
        }
    }
    if (a == b) return a;
    for (int i = 19; i >= 0; i--)
    {
        if (f[a][i] != f[b][i])
        {
            a = f[a][i];
            b = f[b][i];
        }
    }
    return f[a][0];
}
void dfs2(int u, int fa)
{
    for (int v : g[u])
    {
        if (v == fa) continue;
        dfs2(v, u);
    }
    d[fa] += d[u];
}
void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0, u, v; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    while (k--)
    {
        int s, t;
        cin >> s >> t;
        d[s]++;
        d[t]++;
        int fa = lca(s, t);
        d[fa]--;
        d[f[fa][0]]--;
    }
    dfs2(1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, d[i]);
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