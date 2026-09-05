using ll = long long;
const int N = 1e5 + 10;
int n, m, p;
ll fact[N], inv[N];
ll fp(ll a, ll b)
{
    ll res = 1;
    a %= p;
    while (b)
    {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
void init()
{
    fact[0] = 1, inv[0] = 1;
    for (int i = 1; i < p; i++)
    {
        fact[i] = fact[i-1] * i % p;
    }
    inv[p-1] = fp(fact[p-1], p - 2);
    for (int i = p - 1; i; i--)
    {
        inv[i-1] = inv[i] * i % p;
    }
}
inline ll C(ll m, ll n, ll p)
{
    return m < n ? 0 : fact[m] * inv[n] % p * inv[m-n] % p;
}
inline ll lucas(ll m, ll n, ll p)
{
    return n == 0 ? 1 % p : lucas(m / p, n / p, p) * C(m % p, n % p, p) % p;
}