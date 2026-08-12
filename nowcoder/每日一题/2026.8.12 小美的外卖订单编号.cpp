/*
思路：模运算性质，注意编号没有0

时间：O(q)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int q;
    cin >> q;
    while (q--)
    {
        int m, x;
        cin >> m >> x;
        int ans = x % m;
        if (ans == 0) ans = m;
        cout << ans << '\n';
    }
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