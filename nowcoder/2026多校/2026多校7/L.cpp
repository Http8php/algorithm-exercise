/*
思路：从 (a%b)+1=a%(b+1)入手
设 a=qb+r，a=q(b+1)-q+r
r+1≡r-q(mod(b+1)) q+1≡0(mod(b+1)) q=k(b+1)-1
a=kb(b+1)-b+r r∈[0, b-1] a∈[kb(b+1)-b, kb(b+1)-1]
kb(b+1)-b<=n -> k<=floor((n+b)/(b(b+1)))
由于n<=1e12，b只有<=1e6的情况才有贡献(b^2)，考虑枚举b
对于每个b的每个k，只有k-1个区间是完整的，每个区间长为b，最后一段再取交集即可

时间：O(sqrt(n))
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll b = 1; b * b <= n; b++)
    {
        ll k = (b + n) / (b * (b + 1));
        ans += (k - 1) * b;
        ll l = k * b * (b + 1) - b;
        ll r = k * b * (b + 1) - 1;
        ans += max(min(n, r) - l + 1, 0ll);
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