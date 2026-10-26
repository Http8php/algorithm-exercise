/*
标签：bfs，二分答案，最短路

思路：首先处理出每个点的时差，从a,b点分别bfs得到
要最小化路径上的最大权值，考虑二分答案x
如果下一个点的权值>x，这条路视为关闭
当所有>x的点都不能走的情况下s仍可以到达t，这个答案是可行的，可以进一步收拢右端点

时间：O(logn * mlogm)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
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
vector<vector<int> >g(N);
ll dis[N], val[N];
int n, vis[N];
void dij(int s, int x)
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
        for (int v : g[u])
        {
            if (val[v] > x) continue;
            if (dis[v] > dis[u] + val[v])
            {
                dis[v] = dis[u] + val[v];
                q.push({v, dis[v]});
            }
        }
    }
}
void solve()
{
    int m, a, b, s, t;
    cin >> n >> m >> a >> b >> s >> t;
    for (int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int>ta(n + 1), tb(n + 1), vis1(n + 1);
    queue<int>q;
    q.push(a);
    vis1[a] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : g[u])
        {
            if (vis1[v]) continue;
            vis1[v] = 1;
            ta[v] = ta[u] + 1;
            q.push(v);
        }
    }
    vector<int>vis2(n + 1);
    q.push(b);
    vis2[b] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : g[u])
        {
            if (vis2[v]) continue;
            vis2[v] = 1;
            tb[v] = tb[u] + 1;
            q.push(v);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        val[i] = abs(ta[i] - tb[i]);
    }
    int l = max(val[s], val[t]), r = n, ans = inf;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        dij(s, mid);
        if (dis[t] != inf)
        {
            ans = min(ans, mid);
            r = mid - 1;
        }
        else l = mid + 1;
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