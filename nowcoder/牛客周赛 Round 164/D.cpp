/*
标签：贪心，枚举，前缀和

思路：贪心地想，要让收获的钱最多，取ai大的一定更优
但是有钱和篮子的限制，这样不一定是最优
发现顾客只有买篮子和不买篮子两种，可以枚举买篮子的顾客
用剩余的钱计算还能卖给多少不买篮子的顾客，前缀和计算快速答案

时间：O(nlogn)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll x, y, s, m, k;
    cin >> x >> y >> s >> m >> k;
    int n;
    cin >> n;
    vector<ll>a(n), cnt0, cnt1;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0, b; i < n; i++) 
    {
        cin >> b;
        if (b == 1) cnt1.push_back(a[i]);
        else cnt0.push_back(a[i]);
    }
    sort(cnt0.rbegin(), cnt0.rend());
    sort(cnt1.rbegin(), cnt1.rend());
    int sz0 = cnt0.size();
    for (int i = 1; i < sz0; i++)
    {
        cnt0[i] += cnt0[i-1];
    }
    int sz1 = cnt1.size();
    for (int i = 1; i < sz1; i++)
    {
        cnt1[i] += cnt1[i-1];
    }
    ll ans = 0;
    for (int i = 0; i <= sz1; i++)
    {
        ll res = (i == 0 ? 0 : cnt1[i-1]);
        ll ns = s - i * (k * x + y), nm = m - i * k;
        if (ns < 0 || nm < 0) break;
        int mn = min(m / k, ns / (k * x));
        if (mn > 0)
        {
            int idx = min(sz0, mn) - 1;
            res += cnt0[idx];
        }
        ans = max(ans, res);
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