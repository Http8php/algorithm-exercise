/*
知识点：并查集

思路：每个被标记的连通块只需到一个非标记点，每个连通块只要额外连一条边，这就是最小代价
k<n，一定有连的办法，注意方案数是每个连通块可以连出去的边，而不是每个标记点

时间：O(nlogk)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
int n, f[N];
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
void solve()
{
    int k;
    cin >> n >> k;
    init();
    set<int>a;
    for (int i = 1, x; i <= k; i++)
    {
        cin >> x;
        a.insert(x);
    }
    vector<vector<int> >g(n + 1);
    for (int i = 0, u, v; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int u : a)
    {
        ll cnt = 0;
        for (int v : g[u])
        {
            if (a.count(v)) join(u, v);
        }
    }
    int ans1 = 0;
    ll ans2 = 1;
    vector<int>vis(n + 1), deg(n + 1);
    for (int u : a)
    {
        int fa = find(u);
        for (int v : g[u])
        {
            // 每个连通块可以连的边
            if (!a.count(v)) deg[fa]++;
        }
    }
    for (int u : a)
    {
        int fa = find(u);
        if (!vis[fa])
        {
            vis[fa] = 1;
            // 连通块数量
            ans1++;
            // 乘法原理
            ans2 = ans2 * deg[fa] % mod;
        }
    }
    cout << ans1 << " " << ans2;
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