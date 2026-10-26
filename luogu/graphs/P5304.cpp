/*
标签：最短路

思路：求两个集合间AB之间点的最短路，可以人为增加一个超级源点s->A
增加超级汇点B->t，这样从s开始跑最短路，dis[t]即为所需答案

回到题目，只要想办法把最短的两个点分到不同集合就可以了
发现目标的两个点肯定至少有一个二进制位不同
枚举所有二进制位，0放入A，1放入B，分别跑最短路记录最小值

单组时间：O(34 * mlogm)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
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
int n, m, k;
vector<vector<node> >g(N);
ll dis[N];
int vis[N];
void dij(int s)
{
    for (int i = 0; i <= n + 1; i++)
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
    cin >> n >> m >> k;
    for (int i = 0, u, v; i < m; i++)
    {
        ll w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    vector<int>a(k + 1);
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i];
    }
    int s = 0, t = n + 1;
    ll ans = inf;
    for (int i = 0; i <= 17; i++)
    {
        // 记录哪些点加边了，方便去除
        // 这样的好处是不用每次拷贝整个旧图
        vector<int>mem;
        for (int j = 1; j <= k; j++)
        {
            if ((a[j] >> i) & 1) g[s].push_back({a[j], 0});
            else
            {
                g[a[j]].push_back({t, 0});
                mem.push_back(a[j]);
            }
        }
        dij(s);
        ans = min(ans, dis[t]);
        g[s].clear();
        for (int v : mem)
        {
            g[v].pop_back();
        }
        mem.clear();
        // 由于是单向边，s->B->A->t也要考虑
        for (int j = 1; j <= k; j++)
        {
            if (((a[j] >> i) & 1) == 0) g[s].push_back({a[j], 0});
            else
            {
                g[a[j]].push_back({t, 0});
                mem.push_back(a[j]);
            }
        }
        dij(s);
        ans = min(ans, dis[t]);
        g[s].clear();
        for (int v : mem)
        {
            g[v].pop_back();
        }
    }
    cout << ans << '\n';
    for (int i = 0; i <= n + 1; i++)
    {
        g[i].clear();
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}