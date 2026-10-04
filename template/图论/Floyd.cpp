#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int> >g(n + 1, vector<int>(n + 1, inf));
    for (int i = 1; i <= n; i++)
    {
        g[i][i] = 0;
    }
    for (int i = 0, u, v, w; i < m; i++)
    {
        cin >> u >> v >> w;
        g[u][v] = min(g[u][v], w);
        g[v][u] = min(g[v][u], w);
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}