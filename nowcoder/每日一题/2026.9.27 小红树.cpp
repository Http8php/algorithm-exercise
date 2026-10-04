/*
标签：dfs

思路：边的权值和两边连通块数量有关，考虑求出每个点的子树所拥有的连通块数量
用dfs解决，把1当作根，每个点初始1，再加上子节点连通块数量之和，如果与子节点同色，还要减1
接下来考虑计算，再跑一遍dfs
cnt[1]代表所有连通块数量，假设当前到一个点v，边的另一边u数量就是x=cnt[1]-cnt[v]
如果uv同色，会多切出一个连通块，x加1
答案即为所有边的abs(x-cnt[v])

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
int cnt[N];
string s;
vector<vector<int> >g(N);
ll ans;
void dfs(int u, int fa)
{
    cnt[u] = 1;
    for (int v : g[u])
    {
        if (v == fa) continue;
        dfs(v, u);
        cnt[u] += cnt[v];
        if (s[u] == s[v]) cnt[u]--;
    }
}
void calc(int u, int fa)
{
    for (int v : g[u])
    {
        if (v == fa) continue;
        calc(v, u);
        int x = cnt[1] - cnt[v];
        if (s[v] == s[u]) x++;
        ans += abs(x - cnt[v]);
    }
}
void solve()
{
    int n;
    cin >> n >> s;
    s = " " + s;
    for (int i = 0, u, v; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    calc(1, 0);
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