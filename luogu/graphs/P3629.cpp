/*
标签：树的直径

思路：一次巡逻会经过所有边2次，也就是(n-1)*2
假设先加入一条边，一定会形成一个环，可以少走环长减1
要使路过的边最少，选树的直径l1连成环是最优的
所以k=1的答案就是(n-1)*2-l1+1

k=2时，会再次生成一个环，就是找次长的路径
由于两个环可能会重叠，考虑把l1路径上的边权全部取反
此时再找直径，就是新的可以只路过1次的边长度l2，有负边的情况要树形dp找直径
答案是(n-1)*2-l1+1-l2+1

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
vector<vector<pair<int, int> > >g(N);
int mx, idx, f[N], dis[N], vis[N];
int l1, l2;
void dfs(int u, int fa, int d, int cnt)
{
    if (d > mx)
    {
        mx = d;
        idx = u;
    }
    // 记录父节点，方便回溯路径
    if (cnt == 1) f[u] = fa;
    for (auto [v, w] : g[u])
    {
        if (v == fa) continue;
        dfs(v, u, d + w, cnt);
    }
}
void dp(int u, int fa)
{
    for (auto [v, w] : g[u])
    {
        if (v == fa) continue;
        if (vis[u] && vis[v]) w = -1;
        dp(v, u);
        l2 = max(l2, dis[u] + dis[v] + w);
        dis[u] = max(dis[u], dis[v] + w);
    }
}
void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0, u, v; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].push_back({v, 1});
        g[v].push_back({u, 1});
    }
    dfs(1, 0, 0, 0);
    mx = 0;
    dfs(idx, 0, 0, 1);
    l1 = mx;
    if (k == 1)
    {
        cout << (n - 1) * 2 - l1 + 1;
        return;
    }
    for (int i = idx; i != 0; i = f[i])
    {
        vis[i] = 1;
    }
    dp(1, 0);
    cout << (n - 1) * 2 - l1 - l2 + 2;
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