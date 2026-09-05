/*
标签：贪心、前缀和、枚举

思路：首先对价值高的物品用优惠券一定更优
注意到a用在前面更优，最后使用优惠券应该是形如aba的结构
可以枚举b开始的地方，把三段区域的价格算出，取最小的价值
算价格时用前缀和实现O(1)查询

单组时间：O(nlogn)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, a, b, x, y;
    cin >> n >> a >> b >> x >> y;
    vector<double>p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    sort(p.rbegin(), p.rend());
    vector<double>pre(n + 1), sum(n + 1);
    for (int i = 0; i < n; i++)
    {
        pre[i+1] = pre[i] + p[i];
        sum[i+1] = sum[i] + max(0.0, p[i] - y);
    }
    double ans = 1e18;
    for (int k = 0; k <= a; k++)
    {
        int r = min(n, k + b);
        double res = pre[k] * (x / 100.0) + (sum[r] - sum[k]);
        int na = a - k;
        int nr = min(n, r + na);
        res += (pre[nr] - pre[r]) * (x / 100.0) + (pre[n] - pre[nr]);
        ans = min(ans, res);
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}