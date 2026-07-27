/*
知识点：二维前缀和，逆元

思路：算术平均数f(l,r) = (S_r-S_{l-1}) / (r-l+1)
发现区间长度很重要，从这入手，设区间长度L
(S_L-S_0) + (S_{L+1}-S_1) + ... + (S_n-S_{n-L})
=(S_L+S_{L+1}+...+S_n) - (S_0+S_1+...+S_{n-L})
考虑再做一次前缀和，P_i = S_1 + S_2 + ... + S_i
上式A =(P_n-P_{L-1}) - (P_{n-L}-P_0)
=P_n - P_{L-1} - P_{n-L}
枚举长度1~n，答案贡献即为 A / L，除法用逆元处理

时间：O(nlogmod)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;
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
    vector<ll>a(n + 1), inv(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        inv[i] = fp(i, mod - 2);
    }
    vector<ll>sum(n + 1);
    for (int i = 1; i <= n; i++)
    {
        sum[i] = (sum[i-1] + a[i]) % mod;
    }
    for (int i = 1; i <= n; i++)
    {
        sum[i] = (sum[i] + sum[i-1]) % mod;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ll res = (sum[n] - sum[i-1] - sum[n-i] + mod) % mod;
        ans = (ans + res * inv[i] % mod) % mod;
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