/*
标签：拓扑序

思路：发现只要根据值小->大将无向边改成有向边，整个图会变成DAG
此时形成的排列就是拓扑序

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int>in(n + 1);
    vector<vector<int> >g(n + 1);
    for (int i = 0, u, v, a, b; i < n - 1; i++)
    {
        cin >> u >> v >> a >> b;
        if (a < b)
        {
            g[u].push_back(v);
            in[v]++;
        }
        else
        {
            g[v].push_back(u);
            in[u]++;
        }
    }
    queue<int>q;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0) q.push(i);
    }
    vector<int>ans(n + 1);
    int cur = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        ans[u] = cur++;
        for (int v : g[u])
        {
            in[v]--;
            if (in[v] == 0) q.push(v);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
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