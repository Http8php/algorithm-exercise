/*
标签：树形dp，dfs

思路：每个公会都有一个公共顶点，考虑计算每个顶点作为根贡献的答案
如果只是把深度当作答案，会有重复的情况
对于一个有若干不同深度子节点的顶点，可以发现只有最大深度的节点会重复，第二深每往上每一层都对答案贡献1
于是在dfs中除了维护每个节点的深度dep和答案ans，额外维护每个节点能到达的最深深度dp和第二深的深度m2
dp[i]代表节点i能到达的最深深度，m2代表第二深子节点
ans[i] = m2 - dep[i] + 1 + Σans[v]，v代表i的所有子节点

单组时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
int dep[N], dp[N];
ll ans[N];
vector<vector<int> >g(N);
void dfs(int u, int fa)
{
    ans[u] = 0;
    dp[u] = dep[u];
    int m1 = dep[u], m2 = dep[u];
    for (int v : g[u])
    {
        if (v == fa) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
        dp[u] = max(dp[u], dp[v]);
        ans[u] += ans[v];
        // 打擂法维护m1、m2
        if (dp[v] >= m1)
        {
            m2 = m1;
            m1 = dp[v];
        }
        else if (dp[v] >= m2) m2 = dp[v];
    }
    ans[u] += m2 - dep[u] + 1;
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 2, u; i <= n; i++)
    {
        cin >> u;
        g[u].push_back(i);
    }
    dfs(1, 0);
    cout << ans[1] << '\n';
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