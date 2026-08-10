/*
标签：树的直径、lca

思路：把染红的点单独拿出，也能形成一棵树，答案是这棵树的直径
找直径的过程是先找一个红点，遍历到离它最远的红点，再从这个红点遍历到离它最远的红点
找到两个端点后，每加入一个点，把它当成新端点重算距离，与直径取最大
算距离找到最近公共祖先fa，dis=abs(a-fa)+abs(fa-b)

时间：O(20n + nlogn)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
int n, st = -1, a = -1, b = -1, mx;
int dep[N], f[N][20];
vector<vector<int> >g(N);
void init(int u, int fa)
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
        init(v, u);
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
int calc(int a, int b)
{
    int fa = lca(a, b);
    return abs(dep[a] - dep[fa]) + abs(dep[fa] - dep[b]);
}
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    s = " " + s;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '1')
        {
            st = i;
            break;
        }
    }
    for (int i = 0, u, v; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    init(1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '0' || i == st) continue;
        int dis = calc(st, i);
        if (dis > mx)
        {
            a = i;
            mx = dis;
        }
    }
    mx = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '0' || i == a) continue;
        int dis = calc(a, i);
        if (dis > mx)
        {
            b = i;
            mx = dis;
        }
    }
    int dis = calc(a, b);
    for (int i = 1; i <= n; i++)
    {
        cout << max(dis, calc(a, i), calc(b, i)) << '\n';
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