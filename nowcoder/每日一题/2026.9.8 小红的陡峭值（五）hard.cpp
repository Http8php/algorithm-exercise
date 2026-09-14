/*
标签：期望、逆元

思路：首先，陡峭值由不同的相邻对差值组成
排列是对称的，所以每一对数字出现次数是相同的
一共有n(n-1)/2个对，设每个对出现x次
x*n(n-1)/2=n!(n-1) -> x=2n!/n
这是每个数都有的，算期望时要除以总数，于是期望前有系数(2n!/n)/n!=2/n

每个对贡献了它们的差值，现在要计算所有对差值的绝对值之和
将数组排列，任取一对数i<j，|ai-aj|=aj-ai
i=1，为后面的n-1个数充当减数，系数k=-(n-1)=-n+1
i=2，a2-a1时充当了被减数，k=1-(n-2)=-n+3
i=3，k=2-(n-3)=-n+5
这是一个等差数列，公差为2，只需一次遍历就能求和

时间：O(nlogn)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
ll fp(ll a, ll b)
{
    a %= mod;
    ll ans = 1;
    while (b > 0)
    {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    vector<ll>a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll k = 1 - n, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = (sum + k * a[i] % mod + mod) % mod;
        k += 2;
    }
    ll ans = 0;
    ans = 2 * fp(n, mod - 2) % mod * sum % mod;
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