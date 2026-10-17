/*
标签：并查集，树的直径

思路：初始给出一片森林，操作1要求数内最远的距离，就是求树的直径
读入m条边后，用并查集标记树，两遍dfs求出每棵树的直径
操作2是把两棵树合并，且直径最短，候选值先有d1，d2，可能还是原树直径长
要直径尽可能短，就是取两树直径中点连接
这样新的候选值是ceil(d1/2)+ceil(d2/2)+1，取三者的最大值

时间：O(n + m + q)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e5 + 10;
int n, m, q, f[N];
void init()
{
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
    }
}
int find(int x)
{
    if (x == f[x]) return x;
    return f[x] = find(f[x]);
}
void join(int c1, int c2)
{
    int f1 = find(c1), f2 = find(c2);
    if (f1 != f2) f[f1] = f2;
}
int idx, mx, dis[N];
vector<vector<pair<int, ll> > >g(N);
void dfs(int u, int fa, ll d)
{
    if (d > mx)
    {
        mx = d;
        idx = u;
    }
    for (auto [v, w] : g[u])
    {
        if (v == fa) continue;
        dfs(v, u, d + w);
    }
}
void solve()
{
    cin >> n >> m >> q;
    init();
    for (int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v;
        g[u].push_back({v, 1});
        g[v].push_back({u, 1});
        join(u, v);
    }
    vector<int>vis(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int fa = find(i);
        if (!vis[fa])
        {
            vis[fa] = 1;
            mx = -1;
            dfs(fa, 0, 0);
            mx = -1;
            dfs(idx, 0, 0);
            dis[fa] = mx;
        }
    }
    while (q--)
    {
        int op, x, y;
        cin >> op;
        if (op == 1)
        {
            cin >> x;
            int fa = find(x);
            cout << dis[fa] << '\n';
        }
        else
        {
            cin >> x >> y;
            int fx = find(x), fy = find(y);
            if (fx == fy) continue;
            int d = max({(dis[fx] + 1) / 2 + (dis[fy] + 1) / 2 + 1, dis[fx], dis[fy]});
            join(fx, fy);
            dis[fy] = d;
        }
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