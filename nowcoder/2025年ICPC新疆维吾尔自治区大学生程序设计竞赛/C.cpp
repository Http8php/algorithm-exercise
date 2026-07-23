/*
知识点：动态规划

思路：dp[i] = dp[j] * f(a[i] & a[j]) j属于[1, i-1]，f是二进制位1个数
f(a[i] & a[j]) 是依次看30位二进制位，如果a[i]a[j]在这个位置均为1，路径加1
转移时，如果dp[i]在这位上为1，对答案才有贡献
贡献在转移时维护，把所有为1位置加入当前dp[i]

时间：O(30 * n)

*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    // 贡献前缀和
    vector<ll>cnt(30), dp(n + 1);
    dp[1] = 1;
    int cur = 0;
    while (a[1] > 0)
    {
        if (a[1] & 1) cnt[cur]++;
        a[1] >>= 1;
        cur++;
    }
    for (int i = 1; i <= n; i++)
    {
        vector<int>pos;
        int x = a[i];
        cur = 0;
        while (x > 0)
        {
            if (x & 1)
            {
                pos.push_back(cur);
                dp[i] = (dp[i] + cnt[cur]) % mod;
            }
            x >>= 1;
            cur++;
        }
        // 维护前缀和
        for (int v : pos)
        {
            cnt[v] = (cnt[v] + dp[i]) % mod;
        }
    }
    cout << dp[n] << '\n';
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