using ll = long long;
const int N = 1e6 + 10;
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
    fact[0] = 1;
    inv[0] = 1;
    for (int i = 1; i <= N; i++)
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
ll A(int n, int m)
{
    if (n < m || n < 0 || m < 0) return 0;
    return fact[n] * inv[n-m] % mod;
}

// 小数据 杨辉三角
/*
ll C[55][55];
void init()
{
    for (int i = 0; i <= 50; i++)
    {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }  
    }
}
*/