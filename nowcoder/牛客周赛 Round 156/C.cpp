/*
标签：贪心、二分、前缀和

思路：操作最优的情况是把离x最大的数变成x
把所有差值算出，从大到小排序，求前缀和
设当前总差值是cur，如果k>=cur不用操作，k<cur要在前缀和中找到>=cur-k的索引

时间：O(n + szlogsz + qlogsz)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, q;
    ll x;
    cin >> n >> q >> x;
    vector<ll>a(n + 1), b;
    ll cur = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ll d = abs(a[i] - x);
        if (d > 0) b.push_back(d);
        cur += d;
    }
    if (cur == 0)
    {
        while (q--)
        {
            ll k;
            cin >> k;
            cout << 0 << '\n';
        }
        return;
    }
    sort(b.begin(), b.end(), greater<>());
    int sz = b.size();
    vector<ll>sum(sz);
    sum[0] = b[0];
    for (int i = 1; i < sz; i++)
    {
        sum[i] = sum[i-1] + b[i];
    }
    while (q--)
    {
        ll k;
        cin >> k;
        if (k >= cur)
        {
            cout << 0 << '\n';
            continue;
        }
        int ans = lower_bound(sum.begin(), sum.end(), cur - k) - sum.begin() + 1;
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