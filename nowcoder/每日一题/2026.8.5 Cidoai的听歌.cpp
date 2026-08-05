/*
思路：最后要变成同一个数，需要num(最大mx-最小mn)次
在 (mn, mx) 之间的所有数都可以随最大最小值调整
因为从+1开始，最后变成的数距离最大值 floor(num/2)

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n + 1);
    int mn = 1e9, mx = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    int num = mx - mn;
    cout << num << " " << mx - num / 2;
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