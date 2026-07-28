#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int>in(n + 1);
    vector<vector<int> >g(n + 1);
    for (int i = 0, u, v; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        in[v]++;
    }
    queue<int>q;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0) q.push(i);
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : g[u])
        {
            in[v]--;
            if (in[v] == 0) q.push(v);
        }
    }
}