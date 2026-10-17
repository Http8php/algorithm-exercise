/*
标签：钩长定理，换根dp，逆元

思路：现在q<=2e5，不能通过完整的dfs求子树大小了
发现实际上换根时，只有u与v的子树大小变化了，其他子树不变
设换根前sz[u]=n，sz[v]=s，则换根后sz[u]=n-s，sz[v]=n
设dp[u]为以u为根时所有子树的乘积，计数公式依旧是(n-2)!除以所有子树乘积
ans=((n-2)!*sz[u]*sz[v])/dp[u]+((n-2)!*sz[u]'*sz[v]')/dp[v]

时间：O(n + q)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
const int mod = 998244353;
int n, q, sz[N], f[N];
ll sum = 1, dp[N];
vector<vector<int> >g(N);
void dfs(int u, int fa)
{
    f[u] = fa;
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
void trans(int r, int u)
{
    sum = sum * fp(sz[u], mod - 2) % mod;
    sz[r] -= sz[u];
    sz[u] = n;
    sum = sum * sz[r] % mod;
}
void dfs2(int u, int fa)
{
    dp[u] = sum;
    for (int v : g[u])
    {
        if (v == fa) continue;
        trans(u, v);
        dfs2(v, u);
        trans(v, u);
    }
}
void solve()
{
    cin >> n >> q;
    vector<pair<int, int> >e;
    for (int i = 0, u, v; i < n - 1; i++)
    {
        cin >> u >> v;
        e.push_back({u, v});
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        sum = sum * sz[i] % mod;
    }
    dfs2(1, 0);
    ll fact = 1;
    for (int i = 2; i <= n - 2; i++)
    {
        fact = fact * i % mod;
    }
    while (q--)
    {
        int x;
        cin >> x;
        x--;
        auto [u, v] = e[x];
        if (f[u] == v) swap(u, v);
        ll ans = 0;
        ll ans1 = fact * fp(dp[u], mod - 2) % mod;
        ans1 = ans1 * sz[v] % mod * n % mod;
        ll ans2 = fact * fp(dp[v], mod - 2) % mod;
        ans2 = ans2 * (n - sz[v]) % mod * n % mod;
        ans = (ans1 + ans2) % mod;
        cout << ans << '\n';
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