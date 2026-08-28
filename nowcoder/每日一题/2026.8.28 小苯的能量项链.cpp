/*
标签：枚举

思路：题目翻译过来就是取数组中的两个数，使和最大
当前面取了第i个数时，还有k-(i-1)的余量把后面的数拿掉
也就是说，可以随意取后面的k-(i-1)个数，只要比i的索引大
维护一个后缀最大值，从1枚举到min(n, k)记录最大值即可

单组时间：O(n)
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
    ll ans = (n == 1 ? a[1] : a[1] + a[n]);
    vector<ll>suf(n + 2);
    for (int i = n; i >= 1; i--)
    {
        suf[i] = max(suf[i+1], a[i]);
    }
    for (int i = 1; i <= min(n, k); i++)
    {
        int j = n - (k - (i - 1));
        if (j <= i) j = i + 1;
        ans = max(ans, a[i] + suf[j]);
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