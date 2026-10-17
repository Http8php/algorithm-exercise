/*
标签：换根dp

思路：由于只要包含一个k类型的点就算k-路径，所以找到每一个点的最长路径，记录同类型之中的最长路
维护每个点出发的最长路径fi和次长路径se，i点的最长路就是w[i]+fi+se
这个用换根dp两次dfs维护
第一次dfs，计算从u出发经过v向下的最长链，自底向上
第二次dfs，计算从v出发经过u向上的最长链，自顶向下

单组时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 10;
int c[N];
ll w[N], fi[N], se[N];
vector<vector<int> >g(N);
void trans(int x, ll v)
{
    if (v > fi[x])
    {
        se[x] = fi[x];
        fi[x] = v;
    }
    else if (v > se[x])
    {
        se[x] = v;
    }
}
// 计算从u出发经过v向下的最长链
void dfs1(int u, int fa)
{
    for (int v : g[u])
    {
        if (v == fa) continue;
        dfs1(v, u);
        trans(u, fi[v] + w[v]);
    }
}
// 计算从v出发经过u向上的最长链
void dfs2(int u, int fa)
{
    for (int v : g[u])
    {
        if (v == fa) continue;
        // nw是从u出发不经过v的最长链加w[u]
        ll nw = (fi[u] == fi[v] + w[v] ? se[u] : fi[u]) + w[u];
        trans(v, nw);
        dfs2(v, u);
    }
}
void solve()
{ 
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
        fi[i] = se[i] = 0;
    }
    for (int i = 0, u, v; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    vector<ll>ans(n + 1, -1e18);
    for (int i = 1; i <= n; i++)
    {
        ans[c[i]] = max(ans[c[i]], w[i] + fi[i] + se[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << (ans[i] == -1e18 ? -1 : ans[i]) << " ";
    }
    cout << '\n';
    for (int i = 1; i <= n; i++)
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