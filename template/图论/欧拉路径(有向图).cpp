/*
有向连通图
欧拉回路：i=1~n in[i] = out[i]
欧拉路径：起点s in[s] + 1 = out[s] 一个
终点e in[e] = out[e] + 1 一个
其余点i in[i] = out[i]
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
stack<int>ans;
vector<vector<int> >g(N);
int cnt[N];
void dfs(int x)
{
    for (int i = cnt[x]; i < g[x].size(); i = cnt[x])
    {
        cnt[x]++;
        dfs(g[x][i]);
    }
    ans.push(x);
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int>in(n + 1), out(n + 1);
    for (int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        in[v]++, out[u]++;
    }
    int s = -1, e = -1;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == out[i]) continue;
        else if (in[i] + 1 == out[i])
        {
            if (s != -1)
            {
                cout << "No";
                return;
            }
            s = i;
        }
        else if (in[i] == out[i] + 1)
        {
            if (e != -1)
            {
                cout << "No";
                return;
            }
            e = i;
        }
        else
        {
            cout << "No";
            return;
        }
    }
    if (s * e < 0)
    {
        cout << "No";
        return;
    }
    if (s == -1 && e == -1) s = 1;
    dfs(s);
}