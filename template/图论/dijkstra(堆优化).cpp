#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e4 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
struct node
{
    int v;
    ll w;
    friend bool operator<(node a, node b)
    {
        return a.w > b.w;
    }
};
int n, m;
vector<vector<node> >g(N);
ll dis[N];
int vis[N];
void dij(int s)
{
    for (int i = 1; i <= n; i++)
    {
        dis[i] = inf;
        vis[i] = 0;
    }
    priority_queue<node>q;
    dis[s] = 0;
    q.push({s, 0});
    while (!q.empty())
    {
        auto [u, d] = q.top();
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, w] : g[u])
        {
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                q.push({v, dis[v]});
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    for (int i = 0, u, v, w; i < m; i++)
    {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
}