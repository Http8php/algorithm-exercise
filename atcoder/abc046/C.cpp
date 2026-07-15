/*
知识点：贪心

思路：要变成当前比例并且数量少，就要找一个系数k乘在当前比例，使当前票最小值不比前一次票最大值小
第一个比例，最优k=1，之后k的确定依赖 ceil(x / t) 和 ceil(y / a) 之间的最大值

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    ll x = 0, y = 0;
    for (int i = 1, t, a; i <= n; i++)
    {
        cin >> t >> a;
        if (i == 1) x = t, y = a;
        else
        {
            ll c1 = (x + t - 1) / t;
            ll c2 = (y + a - 1) / a;
            ll k = max(c1, c2);
            x = k * t, y = k * a;
        }
    }
    cout << x + y;
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