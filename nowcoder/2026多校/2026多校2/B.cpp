/*
知识点：线性基

思路：设集合X, Y，S = X ^ Y
X + Y = (X ^ Y) + (X & Y) * 2
(X + Y)max = S + (X & Y) * 2
即求(X & Y)的最大值，由于S的限制，只有异或后为0的位置X&Y才有可能是1
在0的位置构造线性基，问题转化为在这些位置上找最大异或和

时间：O(30 * n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll b[31];
void init()
{
    for (int i = 0; i <= 30; i++)
    {
        b[i] = 0;
    }
}
void insert(ll x)
{
    for (int i = 30; i >= 0; i--)
    {
        if (((x >> i) & 1) == 0) continue;
        if (b[i] == 0)
        {
            b[i] = x;
            return;
        }
        x ^= b[i];
    }
}
void solve()
{
    init();
    int n;
    ll tot = 0;
    cin >> n;
    vector<ll>a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        tot ^= a[i];
    }
    // 在tot为0处是1
    ll mask = (((1 << 30) - 1) ^ tot);
    for (int i = 0; i < n; i++)
    {
        // 构造在0位的线性基
        insert(a[i] & mask);
    }
    ll mx = 0;
    for (int i = 30; i >= 0; i--)
    {
        if ((mx ^ b[i]) > mx) mx ^= b[i];
    }
    cout << tot + mx * 2 << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}