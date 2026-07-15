/*
知识点：乘法原理

思路：第一个球可以有k种选择，之后的球只有k-1种选择

时间：O(logn)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll fp(ll a, ll b)
{
    ll ans = 1;
    while (b > 0)
    {
        if (b & 1) ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    cout << k * fp(k - 1, n - 1);
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