/*
知识点：dijkstra

思路：由于路线是1->2->...->k，把点编号，对每个起点跑dij，收集终点最小值即可

时间：O(n^6logn) 最坏情况
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
int n, k;
vector<vector<node> >g(N);
ll dis[N];
int vis[N];
void dij(int s)
{
    for (int i = 1; i <= n * n; i++)
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
    cin >> n >> k;
    vector<vector<tuple<int, int, int> > >pos(n * n + 1);
    for (int i = 1, x; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> x;
            pos[x].push_back({i, j, 0});
        }
    }
    int cur = 1;
    vector<int>sid, eid;
    for (int i = 1; i <= k; i++)
    {
        if (pos[i].size() == 0)
        {
            cout << -1;
            return;
        }
        for (auto &[x, y, id] : pos[i])
        {
            if (i == 1) sid.push_back(cur);
            if (i == k) eid.push_back(cur);
            id = cur++;
        }
    }
    for (int i = 1; i < n * n; i++)
    {
        for (auto [ax, ay, ida] : pos[i])
        {
            for (auto [bx, by, idb] : pos[i+1])
            {
                g[ida].push_back({idb, abs(ax - bx) + abs(ay - by)});
            }
        }
    }
    ll ans = inf;
    for (int x : sid)
    {
        dij(x);
        for (int y : eid)
        {
            ans = min(ans, dis[y]);
        }
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