/*
标签：模板题、二分图

时间：O(n + m)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e5 + 10;
int n, m;
vector<vector<int> >g(N);
int col[N];
bool dfs(int u)
{
    for (int v : g[u])
    {
        if (!col[v])
        {
            col[v] = 3 - col[u];
            if(!dfs(v)) return false;
        }
        else
        {
            if (col[v] == col[u]) return false;
        }
    }
    return true;
}
void solve()
{
    cin >> n >> m;
    for (int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bool ok = true;
    for (int i = 1; i <= n; i++)
    {
        if (!col[i])
        {
            col[i] = 1;
            ok = dfs(i);
        }
    }
    cout << (ok ? "YES" : "NO");
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