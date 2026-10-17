/*
标签：贪心，强连通分量，缩点，拓扑排序

思路：题目给了很多约束，第一反应是差分约束
x=1: u=v -> u>=v+0 v>=u+0 建立u-v双向边，边权0
x=2: u<v -> v>=u+1 u->v，边权1
x=3: u<=v -> v>=u+0 u->v，边权0
x=4: u>v -> u>=v+1 v->u，边权1
x=5: u>=v -> u>=v+0 v->u，边权0
然后spfa跑最长路，有正环就无解，最小值大于零即可
但是点数<=1e5，边数也是这个数量级，spfa可能会被卡到nk

最小值是0，对于一个约束，通过±1来最小地满足条件，也就是边权只有0和1
一个点满足之前的约束才能处理接下来的点，考虑拓扑排序
把同值的点缩成一个点，如果一个强连通分量中有边权1，说明有正环，无解
设dp[i]为编号i的强连通分量的最小糖果数
对于缩点后的新边，u-v，边权w，dp[v]=max(dp[v], dp[u]+w)

时间：O(n + k)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
struct node
{
    int v, w;
};
vector<vector<node> >g(N);
vector<vector<node> >ng(N);
int dfn[N], low[N], bel[N], dp[N];
bool ins[N];
stack<int>st;
int n, k, cnt, idx;
void tarjan(int u)
{
    low[u] = dfn[u] = ++cnt;
    st.push(u);
    ins[u] = true;
    for (auto [v, w] : g[u])
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
        } while (x != u);
    }
}
void solve()
{
    cin >> n >> k;
    for (int i = 0, x, u, v; i < k; i++)
    {
        cin >> x >> u >> v;
        if (x == 1)
        {
            g[u].push_back({v, 0});
            g[v].push_back({u, 0});
        }
        else if (x == 2)
        {
            g[u].push_back({v, 1});
        }
        else if (x == 3)
        {
            g[v].push_back({u, 0});
        }
        else if (x == 4)
        {
            g[v].push_back({u, 1});
        }
        else
        {
            g[u].push_back({v, 0});
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i]) tarjan(i);
    }
    vector<int>in(n + 1);
    for (int u = 1; u <= n; u++)
    {
        for (auto [v, w] : g[u])
        {
            int f1 = bel[u], f2 = bel[v];
            if (f1 == f2 && w == 1)
            {
                cout << -1;
                return;
            }
            if (f1 != f2)
            {
                ng[f1].push_back({f2, w});
                in[f2]++;
            }
        }
    }
    queue<int>q;
    for (int i = 1; i <= idx; i++)
    {
        if (in[i] == 0)
        {
            q.push(i);
            dp[i] = 1;
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto [v, w] : ng[u])
        {
            dp[v] = max(dp[v], dp[u] + w);
            in[v]--;
            if (in[v] == 0) q.push(v);
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += dp[bel[i]];
    }
    cout << ans;
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