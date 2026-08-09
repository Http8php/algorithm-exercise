/*
标签：动态规划

思路：为了使划分的区间尽可能多，每个数考虑离它最近的不互质数
预处理出每个数左右两边最近的不互质数距离l,r，设dp[i]为前i-1个数最多划出几段
固定右端点i，枚举左端点j，维护最左允许起点cl，如果cl>=j，则可以转移

时间：O(n^2)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    // 预处理
    vector<int>l(n + 1, 0), r(n + 1, n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i - 1; j > 0; j--)
        {
            if (gcd(a[i], a[j]) > 1)
            {
                l[i] = j;
                break;
            }
        }
        for (int j = i + 1; j <= n; j++)
        {
            if (gcd(a[i], a[j]) > 1)
            {
                r[i] = j;
                break;
            }
        }
    }
    vector<int>dp(n + 2, -1);
    dp[0] = dp[1] = 0;
    for (int i = 2; i <= n + 1; i++)
    {
        int cl = i;
        // 当区间左右端点均为 i-1 时
        // 因为 r[j]>j=i-1，一定有 r[j]>=i
        // cl会更新，不可能>=j，不会转移，排除了长度为1的区间
        for (int j = i - 1; j > 0; j--)
        {
            // 右侧合法数不在当前区间
            if (r[j] >= i)
            {
                // 尝试让左侧合法数在当前区间
                cl = min(cl, l[j]);
            }
            if (cl >= j && dp[j] != -1)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    cout << dp[n+1];
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