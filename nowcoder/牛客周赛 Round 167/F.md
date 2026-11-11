### 标签
$dfs$， $LCA$，树上差分

### 思路
有了 $easy$ 版本的铺垫， $hard$ 版本也考虑从子树下手。发现每一个断言都代表一片合法点集，且总是以子树为单位，想到树上差分，如果最后点上的标记数 $=k$，说明这个点符合条件。

强制以 $1$ 为根，便于树上差分。

断言 $1$ 现在分成三种情况

$1.a$ 是 $b$ 的祖先，设 $c$ 为路径 $a-b$ 上的第一个点，合法的点集是 $sz_1-sz_c$

$2.b$ 是 $a$ 的祖先或没有祖先关系，合法的点集是 $sz_a$

断言 $2$ 同理

$1.a$ 是 $b$ 的祖先，设 $c$ 为路径 $a-b$ 上的第一个点，合法的点集是 $sz_c-sz_b$

$2.b$ 是 $a$ 的祖先，设 $c$ 为路径 $b-a$ 上的第一个点，合法的点集是 $sz_c-sz_a$

$3.$ 没有祖先关系，合法的点集是 $sz_1-sz_a-sz_b$

用 $LCA$ 判断 $a,b$ 的祖先关系。

### 时间
$O(n + k)$

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
vector<vector<int> >g(N);
int d[N], dep[N], f[N][20];
void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    f[u][0] = fa;
    for (int i = 1; i <= 19; i++)
    {
        f[u][i] = f[f[u][i-1]][i-1];
    }
    for (int v : g[u])
    {
        if (v == fa) continue;
        dfs(v, u);
    }
}
int lca(int a, int b)
{
    if (dep[a] < dep[b]) swap(a, b);
    for (int i = 19; i >= 0; i--)
    {
        if (dep[f[a][i]] >= dep[b])
        {
            a = f[a][i];
        }
    }
    if (a == b) return a;
    for (int i = 19; i >= 0; i--)
    {
        if (f[a][i] != f[b][i])
        {
            a = f[a][i];
            b = f[b][i];
        }
    }
    return f[a][0];
}
void dfs2(int u, int fa)
{
    for (int v : g[u])
    {
        if (v == fa) continue;
        d[v] += d[u];
        dfs2(v, u);
    }
}
void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0, u, v; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 0; i < k; i++)
    {
        int op, a, b;
        cin >> op >> a >> b;
        int fa = lca(a, b);
        if (op == 1)
        {
            if (fa == a)
            {
                int c = b;
                for (int i = 19; i >= 0; i--)
                {
                    if (dep[f[c][i]] > dep[a])
                    {
                        c = f[c][i];
                    }
                }
                d[1]++, d[c]--;
            }
            else d[a]++;
        }
        else
        {
            if (fa == a)
            {
                int c = b;
                for (int i = 19; i >= 0; i--)
                {
                    if (dep[f[c][i]] > dep[a])
                    {
                        c = f[c][i];
                    }
                }
                d[c]++, d[b]--;
            }
            else if (fa == b)
            {
                int c = a;
                for (int i = 19; i >= 0; i--)
                {
                    if (dep[f[c][i]] > dep[b])
                    {
                        c = f[c][i];
                    }
                }
                d[c]++, d[a]--;
            }
            else d[1]++, d[a]--, d[b]--;
        }
    }
    dfs2(1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += (d[i] == k);
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
```