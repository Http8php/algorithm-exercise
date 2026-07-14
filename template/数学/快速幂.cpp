using ll = long long;
ll fp(ll a, ll b)
{
    ll ans = 1;
    while (b > 0)
    {
        if (b & 1) ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}
/*
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

ll fp(ll a, ll b, ll p)
{
    a %= p;
    ll ans = 1;
    while (b > 0)
    {
        if (b & 1) ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}
*/