#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;
struct Fenwick
{
    int n;
    vector<ll>tr;
    Fenwick(int n): n(n), tr(n + 1) {}
    void add(int x, int v)
    {
        while (x <= n)
        {
            tr[x] += v;
            x += (x & -x);
        }
    }
    ll sum(int x)
    {
        ll ans = 0;
        while (x > 0)
        {
            ans += tr[x];
            x -= (x & -x);
        }
        return ans;
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<ll>fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fact[i] = fact[i-1] * i % mod;
    }
    vector<int>a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    Fenwick A(n);
    ll ans = 1;
    for (int i = n; i >= 1; i--)
    {
        ll tmp = A.sum(a[i]) % mod;
        ans = (ans + tmp * fact[n-i] % mod) % mod;
        A.add(a[i], 1);
    }
    cout << ans;
}