/*
标签：最短路，分层图，方案输出

思路：由于有不限速道路，不能直接使用最短路算法
设dis[i][j]为以j的速度到i点的最小时间
松弛时，如果当前路没有限速，就用上一个点的速度
每次松弛成功，记录上一个点和速度用于回溯方案
找到最小的dis[d][j]，输出方案

时间：O(mlogm)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node
{
    int nxt, v, l;
};
struct node2
{
    int u, v;
    double w;
    friend bool operator<(node2 a, node2 b)
    {
        return a.w > b.w;
    }
};
int n, m, d;
vector<vector<node> >g(155);
double dis[155][550];
int vis[155][550];
pair<int, int> back[155][550];
void dij(int s)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= 500; j++)
        {
            dis[i][j] = 1e18;
            vis[i][j] = 0;
            back[i][j] = {-1, -1};
        }
    }
    priority_queue<node2>q;
    dis[s][70] = 0;
    q.push({s, 70, 0});
    while (!q.empty())
    {
        auto [u, nv, tim] = q.top();
        q.pop();
        if (vis[u][nv]) continue;
        vis[u][nv] = 1;
        for (auto [nxt, v, l] : g[u])
        {
            if (v)
            {
                if (dis[nxt][v] > dis[u][nv] + 1.0 * l / v)
                {
                    dis[nxt][v] = dis[u][nv] + 1.0 * l / v;
                    q.push({nxt, v, dis[nxt][v]});
                    back[nxt][v] = {u, nv};
                }
            }
            else
            {
                if (dis[nxt][nv] > dis[u][nv] + 1.0 * l / nv)
                {
                    dis[nxt][nv] = dis[u][nv] + 1.0 * l / nv;
                    q.push({nxt, nv, dis[nxt][nv]});
                    back[nxt][nv] = {u, nv};
                }
            }
        }
    }
}
void solve()
{
    cin >> n >> m >> d;
    for (int i = 0, a, b, v, l; i < m; i++)
    {
        cin >> a >> b >> v >> l;
        g[a].push_back({b, v, l});
    }
    dij(0);
    double mn = 1e18; 
    for (int i = 1; i <= 500; i++)
    {
        if (dis[d][i] < mn) mn = dis[d][i];
    }
    vector<int>ans;
    for (int i = 1; i <= 500; i++)
    {
        if (dis[d][i] == mn)
        {
            int cu = d, cv = i;
            while (back[cu][cv].first != -1)
            {
                ans.push_back(cu);
                auto [u, v] = back[cu][cv];
                cu = u, cv = v;
            }
            break;
        }
    }
    ans.push_back(0);
    reverse(ans.begin(), ans.end());
    for (int v : ans)
    {
        cout << v << " ";
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