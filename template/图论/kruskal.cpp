#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
struct edge
{
    int u, v, w;
}es[N];
bool cmp(edge x, edge y)
{
    return x.w < y.w;
}
int n, m, cnt, f[N];
ll ans;
int find(int x)
{
    if (f[x] == x) return x;
    else return f[x] = find(f[x]);
}
void kus(int u, int v, int w)
{
    int f1 = find(u), f2 = find(v);
    if (f1 == f2) return;
    f[f1] = f2;
    ans += w;
    cnt++;
}