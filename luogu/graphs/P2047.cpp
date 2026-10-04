/*
标签：Floyd

思路：要计算一个节点k的重要程度，需要知道任意两个点之间最短路路径数量和其中经过k的数量
经过k就是dis[i][k]+dis[k][j]=dis[i][j]，这样就是经过k的最短路数量
现在要求任意(i,j)之间的最短路数量，由于n<=100，考虑Floyd

在Floyd的过程中，可以维护出最短路的数量cnt
如果发现一条最短路，cnt[i][j]=cnt[i][k]*cnt[k][j]
如果有距离相同的最短路，cnt[i][j]=cnt[i][j]+cnt[i][k]*cnt[k][j]
这样就可以算每个点的重要程度了，即ans[k]=ans[k]+(cnt[i][k]*cnt[k][j])/cnt[i][j]

时间：O(n^3)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<ll> >g(n + 1, vector<ll>(n + 1, 1e18));
    vector<vector<ll> >cnt(n + 1, vector<ll>(n + 1));
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = c;
        cnt[a][b] = cnt[b][a] = 1;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (g[i][j] > g[i][k] + g[k][j])
                {
                    g[i][j] = g[i][k] + g[k][j];
                    cnt[i][j] = cnt[i][k] * cnt[k][j];           
                }
                else if (g[i][j] == g[i][k] + g[k][j])
                {
                    cnt[i][j] += cnt[i][k] * cnt[k][j];
                }
            }
        }
    }
    vector<double>ans(n + 1);
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                // 必须是三个不同的点
                if (k == i || i == j || j == k) continue;
                if (g[i][j] == g[i][k] + g[k][j])
                {
                    ans[k] += (1.0 * cnt[i][k] * cnt[k][j]) / cnt[i][j];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(3);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}