/*
标签：博弈，动态规划

小trick：dp时把数转换成+1-1，条件转换成判前缀和

思路：题目大意是对方每出一个数，我方都要有比对方小的数
由于对面有剩余所有数，我方的数必须全部落在2n内，否则必输
若给定的m个数合法，考虑n^2dp，设dp[i][j]表示前i个数的前缀和为j
我方选数转换成+1，对方选数转换成-1，合法情况即为最后前缀和=0
dp[i][j]=dp[i-1][j-1], 这个数是固定的数
dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1], 这个数不是固定的数 选/不选
空间较大，可以用滚动数组优化

单组时间：O(4n^2)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;
void solve()
{
    int n, m;
    cin >> n >> m;
    int r = (n << 1);
    vector<int>a(m), num(r + 1);
    bool ok = true;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
        if (a[i] > r) ok = false;
    }
    if (!ok)
    {
        cout << 0 << '\n';
        return;
    }
    for (int x : a)
    {
        num[x] = 1;
    }
    vector<int>dp(r + 1);
    dp[0] = 1;
    for (int i = 1; i <= r; i++)
    {
        auto ndp = dp;
        for (int j = 0; j <= r; j++)
        {
            if (num[i]) ndp[j] = dp[j-1];
            else ndp[j] = dp[j-1] + dp[j+1];
            if (ndp[j] >= mod) ndp[j] -= mod;
        }
        dp = ndp;
    }
    cout << dp[0] << '\n';
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