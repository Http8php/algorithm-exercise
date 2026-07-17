/*
思路：先写出修改一段的贡献式子 R: (l + r)(r - l + 1) - (sum[r] - sum[l-1])
由于只能改一段，目标就是找到这个贡献的最大值，答案是 sum[n] + max(R)
有l和sum[l-1]在，式子较难处理，考虑打开式子
r^2 + r - sum[r] - l^2 + l + sum[l-1] 同构，等价变形
r^2 + r - sum[r] - ((l - 1)^2 + (l - 1) - sum[l-1])
f(r) - f(l-1) f(x) = x^2 + x - sum[x]
遍历r，维护最小的f(r)，获得最大的R，特别地，f(0) = 0

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<ll>a(n + 1);
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ans += a[i];
    }
    // mn = f(0)
    ll sum = 0, mn = 0, mx = 0;
    for (ll i = 1; i <= n; i++)
    {
        sum += a[i];
        ll cur = i * i + i - sum;
        mn = min(mn, cur);
        mx = max(mx, cur - mn);
    }
    cout << ans + mx << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}