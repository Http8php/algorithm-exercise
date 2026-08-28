using ll = long long;
int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

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