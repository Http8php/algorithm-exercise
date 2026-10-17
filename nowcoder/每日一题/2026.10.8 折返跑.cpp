/*
标签：组合数学

思路：需要走m趟，杆子会移动m-1次
1~n中间有n-2个点，只要在这n-2个点中选m-1个点即可
由于第一次移动一定是右杆，所以选出的m-1个位置摆法是唯一的

预处理：O(N)
单组时间：O(1)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
ll fact[N], inv[N];
ll fp(ll a, ll b)
{
    ll res = 1;
    a %= mod;
    while (b)
    {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
void ptm()
{
    fact[0] = 1, inv[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = fact[i-1] * i % mod;
    }
    inv[N-1] = fp(fact[N-1], mod - 2);
    for (int i = N - 1; i; i--)
    {
        inv[i-1] = inv[i] * i % mod;
    }
}
ll C(int n, int m)
{
    if (n < m || n < 0 || m < 0) return 0;
    return fact[n] * inv[m] % mod * inv[n-m] % mod;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    cout << C(n - 2, m - 1) << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ptm();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}