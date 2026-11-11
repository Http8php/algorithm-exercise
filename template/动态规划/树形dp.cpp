#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
ll a[N], dp[N][2];
vector<vector<int> >g(N);
void dfs(int u, int fa)
{
    dp[u][0] = 0;
    dp[u][1] = a[u];
    for (int v : g[u])
    {
        if (v == fa) continue;
        dfs(v, u);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}