/*
知识点：贪心，前缀和

思路：数组的顺序与答案无关，先排序，计算出前缀和
当k为奇数时，设子序列有2m-1个数，中位数在p处
前面的数肯定越小越好，直接取前m个，然后枚举中位数，并把中位数后的m个数换成中位数

当k为偶数时，设子序列有2m个数
前面的数也是越小越好，直接取前m-1个，比中位数大的数越小越好，中位数的选取应该贴着取

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll>a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    vector<ll>sum(n + 1);
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i-1] + a[i];
    }
    ll ans = 0;
    if (k % 2)
    {
        int m = (k - 1) / 2;
        ll sl = sum[m];
        for (int i = m + 1; i <= n - m; i++)
        {
            ll sr = sum[i+m] - sum[i];
            ll res = (sum[n] - sl - sr) + (k - 1) * a[i];
            ans = max(ans, res);
        }
    }
    else
    {
        int m = k / 2 - 1;
        ll sl = sum[m];
        for (int i = m + 1; i < n - m; i++)
        {
            ll sr = sum[i+1+m] - sum[i+1];
            // k一定是偶数，不会有小数
            ll res = (sum[n] - sl - sr - a[i] - a[i+1]) + k * (a[i] + a[i+1]) / 2;
            ans = max(ans, res);
        }
    }
    cout << ans << '\n';
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