/*
知识点：二分答案

小trick：k-th问题可以考虑二分

思路：有序列长度len，单次操作相当于len - floor(len / y)
如果x次操作后，恰好剩余k个，就满足要求，我们要找最小的满足要求的长度
考虑二分，序列长了剩余比k大，反之比k小

时间：O(log1e12 * x)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int x;
    ll y, k;
    cin >> x >> y >> k;
    ll l = 0, r = 1e12;
    ll ans = -1;
    while (l <= r)
    {
        ll mid = (l + r) >> 1;
        ll cur = mid;
        for (int i = 0; i < x; i++)
        {
            cur -= cur / y;
        }
        if (cur >= k)
        {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
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