/*
标签：贪心

思路：初始x=0，a[i]只能加，发现一旦x>1，选×一定优于+
注意后续a[i]=0或1，选+一定优于×

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;
void solve()
{
    int n;
    cin >> n;
    vector<ll>a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll ans = 0;
    int i = 1;
    while (i <= n && ans < 2)
    {
        ans += a[i];
        i++;
    }
    for (int j = i; j <= n; j++)
    {
        if (a[j] == 0 || a[j] == 1)
        {
            ans += a[j];
            if (ans > mod) ans -= mod;
        }
        else
        {
            ans = ans * a[j] % mod;
        }
    }
    cout << ans % mod << '\n';
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