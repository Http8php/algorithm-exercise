/*
思路：由于不能旋转矩形，那么最大面积就是短的宽和短的高

时间：O(1)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << min(a, c) * min(b, d);
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