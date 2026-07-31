/*
思路：设每进行一次游戏的得分为x，第i次累计得分为i*x
每次有约束 a_i<=ix<a_i+1 -> a_i/i<=x<(a_i+1)/i
由于题目保证有解，答案即为最小右端点

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    double ans = 1e10;
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        double r = 1.0 * (x + 1.0) / i;
        ans = min(ans, r);
    }
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(10);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}