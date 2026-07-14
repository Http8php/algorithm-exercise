#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
const int inf = 0x3f3f3f3f;
int n, idx, mx, dis[N];
vector<vector<pair<int, ll> > >g(N);
void dfs(int u, int fa, ll nd)
{
    dis[u] = nd;
    if (nd > mx)
    {
        mx = nd;
        idx = u;
    }
    for (auto [v, w] : g[u])
    {
        if (v == fa) continue;
        dfs(v, u, nd + w);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0, u, v, w; i < n - 1; i++)
    {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    mx = -1;
    dfs(1, 0, 0);
    mx = -1;
    dfs(idx, 0, 0);
    cout << mx;
    return 0;
}