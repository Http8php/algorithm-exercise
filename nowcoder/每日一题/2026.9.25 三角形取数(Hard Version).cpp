/*
标签：动态规划

思路：先不考虑k，就是经典的数字金字塔
从上到下，每个位置可以向左下、下、右下转移，记录每个位置的最大值
当k为0时，向左向右的次数相同，只能在中间
k为1，可以多一次左或右，能走到的范围左右拓展了两格
于是在[n-k, n+k]中取得最终答案

时间：O(n^2)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mp[310][610], dp[310][610];
void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= (i << 1) - 1; j++)
        {
            // 储存时加上n-i的偏移量，方便转移
            cin >> mp[i][n+j-i];
            // 注意数据有负数
            dp[i][n+j-i] = -1e18;
        }
    }
    dp[1][n] = mp[1][n];
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= (i << 1) - 1; j++)
        {
            int cur = n + j - i;
            ll x = dp[i][cur];
            dp[i+1][cur] = max(dp[i+1][cur], x + mp[i+1][cur]);
            dp[i+1][cur-1] = max(dp[i+1][cur-1], x + mp[i+1][cur-1]);
            dp[i+1][cur+1] = max(dp[i+1][cur+1], x + mp[i+1][cur+1]);
        }
    }
    ll ans = -1e18;
    for (int i = max(1, n - k); i <= min(2 * n - 1, n + k); i++)
    {
        ans = max(ans, dp[n][i]);
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