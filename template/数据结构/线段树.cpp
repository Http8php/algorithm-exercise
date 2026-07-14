#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
ll tr[N<<2], mark[N<<2];
ll n, m, a[N];
void push_down(int p, ll len)
{
    if (len <= 1) return;
    tr[p<<1] += mark[p] * (len - len / 2);
    mark[p<<1] += mark[p];
    tr[p<<1|1] += mark[p] * (len / 2);
    mark[p<<1|1] += mark[p];
    mark[p] = 0;
}
void build(int p, ll cl, ll cr)
{
    if (cl == cr)
    {
        tr[p] = a[cl];
        return;
    }
    ll mid = (cl + cr) >> 1;
    build(p << 1, cl, mid);
    build(p << 1 | 1, mid + 1, cr);
    tr[p] = tr[p<<1] + tr[p<<1|1];
}
void update(ll l, ll r, ll d, int p = 1, ll cl = 1, ll cr = n)
{
    if (cl >= l && cr <= r)
    {
        tr[p] += d * (cr - cl + 1);
        mark[p] += d;
        return;
    }
    push_down(p, cr - cl + 1);
    ll mid = (cl + cr) >> 1;
    if (mid >= l) update(l, r, d, p << 1, cl, mid);
    if (mid < r) update(l, r, d, p << 1 | 1, mid + 1, cr);
    tr[p] = tr[p<<1] + tr[p<<1|1];
}
ll query(ll l, ll r, int p = 1, ll cl = 1, ll cr = n)
{
    if (cl >= l && cr <= r) return tr[p];
    push_down(p, cr - cl + 1);
    ll mid = (cl + cr) >> 1;
    ll res = 0;
    if (l <= mid) res += query(l, r, p << 1, cl, mid);
    if (r > mid) res += query(l, r, p << 1 | 1, mid + 1, cr);
    return res;
}