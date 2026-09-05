#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int n;
vector<int>g[N];
int a[N], dp[N][2];
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