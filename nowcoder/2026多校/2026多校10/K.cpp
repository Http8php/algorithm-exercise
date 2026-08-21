/*
标签：状压dp

思路：3n<=24，考虑状压dp，设dp[s]为已组好队的人的默契最大值
由于每次挑三个人组队会有大量重复，考虑优化
枚举状态数时，钦定编号最小的人，再选未选的编号大的两人组成一队进行转移
转移时，必须从可达状态进行转移，如果mask中的1不是3的倍数，就不可达
跳过不可达状态后，即使再加上两层for循环，时间复杂度也可以接受

时间：O((3n)^2 * 2^{3n})
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[25][25];
void solve()
{
    int n;
    cin >> n;
    n *= 3;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<ll>dp(1 << n, -1e18);
    dp[0] = 0;
    for (int mask = 0; mask < (1 << n); mask++)
    {
        if (dp[mask] == -1e18) continue;
        int i = __builtin_ctz(~mask);
        for (int j = i + 1; j < n; j++)
        {
            if (((mask >> j) & 1) == 0)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (((mask >> k) & 1) == 0)
                    {
                        int nmask = mask | (1 << i) | (1 << j) | (1 << k);
                        dp[nmask] = max(dp[nmask], dp[mask] + a[i][j] + a[j][k] + a[i][k]);
                    }
                }
            }
        }
    }
    cout << dp[(1<<n)-1];
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