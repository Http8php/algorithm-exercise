/*
标签：概率dp

思路：设dp[i][j]为当小红已经吃了i枚棋子、小紫已经吃了j枚棋子时，小红最终获胜的概率
小红 小紫
吃   吃   A = dp[i][j] = dp[i+1][j+1] * p1 * p2
吃   不吃 B = dp[i][j] = dp[i+1][j] * p1 * (1 - p2)
不吃 不吃 C = dp[i][j] = dp[i+1][j] * (1 - p1) * p2
dp[i][j] = A + B + C + dp[i][j] * (1 - p1) * (1 - p2)
dp[i][j] = (A + B + C) / (1 - (1 - p1) * (1 - p2)) 分母化简为p1+p2-p1p2
初始化dp[i][x] = 1, i=0~x-1
答案为dp[0][0]

时间：O(x^2)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int N = 1e3 + 10;
ll fp(ll a, ll b)
{
    a %= mod;
    ll ans = 1;
    while (b > 0)
    {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
ll dp[N][N];
void solve()
{
    int x;
    ll a1, b1, a2, b2;
    cin >> x >> a1 >> b1 >> a2 >> b2;
    ll p1 = a1 * fp(b1, mod - 2) % mod;
    ll np1 = (1 - p1 + mod) % mod;
    ll p2 = a2 * fp(b2, mod - 2) % mod;
    ll np2 = (1 - p2 + mod) % mod;
    ll num = ((p1 + p2) % mod - p1 * p2 % mod + mod) % mod;
    ll ny = fp(num, mod - 2);
    for (int i = 0; i < x; i++)
    {
        dp[i][x] = 1;
    }
    for (int i = x - 1; i >= 0; i--)
    {
        for (int j = x - 1; j >= 0; j--)
        {
            dp[i][j] = (dp[i][j] + (dp[i+1][j+1] * p1 % mod * p2 % mod)) % mod;
            dp[i][j] = (dp[i][j] + (dp[i+1][j] * p1 % mod * np2 % mod)) % mod;
            dp[i][j] = (dp[i][j] + (dp[i][j+1] * np1 % mod * p2 % mod)) % mod;
            dp[i][j] = dp[i][j] * ny % mod;
        }
    }
    cout << dp[0][0];
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