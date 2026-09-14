/*
思路：先把n转换成k进制，要拆成不同的数，就是找幂系数最大的那一位
比如n=k^c1+k^c2+k^c2+k^c3 拆成k^c1+k^c2+k^c3和k^c2两个数最优
注意k=1可以随意变换幂，答案一定是1

单组时间：O(logn)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, k, ans = 0;
    cin >> n >> k;
    if (k == 1)
    {
        cout << 1 << '\n';
        return;
    }
    while (n)
    {
        ans = max(ans, n % k);
        n /= k;
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