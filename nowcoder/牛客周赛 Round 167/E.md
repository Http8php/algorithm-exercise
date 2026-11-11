### 标签
$dfs$

### 思路
由于 $k=1$，只需要单独考虑一个断言。

断言 $1$: $a$ 是 $b$ 的祖先，合法的点集是以 $b$ 为根的子树大小 $sz_a$。

断言 $2$: $a,b$ 没有祖先关系，合法的点集是 $n-sz_a-sz_b$，分别以对面为根算子树大小。

### 时间
$O(n)$

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
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
void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0, u, v; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int op, a, b;
    cin >> op >> a >> b;
    if (op == 1)
    {
        dfs(b, 0);
        cout << sz[a];
    }
    else
    {
        int ans = n;
        dfs(a, 0);
        ans -= sz[b];
        dfs(b, 0);
        ans -= sz[a];
        cout << ans;
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
```