#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, q;
int a[N], mx[N][18], mn[N][18];
void init()
{
    for (int j = 1; (1 << j) <= n; j++)
    {
        int tmp = (1 << j - 1);
        for (int i = 1; i + tmp <= n; i++)
        {
            mx[i][j] = max(mx[i][j-1], mx[i+tmp][j-1]);
            mn[i][j] = min(mn[i][j-1], mn[i+tmp][j-1]);
        }
    }
}
int query_max(int l, int r)
{
    int len = r - l + 1;
    int j = log2(len);
    return max(mx[l][j], mx[r-(1<<j)+1][j]);
}
int query_min(int l, int r)
{
    int len = r - l + 1;
    int j = log2(len);
    return min(mn[l][j], mn[r-(1<<j)+1][j]);
}