/*
标签：树的直径

思路：如果只有一个核心城市，放在直径中点可以覆盖更多城市
将直径中点mid作为根，根下会出现很多分支，下一个核心城市与根相连
贪心地想，把最深的分支顶部变成核心城市，一定是最优的
于是以mid为根dfs时，维护节点的深度dep和最大到达的深度mxd，令根深度为1
把mxd-dep作为关键字降序排序，前k个成为核心城市是最优的
答案就是mxd[k+1]-dep[k+1]+1

时间：O(nlogn)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
int n, k, idx, mx, f[N];
vector<vector<int> >g(N);
void dfs(int u, int fa, ll d)
{
    if (d > mx)
    {
        mx = d;
        idx = u;
    }
    for (int v : g[u])
    {
        if (v == fa) continue;
        f[v] = u;
        dfs(v, u, d + 1);
    }
}
int dep[N], mxd[N];
void dfs2(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    mxd[u] = dep[u];
    for (int v : g[u])
    {
        if (v == fa) continue;
        dfs2(v, u);
        mxd[u] = max(mxd[u], mxd[v]);
    }
}
void solve()
{
    cin >> n >> k;
    for (int i = 0, u, v; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    mx = -1;
    dfs(1, 0, 0);
    mx = -1;
    int h = idx;
    dfs(idx, 0, 0);
    // 找直径中点
    vector<int>p;
    while (idx != h)
    {
        p.push_back(idx);
        idx = f[idx];
    }
    p.push_back(h);
    int mid = p[mx/2];
    dfs2(mid, 0);
    vector<int>ans;
    for (int i = 1; i <= n; i++)
    {
        ans.push_back(mxd[i] - dep[i]);
    }
    sort(ans.rbegin(), ans.rend());
    cout << ans[k] + 1;
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