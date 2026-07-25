/*
知识点：动态规划

思路：状态：dp[i][j] 代表前i个数取k个数合法的数量
初始化：dp[1][1] = 1 代表序列[1]
转移：从当前i的因子转移，相当于把i填入之前序列的后面

时间：O(n^2logn)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<ll> >dp(n + 1, vector<ll>(k + 1));
    for (int i = 1; i <= n; i++) dp[i][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        // 收集因子
        vector<int>num;
        for (int k = 1; k * k <= i; k++)
        {
            if (i % k == 0) num.push_back(k);
            else continue;
            if (i / k != k) num.push_back(i / k);
        }
        for (int j = 1; j <= k; j++)
        {
            for (int v : num)
            {
                dp[i][j] = (dp[i][j] + dp[v][j-1]) % mod;
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = (ans + dp[i][k]) % mod;
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