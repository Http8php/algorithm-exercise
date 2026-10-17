/*
标签：分解质因数

思路：a*b分解质因数为p1^k1*p2^k2*...
现要x*y=a*b，且gcd(a,b)最大，就是把质因数均匀分给a,b
注意不能乘起来再分解，这样会超时

时间：O(x^{1/2}+y^{1/2})
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll x, y;
    cin >> x >> y;
    ll a = 1, b = 1;
    map<ll, ll>mp;
    for (int i = 2; i * i <= x; i++)
    {
        while (x % i == 0)
        {
            x /= i;
            mp[i]++;
        }
    }
    if (x > 1)
    {
        mp[x]++;
    }
    for (int i = 2; i * i <= y; i++)
    {
        while (y % i == 0)
        {
            y /= i;
            mp[i]++;
        }
    }
    if (y > 1)
    {
        mp[y]++;
    }
    for (auto [v, c] : mp)
    {
        int cur = 0;
        while (c--)
        {
            if (cur == 0) a *= v;
            else b *= v;
            cur ^= 1;
        }
    }
    cout << a << " " << b << '\n';
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