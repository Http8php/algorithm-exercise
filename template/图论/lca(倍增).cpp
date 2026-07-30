#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
vector<vector<int> >g(N);
int dep[N], f[N][20];
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
void solve()
{
    int n;
    cin >> n;
    for (int i = 0, u, v; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
}