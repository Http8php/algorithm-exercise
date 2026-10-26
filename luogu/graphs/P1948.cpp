/*
标签：二分答案，最短路

思路：二分最终价格x，把>x的边看作1，<=x的边看作0
用spfa跑最短路，如果到n的距离<=k，说明这个答案可行
1可以理解为使用一次免费机会

时间：O(kp) k为每个点入队次数
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
struct node
{
    int v;
    ll w;
};
int n, p, k;
ll dis[N];
bool in[N];
vector<vector<node> >g(N);
void spfa(int s, int x)
{
    queue<int>q;
    for (int i = 1; i <= n; i++)
    {
        dis[i] = inf;
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
            if (w > x) w = 1;
            else w = 0;
            if (dis[v] > dis[u] + w)
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
void solve()
{
    cin >> n >> p >> k;
    for (int i = 0, u, v, w; i < p; i++)
    {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    int l = 0, r = 1e6, ans = 1e6;
    spfa(1, r);
    if (dis[n] > k)
    {
        cout << -1;
        return;
    }
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        spfa(1, mid);
        if (dis[n] <= k)
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