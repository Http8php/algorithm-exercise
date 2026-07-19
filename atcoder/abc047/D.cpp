/*
思路：要获得最大利润，就在前面的最小值买入，在后面的最大值卖出
从左往右遍历，记录最小值和当前卖出的利润，要让期望最大利润降低1元，只需在每个利润最大值点卖出价都便宜1元

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, t;
    cin >> n >> t;
    vector<int>p(n + 1);
    int mn = 1e9, mx = 0;
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        mn = min(mn, x);
        p[i] = x - mn;
        mx = max(mx, p[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (p[i] == mx) ans++;
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