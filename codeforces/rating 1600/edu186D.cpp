/*
标签：组合数学

思路：a0是公用的数字，可以把a0中的数分配到a1~an中
由于是循环取数，分配完后的a1~an最大差值不能大于1，这是条件1

设sum为数组和，则ceil(sum/n)是每个i(i>0)可以达到的上界，ai不能超过上界
n*(x-1)是完整的x-1轮循环，还剩下y=sum-n*(x-1)的余量可以用
统计ai=x的数量cnt，如果cnt>y，说明余量不够了，这是条件2

两个条件都满足，说明有解
cnt个数为x，必须填在前y个位置内，不然a0不够用
这个方案数为y!/(y-cnt)!
还有n-cnt个数，可以随意填，方案数为(n-cnt)!
最终答案是y!/(y-cnt)!*(n-cnt)!

单组时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;
void solve()
{
    int n, sum = 0, mx = 0;
    cin >> n;
    vector<int>a(n + 1);
    for (int i = 0; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
        if (i > 0) mx = max(mx, a[i]);
    }
    int x = (sum + n - 1) / n;
    if (mx > x)
    {
        cout << 0 << '\n';
        return;
    }
    int y = sum - n * (x - 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == x) cnt++;
    }
    if (cnt > y)
    {
        cout << 0 << '\n';
        return;
    }
    int z = n - cnt;
    ll ans = 1;
    for (int i = y; i > y - cnt; i--)
    {
        ans = ans * i % mod;
    }
    for (int i = 2; i <= z; i++)
    {
        ans = ans * i % mod;
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