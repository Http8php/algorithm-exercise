#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e4 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
struct node
{
    int v;
    ll w;
};
int n, m;
vector<vector<node> >g(N);
ll dis[N];
int vis[N];
void dij(int s)
{
    for (int i = 0; i <= n; i++)
    {
        dis[i] = inf;
        vis[i] = 0;
    }
    dis[s] = 0;
    while (1)
    {
        int u = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i] && dis[u] > dis[i]) u = i;
        }
        if (u == 0) break;
        vis[u] = 1;
        for (auto [v, w] : g[u])
        {
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    for (int i = 0, u, v; i < m; i++)
    {
        ll w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
}