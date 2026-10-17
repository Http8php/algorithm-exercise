/*
标签：贪心

思路：先算出当前数组的和，与目标进行比较
如果当前和大了，取最大的数，直接设为-1e4，变化过程中能凑到目标就停止
和小了同理，取最小的数操作
题目保证有解，这样贪心可以找到最小操作数

单组时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{ 
    int n;
    ll sum, cur = 0;
    cin >> n >> sum;
    vector<int>a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cur += a[i];
    }
    sort(a.begin() + 1, a.end());
    int ans = 0;
    if (cur < sum)
    {
        ll d = sum - cur;
        for (int i = 1; i <= n; i++)
        {
            ll v = 10000 - a[i];
            ans++;
            if (v >= d) break;
            d -= v;
        }
    }
    else if (cur > sum)
    {
        ll d = cur - sum;
        for (int i = n; i >= 1; i--)
        {
            ll v = 10000 + a[i];
            ans++;
            if (v >= d) break;
            d -= v;
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