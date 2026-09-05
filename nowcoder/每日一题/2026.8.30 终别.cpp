/*
标签：贪心、枚举

思路：首先斩击每次打三个一定更优
从左到右把第一个怪需要的斩击数传给后两个怪，前缀和就是最优解
接下来考虑魔法，也是每次击中两个更优
可以枚举魔法释放的位置，这样需要处理前后两个区间，预处理前后缀和，枚举得到答案

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<ll>a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    // n=1或2直接释放魔法即可
    if (n < 3)
    {
        cout << 0;
        return;
    }
    vector<ll>pre(n + 1), suf(n + 2);
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i-1] + b[i];
        for (int j = i + 1; j <= min(n, i + 2); j++)
        {
            b[j] -= b[i];
            b[j] = max(0ll, b[j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        b[i] = a[i];
    }
    for (int i = n; i >= 1; i--)
    {
        suf[i] = suf[i+1] + b[i];
        for (int j = i - 1; j >= max(1, i - 2); j--)
        {
            b[j] -= b[i];
            b[j] = max(0ll, b[j]);
        }
    }
    ll ans = 1e18;
    for (int i = 1; i < n; i++)
    {
        ll tmp = 0;
        int l = i - 1, r = i + 2;
        if (l >= 1) tmp += pre[l];
        if (r <= n) tmp += suf[r];
        ans = min(ans, tmp);
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