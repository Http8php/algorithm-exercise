/*
知识点：二分图，bfs

思路：首先选1作为顶点，路径为 1->2<-3->4<-5，发现一定是奇数点指向偶数点
这种一类点指向另一类点是二分图的性质，题中要求的点就是左半或右半
对于每一个连通分量，先判断是否为二分图，若是，把多的顶点加入答案

时间：O(n + m)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int> >g(n + 1);
    for (int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // 染色法判断二分图
    vector<int>id(n + 1), vis(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        vector<int>cnt(2);
        bool ok = true;
        // 点 颜色
        queue<pair<int, int> >q;
        q.push({i, 1});
        while (!q.empty())
        {
            auto [u, x] = q.front();
            q.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            id[u] = x;
            cnt[x]++;
            for (int v : g[u])
            {
                // 相邻节点颜色必须不同
                if (vis[v] && id[v] == id[u])
                {
                    ok = false;
                    continue;
                }
                if (!vis[v])
                {
                    id[v] = id[u] ^ 1;
                    q.push({v, id[v]});
                }
            }
        }
        if (ok) ans += max(cnt[0], cnt[1]);
    }
    cout << ans << '\n';
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