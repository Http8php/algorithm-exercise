/*
标签：基环树

思路：基环树上从1到n最多只有两种走法，即两点不在环的同一颗子树上，顺/逆时针走
于是可以暴力搜索，每走到一次n，就把没经过的边都设成这个答案，相当于删边

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
int n, vis[N], ans[N];
vector<vector<pair<int, int> > >g(N);
void dfs(int u, int dep)
{
    if (u == n)
    {
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                ans[i] = min(ans[i], dep);
            }
        }
        return;
    }
    for (auto [v, id] : g[u])
    {
        if (!vis[id])
        {
            vis[id] = 1;
            dfs(v, dep + 1);
            vis[id] = 0;
        }
    }
}
void solve()
{
    cin >> n;
    for (int i = 0, u, v; i < n; i++)
    {
        cin >> u >> v;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
        ans[i] = 1e9;
    }
    dfs(1, 0);
    for (int i = 0; i < n; i++)
    {
        cout << (ans[i] == 1e9 ? -1 : ans[i]) << " ";
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