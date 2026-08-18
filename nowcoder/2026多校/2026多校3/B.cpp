/*
标签：组合数学，概率，Raney引理

思路：设喝完m瓶时中奖w次，总钱数n-m+cw
因为要恰好花光，n-m-cw=0，即w=(n-m)/c，中奖次数是固定的
如果w非整数或小于0，概率直接是0
问题转化为有多少个长度为m的序列，满足有w次中奖，所有前缀和不为0(即钱不会提前花光)
有Raney引理：序列a，ai<=1，Σai=n(n>0)，其m个循环移位中恰有n个移位的所有非空前缀和>0
中奖增加c-1元，未中奖减少1元，即序列中ai=c-1或-1，初始值n，终点值0，Σai=-n，不满足条件
转化，取相反数：ai=1-c或1，初始值0，终点值n，Σai=n，满足引理
序列总数是C(m, w)，有n/m的数量合法，故合法序列数量是n/m*C(m, w)
中奖概率a/b，未中奖1-a/b，w次中奖，m-w次未中奖
最后答案为：n/m*C(m, w)*(a/b)^w*(1-a/b)^(m-w)

预处理：O(n)
单组时间：O(logmod)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e6 + 10;
const int mod = 998244353;
ll fact[N], inv[N];
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
    ll n, m, c, a, b;
    cin >> n >> m >> c >> a >> b;
    if (m < n || (m - n) % c)
    {
        cout << 0 << '\n';
        return;
    }
    ll w = (m - n) / c;
    ll p = a * fp(b, mod - 2);
    ll q = ((1ll - p) % mod + mod) % mod;
    ll ans = n * fp(m, mod - 2) % mod * C(m, w) % mod * fp(p, w) % mod * fp(q, m - w) % mod;
    cout << ans << '\n';
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