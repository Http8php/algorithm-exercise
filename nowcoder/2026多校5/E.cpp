/*
标签：素数筛

思路：找规律题
设x的质因子数量为k，g(x)即为第k-1个质数
g(x)可以在素数筛中维护，c^i可以线性递推，这样保证不超时

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;
const int N = 1e7 + 10;
ll pc[N];
int g[N];
vector<int>p;
void init(int n)
{
    g[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (g[i] == 0)
        {
            p.push_back(i);
            g[i] = 1;
        }
        for (int x : p)
        {
            if (i * x > n) break;
            g[i*x] = g[i] + 1;
            if (i % x == 0) break;
        }
    }
}
void solve()
{
    int n, c;
    cin >> n >> c;
    init(n);
    pc[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        pc[i] = pc[i-1] * c % mod;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int gx = 0;
        if (g[i] >= 2) gx = p[g[i]-2];
        else gx = 1;
        ans = (ans + gx * pc[i] % mod) % mod;
    }
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}