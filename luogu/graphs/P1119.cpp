/*
标签：Floyd

思路：注意到题目中的特殊性质，每个点的开放时间和询问时的时间都是升序的
也就是说，可以维护当前点，如果当前点开放时间小于询问时间，就加入地图
加入的过程，实际上就是Floyd中加入中间点，只不过把k的那个循环拆开了
Floyd是把1~n的每个前缀集合依次当成中间点，与这题相同
每次询问先加入新开放的点，跑Floyd
直到不能加入点时，图就是当前的最短路，如果两个点相互可达，输出即可

时间：O(n^3 + q)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 0x3f3f3f3f;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int>t(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }
    vector<vector<int> >g(n + 1, vector<int>(n + 1, inf));
    for (int i = 1; i <= n; i++)
    {
        g[i][i] = 0;
    }
    for (int i = 0, u, v, w; i < m; i++)
    {
        cin >> u >> v >> w;
        // 题目中编号从0开始，需要加1
        u++, v++;
        g[u][v] = min(g[u][v], w);
        g[v][u] = min(g[v][u], w);
    }
    int q, cur = 1;
    cin >> q;
    while (q--)
    {
        int x, y, tim;
        cin >> x >> y >> tim;
        x++, y++;
        while (cur <= n && t[cur] <= tim)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    g[i][j] = min(g[i][j], g[i][cur] + g[cur][j]);
                }
            }
            cur++;
        }
        if (t[x] > tim || t[y] > tim || g[x][y] == inf)
        {
            cout << -1 << '\n';
            continue;
        }
        cout << g[x][y] << '\n';
    }
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