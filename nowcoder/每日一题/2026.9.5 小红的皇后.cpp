/*
标签：动态规划

思路：由于只能往右、右下、下三个方向走，没有回头路，相当于DAGdp
设dp[i][j][k]为以k方式走到(i, j)的最短步数
转移即从三个方向的最短步数+1，如果同方向最短则不用+1

时间：O(3nm)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2010;
char a[N][N];
int dp[N][N][3];
// 不可达不需要+1
int check(int x)
{
    return (x == 1e9 ? 1e9 : x + 1);
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            for (int k = 0; k < 3; k++)
            {
                dp[i][j][k] = 1e9;
            }
        }
    }
    dp[1][1][0] = dp[1][1][1] = dp[1][1][2] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == '*') continue;
            if (i == 1 && j == 1) continue;
            if (j > 1) dp[i][j][0] = min({dp[i][j-1][0], check(dp[i][j-1][1]), check(dp[i][j-1][2])});
            if (i > 1) dp[i][j][1] = min({dp[i-1][j][1], check(dp[i-1][j][0]), check(dp[i-1][j][2])});
            if (i > 1 && j > 1) dp[i][j][2] = min({dp[i-1][j-1][2], check(dp[i-1][j-1][0]), check(dp[i-1][j-1][1])});
        }
    }
    int ans = min({dp[n][m][0], dp[n][m][1], dp[n][m][2]});
    cout << (ans == 1e9 ? -1 : ans);
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