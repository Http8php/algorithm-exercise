using ll = long long;
using i128 = __int128;
ll n, a[15], b[15];
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll x2 = 0, y2 = 0;
    ll g = exgcd(b, a % b, x2, y2);
    x = y2;
    y = x2 - a / b * y2;
    return g;
}
ll inv(ll a, ll p)
{
    ll x, y;
    exgcd(a, p, x, y);
    return (x % p + p) % p;
}
ll crt()
{
    ll p = 1, x = 0;
    for (int i = 1; i <= n; i++) p *= a[i];
    for (int i = 1; i <= n; i++)
    {
        ll r = p / a[i];
        i128 num = (i128)b[i] * r % p * inv(r, a[i]) % p;
        x = (x + num) % p;
    }
    return x % p;
}