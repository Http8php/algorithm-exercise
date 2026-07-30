/*
知识点：二分答案，dijkstra

小trick：最大的最小值类似的表述大概率是二分信号

思路：观察到答案具有单调性，存在一个点，减小走不通，增大更能走通
于是二分答案，每次跑dij，看是否能到达终点，若能，则更贵的一定也能，减小，若不能，增大

时间：O(log(r - l) * mlogm) l, r为二分值域
*/

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
int n, m, b;
vector<vector<node> >g(N);
ll dis[N];
int vis[N], f[N];
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
        for (auto [v, w] : g[u])
        {
            if (f[v] > x) continue;
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
    cin >> n >> m >> b;
    int r = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i];
        r = max(r, f[i]);
    }
    for (int i = 0, u, v, w; i < m; i++)
    {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    int l = max(f[1], f[n]), ans = -1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        dij(1, mid);
        if (dis[n] <= b)
        {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    if (ans == -1)
    {
        cout << "AFK";
        return;
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