/*
标签：二分答案、枚举

思路：首先血量上限是10^9级别，无法dp
求最少回合数，可以发现回合数有单调性，考虑二分答案
如果又有毒又有普攻，那么一定是毒在前普攻在后，毒叠起来后，伤害高且覆盖的回合更多
需要找任意一个分界点，如果总伤大于x，就可以把右端点往左移
毒造成的伤害是等差数列，和是二次的，这代表回合数不超过sqrt(x)，可以直接枚举分界点

时间：O(sqrt(x)logx)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6;
ll x, a, b, ans;
ll calc(ll c1, ll c2)
{
    ll d1 = c1 * (c1 + 1) / 2 * a - c1 * (c1 - 1) / 2;
    ll d2 = c2 * b;
    ll fin = c1 * a - c1;
    ll d3;
    if (fin <= c2) d3 = fin * (fin + 1) / 2;
    else d3 = (fin + fin - c2 + 1) * c2 / 2;
    return d1 + d2 + d3;
}
bool check(int mid)
{
    // 保险起见取了1e6
    for (int i = 0; i <= min(mid, N); i++)
    {
        if (calc(mid - i, i) >= x) return true;
    }
    return false;
}
void solve()
{
    cin >> x >> a >> b;
    int l = 1, r = (x + b - 1) / b;
    ans = r;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
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