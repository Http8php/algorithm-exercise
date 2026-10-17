/*
标签：逆元

思路：先分解a=p1^k1*p2^k2*...
a^b=p1^bk1*p2^bk2*...
因子是由不同的质因子组合而成，一个质因子可以取0,1,2...项
即(1 + p1 + p1^2 + ... + p1^k1)，所有的质因子乘起来就是答案
这个是等比数列，可以化简成(p1^{k1+1}-1)/(p1-1)

由于需要取模，需要得到p1-1的逆元
9901是质数，基本可以用费马小定理求，除了p1-1是9901倍数的情况
也就是p1%9901=1，此时没有逆元，需要另想办法
发现(1 + (p1%9901) + (p1%9901)^2 + ...)相当于1+k1

时间：O(a^{1/2}*logb)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 9901;
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
    int a, b;
    cin >> a >> b;
    int ta = a;
    ll ans = 1;
    for (int i = 2; i * i <= a; i++)
    {
        ll cnt = 0;
        while (ta % i == 0)
        {
            cnt++;
            ta /= i;
        }
        if (cnt)
        {
            ll tot = cnt * b;
            if (i % mod == 1)
            {
                ans = ans * (tot + 1) % mod;
            }
            else
            {
                ll inv = fp(i - 1, mod - 2);
                ll res = (fp(i, tot + 1) - 1 + mod) % mod * inv % mod;
                ans = (ans * res) % mod;
            }
        }
    }
    if (ta > 1)
    {
        if (ta % mod == 1)
        {
            ans = (ans * (b + 1)) % mod;
        }
        else
        {
            ll inv = fp(ta - 1, mod - 2);
            ll res = (fp(ta, b + 1) - 1 + mod) % mod * inv % mod;
            ans = (ans * res) % mod;
        }
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