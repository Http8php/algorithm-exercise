/*
标签：强连通分量

思路：发现一个强连通分量中的员工是相互信任的
考虑缩点，如果最终只有一个汇点，即出度为0，这个点的大小就是答案
如果无汇点或多个汇点，不满足条件，输出0

时间：O(n + m)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
vector<vector<int> >g(N);
int dfn[N], low[N], bel[N], out[N], sz[N];
bool ins[N], vis[N];
stack<int>st;
int n, m, cnt, idx;
void tarjan(int u)
{
    low[u] = dfn[u] = ++cnt;
    st.push(u);
    ins[u] = true;
    for (int v : g[u])
	{
        if (!dfn[v])
		{
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
		else if (ins[v])
		{
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u])
	{
        idx++;
        int x;
        do
		{
            x = st.top();
			st.pop();
            ins[x] = false;
            bel[x] = idx;
            sz[idx]++;
        } while (x != u);
    }
}
void solve()
{
    cin >> n >> m;
    for (int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i]) tarjan(i);
    }
    for (int u = 1; u <= n; u++)
    {
        for (int v : g[u])
        {
            int p = bel[u], q = bel[v];
            if (p != q)
            {
                out[p]++;
            }
        }
    }
    int cnt = 0, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int fa = bel[i];
        if (!vis[fa] && out[fa] == 0)
        {
            vis[fa] = true;
            cnt++;
            ans = sz[fa];
        }
    }
    cout << (cnt == 1 ? ans : 0);
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