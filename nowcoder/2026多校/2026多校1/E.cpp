/*
思路：推式子，对于每个数P_i，+i次，-(n-1-i)次
ans=Σ{i}(2i-n+1)P_i

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    ll ans = 0;
    cin >> n;
    for (int i = 0, x; i < n; i++)
    {
        cin >> x;
        ans += (2 * i - n + 1) * x;
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