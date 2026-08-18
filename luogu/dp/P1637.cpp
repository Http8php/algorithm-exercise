/*
标签：dp优化、树状数组

思路：设dp[i][j]为以第j个元素结尾，长度为i的严格上升子序列的个数
要算dp[i][j]，需要在j之前找到所有值比a[j]小的位置，把它们对应的dp[i-1]加起来
遍历时，j从小到大，j<k天然满足，只要a[j]<a[k]就可以拼到dp[i][j]后面变成dp[i+1][k]
由于值域<=10^5，不需要离散化也可以

时间：O(nlogmx)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Fenwick
{
    int n;
    vector<ll>tr;
    Fenwick(int n): n(n), tr(n + 1) {}
    void add(int x, ll v)
    {
        while (x <= n)
        {
            tr[x] += v;
            x += (x & -x);
        }
    }
    ll sum(int x)
    {
        ll res = 0;
        while (x >= 1)
        {
            res += tr[x];
            x -= (x & -x);
        }
        return res;
    }
};
void solve()
{
    int n, mx = 0;
    cin >> n;
    vector<int>a(n + 1);
    vector<vector<int> >dp(4, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
        dp[1][i] = 1;
    }
    for (int i = 2; i <= 3; i++)
    {
        Fenwick cnt(mx);
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] += cnt.sum(a[j] - 1);
            cnt.add(a[j], dp[i-1][j]);
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += dp[3][i];
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