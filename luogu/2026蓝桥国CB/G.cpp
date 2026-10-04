/*
标签：线段树、逆元

思路：平均值比较好求，维护区间和再乘上len的逆元
操作2是单点修改，可以考虑树状数组或线段树

比较棘手的是方差，先展开式子，设平均值为x
Σ(ai-x)^2 -> Σai^2-2xΣai+Σx^2
由于Σai=nx，所以式子再次化成Σai^2-2nx^2+nx^2
最终为Σai^2-nx^2，需要维护区间平方和
因为单点修改，所以可以不用懒标记，直接修改sq[k]=x*x

维护区间和、平方和和最后答案时注意取模

时间：O(n + mlogn)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e5 + 10;
const int mod = 998244353;
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
int n, m;
ll a[N], sum[N<<2], sq[N<<2];
void build(int p, ll cl, ll cr)
{
    if (cl == cr)
    {
        sq[p] = a[cl] * a[cl] % mod;
        sum[p] = a[cl] % mod;
        return;
    }
    ll mid = (cl + cr) >> 1;
    build(p << 1, cl, mid);
    build(p << 1 | 1, mid + 1, cr);
    sq[p] = (sq[p<<1] + sq[p<<1|1]) % mod;
    sum[p] = (sum[p<<1] + sum[p<<1|1]) % mod;
}
void update(ll k, ll x, int p = 1, ll cl = 1, ll cr = n)
{
    if (cl == cr)
    {
        sq[p] = x * x % mod;
        sum[p] = x % mod;
        return;
    }
    ll mid = (cl + cr) >> 1;
    if (mid >= k) update(k, x, p << 1, cl, mid);
    else update(k, x, p << 1 | 1, mid + 1, cr);
    sq[p] = (sq[p<<1] + sq[p<<1|1]) % mod;
    sum[p] = (sum[p<<1] + sum[p<<1|1]) % mod;
}
ll q1(ll l, ll r, int p = 1, ll cl = 1, ll cr = n)
{
    if (cl >= l && cr <= r) return sum[p];
    ll mid = (cl + cr) >> 1;
    ll res = 0;
    if (l <= mid) res = (res + q1(l, r, p << 1, cl, mid)) % mod;
    if (r > mid) res = (res + q1(l, r, p << 1 | 1, mid + 1, cr)) % mod;
    return res % mod;
}
ll q2(ll l, ll r, int p = 1, ll cl = 1, ll cr = n)
{
    if (cl >= l && cr <= r) return sq[p];
    ll mid = (cl + cr) >> 1;
    ll res = 0;
    if (l <= mid) res = (res + q2(l, r, p << 1, cl, mid)) % mod;
    if (r > mid) res = (res + q2(l, r, p << 1 | 1, mid + 1, cr)) % mod;
    return res % mod;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, n);
    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l, r;
            cin >> l >> r;
            int len = r - l + 1;
            ll avg = q1(l, r) * fp(len, mod - 2) % mod;
            ll var = (q2(l, r) - len * avg % mod * avg % mod + mod) % mod;
            cout << avg << " " << var << '\n';
        }
        else
        {
            int k, x;
            cin >> k >> x;
            update(k, x);
        }
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