/*
标签：钩长定理，逆元

思路：对于一颗有根树，节点数为n，子树大小为sz
最后删除根节点的方案数为n!除以所有子树乘积

现题目固定删除的最后边u-v，也就是最后会留u或者v一个点
1.删u保留v，以v为根，答案是(n-2)!除以除了sz[u]sz[v]以外所有子树的乘积
2.删v保留u，以u为根，答案形状是相同的

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
const int mod = 998244353;
int sz[N];
vector<vector<int> >g(N);
void dfs(int u, int fa)
{
    sz[u] = 1;
    for (int v : g[u])
    {
        if (v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}
ll fp(ll a, ll b)
{
    a %= mod;
    ll ans = 1;
    while (b > 0)
    {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<pair<int, int> >e;
    for (int i = 0, u, v; i < n - 1; i++)
    {
        cin >> u >> v;
        e.push_back({u, v});
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int x;
    cin >> x;
    x--;
    auto [u, v] = e[x];
    ll fact = 1;
    for (int i = 2; i <= n - 2; i++)
    {
        fact = fact * i % mod;
    }
    ll ans = 0, sum = 1;
    dfs(v, 0);
    for (int i = 1; i <= n; i++)
    {
        if (i == u || i == v) continue;
        sum = sum * sz[i] % mod;
    }
    ll inv = fp(sum, mod - 2);
    ans = (ans + fact * inv % mod) % mod;
    sum = 1;
    dfs(u, 0);
    for (int i = 1; i <= n; i++)
    {
        if (i == u || i == v) continue;
        sum = sum * sz[i] % mod;
    }
    inv = fp(sum, mod - 2);
    ans = (ans + fact * inv % mod) % mod;
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