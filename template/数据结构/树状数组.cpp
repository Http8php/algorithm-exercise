#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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