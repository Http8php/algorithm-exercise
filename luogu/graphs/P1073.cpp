/*
标签：分层图、最长路

思路：从1到n，每个点都可以买入或卖出
考虑分层图，买入即增加一条从i->i，权值是-w的边，卖出则相反
由于只能交易一次，上述边均为有向边
最后答案即为1到n*3的最长路，用spfa实现

时间：O(km) k为每个点入队次数
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e5 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
struct node
{
    int v;
    ll w;
};
int n, m;
ll dis[N];
bool in[N];
vector<vector<node> >g(N);
void spfa(int s)
{
    queue<int>q;
    for (int i = 1; i <= n * 3; i++)
    {
        dis[i] = -inf;
        in[i] = false;
    }
    q.push(s);
    in[s] = true;
    dis[s] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        in[u] = false;
        for (auto [v, w] : g[u])
        {
            if (dis[v] < dis[u] + w)
            {
                dis[v] = dis[u] + w;
                if (!in[v])
                {
                    q.push(v);
                    in[v] = true;
                }
            }
        }
    }
}
int get(int x, int cnt)
{
    return (x + n * cnt);
}
void solve()
{
    cin >> n >> m;
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        g[i].push_back({get(i, 1), -x});
        g[get(i, 1)].push_back({get(i, 2), x});
    }
    for (int i = 0, u, v, op; i < m; i++)
    {
        cin >> u >> v >> op;
        g[u].push_back({v, 0});
        g[get(u, 1)].push_back({get(v, 1), 0});
        g[get(u, 2)].push_back({get(v, 2), 0});
        if (op == 2)
        {
            g[v].push_back({u, 0});
            g[get(v, 1)].push_back({get(u, 1), 0});
            g[get(v, 2)].push_back({get(u, 2), 0});
        }
    }
    spfa(1);
    cout << dis[get(n, 2)];
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