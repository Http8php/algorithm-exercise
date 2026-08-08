/*
标签：博弈、bfs

思路：先考虑Alice必胜的点
特殊点相连的点一定可以胜利，其次就是与连接了两个以上特殊点相连的点
只需要bfs，从特殊点拓展给相邻点+1，如果一个点>1，入队

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int> >g(n + 1);
    for (int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int>cnt(n + 1), e(n + 1), in(n + 1);
    queue<int>q;
    for (int i = 0, x; i < k; i++)
    {
        cin >> x;
        e[x] = 1;
        in[x] = 1;
        q.push(x);
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : g[u])
        {
            cnt[v]++;
            // 每个点保证最多入队一次
            if (!in[v] && cnt[v] >= 2)
            {
                in[v] = 1;
                q.push(v);
            }
        }
    }
    vector<int>ans;
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] && !e[i]) ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for (int x : ans)
    {
        cout << x << " ";
    }
    cout << '\n';
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