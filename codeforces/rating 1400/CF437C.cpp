/*
知识点：贪心

思路：要将所有的点删除，所有的边也会删除
只要一条边连接的两个点其中有一个点被删，这条边就被删除了
对答案的贡献是值小的那个点，对所有边这样处理即可

时间：O(m)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int>a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v;
        ans += min(a[u], a[v]);
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