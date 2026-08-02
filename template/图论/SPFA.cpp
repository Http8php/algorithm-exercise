#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
struct node
{
    int v;
    ll w;
};
int n, m, cnt[N];
ll dis[N];
bool in[N];
vector<vector<node> >g(N);
void spfa(int s)
{
    queue<int>q;
    for (int i = 1; i <= n; i++)
    {
        dis[i] = inf;
        //cnt[i] = 0;
        in[i] = false;
    }
    q.push(s);
    in[s] = true;
    dis[s] = 0;
    //cnt[s] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        in[u] = false;
        for (auto [v, w] : g[u])
        {
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                //cnt[v]++;
                //if (cnt[v] >= n) return true;
                if (!in[v])
                {
                    q.push(v);
                    in[v] = true;
                }
            }
        }
    }
    //return false;
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