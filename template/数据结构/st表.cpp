#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
int n, q, l2[N];
ll a[N], mx[N][25], mn[N][25];
void init()
{
    for (int i = 2; i <= n + 1; i++)
    {
        l2[i] = l2[i/2] + 1;
    }
    for (int i = 1; i <= n; i++)
    {
        mx[i][0] = mn[i][0] = a[i];
    }
    for (int i = 1; (1 << i) <= n + 1; i++)
    {
        for (int j = 0; j + (1 << i) - 1 <= n; j++)
        {
            mx[j][i] = max(mx[j][i-1], mx[j+(1<<(i-1))][i-1]);
            mn[j][i] = min(mn[j][i-1], mn[j+(1<<(i-1))][i-1]);
        }
    }
}
ll query_max(int l, int r)
{
    int j = l2[r-l+1];
    return max(mx[l][j], mx[r-(1<<j)+1][j]);
}
ll query_min(int l, int r)
{
    int j = l2[r-l+1];
    return min(mn[l][j], mn[r-(1<<j)+1][j]);
}