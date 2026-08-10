/*
标签：状压dp

思路：不能有两列相同，且只有8种状态，于是>8列就无解
由于状态数少，考虑状压dp
预处理出每列可以填的方案，如果这个方案之前没用过，就可以转移

时间：O(256nm) m为可行方案数
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<string>s(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> s[i];
    }
    if (n > 8)
    {
        cout << 0;
        return;
    }
    vector<vector<int> >op(n);
    for (int i = 0; i < n; i++)
    {
        for (int w = 0; w < 8; w++)
        {
            bool ok = true;
            if (s[0][i] != '?' && (s[0][i] - '0') != (w & 1)) ok = false;
            if (s[1][i] != '?' && (s[1][i] - '0') != ((w >> 1) & 1)) ok = false;
            if (s[2][i] != '?' && (s[2][i] - '0') != ((w >> 2) & 1)) ok = false;
            if (ok) op[i].push_back(w);
        }
    }
    vector<int>dp(1 << 8);
    dp[0] = 1;
    for (int j = 0; j < n; j++)
    {
        vector<int>ndp(1 << 8);
        for (int i = 0; i < (1 << 8); i++)
        {
            if (dp[i] == 0) continue;
            for (int w : op[j])
            {
                if (((i >> w) & 1) == 0)
                {
                    ndp[i|(1<<w)] += dp[i];
                }
            }
        }
        dp = ndp;
    }
    ll ans = 0;
    for (ll x : dp)
    {
        ans += x;
    }
    cout << ans << '\n';
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