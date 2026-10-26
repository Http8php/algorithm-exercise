/*
标签：前缀和

思路：ai最大只有30，可以从这入手
最长的符合要求的区间为30 1 ... 1 30，长度为902
所以n^2枚举长度小于等于902的子数组
即使n=2e5，最大时间也是1e8级别，可以通过
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n + 1), sum(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    ll ans = 0;
    for (int l = 1; l <= n - 2; l++)
    {
        for (int r = l + 2; r <= n; r++)
        {
            if (r - l + 1 > 902) break;
            if (a[l] * a[r] == sum[r-1] - sum[l]) ans++;
        }
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