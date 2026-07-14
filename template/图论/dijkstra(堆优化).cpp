#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
int main()
{
    int n, m, s;
    cin >> n >> m >> s;
    vector<ll>dis(n + 1, inf);
    vector<int>vis(n + 1);
    vector<vector<node> >g(n + 1);
    for (int i = 0, u, v, w; i < m; i++)
    {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
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
            if (dis[v] > d + w)
            {
                dis[v] = d + w;
                q.push({v, dis[v]});
            }
        }
    }
    return 0;
}