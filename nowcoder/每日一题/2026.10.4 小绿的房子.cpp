/*
标签：树的直径、分类讨论

思路：树间距离最远的两个点是树的直径mx，可以通过这个分类讨论
如果mx<=3(直径有三个点)，说明所有的点距离都不会超过2，输出n
3<mx<=5，mx=4只有中间两个点符合要求，mx=5只有一个，合起来是6-mx
mx>5，不可能有符合要求的点，答案是0

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5;
int mx, idx;
vector<vector<int> >g(N);
void dfs(int u, int fa, int d)
{
    if (d > mx)
    {
        mx = d;
        idx = u;
    }
    for (int v : g[u])
    {
        if (v == fa) continue;
        dfs(v, u, d + 1);
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
    mx = 0, idx = 0;
    dfs(1, 0, 1);
    mx = 0;
    dfs(idx, 0, 1);
    if (mx > 5)
    {
        cout << 0;
        return;
    }
    if (mx > 3)
    {
        cout << 6 - mx;
        return;
    }
    cout << n;
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