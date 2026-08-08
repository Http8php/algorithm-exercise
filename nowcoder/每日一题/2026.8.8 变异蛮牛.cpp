/*
标签：树，dfs

思路：在任何一条链上，黑点白点是交替的，于是最长的链只可能是1
问题转换成计数所有黑点比白点多一个的链，1是黑点，就是奇数长的链
发现深度为奇数的点都是黑点，链两端一定都是这样的点
在树上往下dfs时，每当有一个深度为奇数的点，对答案的贡献是本身加之前所有的奇数点

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
vector<vector<int> >g(N);
int dep[N];
ll ans, sum;
void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    if (dep[u] & 1)
    {
        sum++;
        ans += sum;
    }
    for (int v : g[u])
    {
        if (v == fa) continue;
        dfs(v, u);
    }
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 0, u, v; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ans = 0, sum = 0;
    dfs(1, 0);
    cout << ans << '\n';
    // 多测清空
    for (int i = 1; i <= n; i++)
    {
        dep[i] = 0;
        g[i].clear();
    }
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