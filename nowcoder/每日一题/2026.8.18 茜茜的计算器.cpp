/*
标签：分类讨论

思路：上下对称：0138组成，可以随意摆放，4^n种方案
左右对称：08，不容易发现的是25，1在由于在“日”的右边，不满足对称
n为偶数时，左边n/2个位置随意填0258，右边只能填左边对称过去的数，4^{n/2}种方案
只含08的方案在上下对称已记录，需要删除2^{n/2}种方案
n为奇数时，中间的位置只能填0或8，比n-1的左右对称方案数多了一倍，直接×2即可

时间：O(logn)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
ll fp(ll a, ll b)
{
    ll res = 1;
    a %= mod;
    while (b)
    {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
void solve()
{
    int n;
    cin >> n;
    ll c1, c2;
    c1 = fp(4, n);
    c2 = (fp(4, n / 2) - fp(2, n / 2) + mod) % mod;
    if (n & 1) cout << (c1 + c2 * 2 % mod) % mod;
    else cout << (c1 + c2) % mod;
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