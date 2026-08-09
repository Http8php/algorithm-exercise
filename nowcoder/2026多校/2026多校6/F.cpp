/*
标签：Z函数、拓扑序计数、状压dp

思路：从定义入手，一个串的字典序要小于它的后缀，只要约束第一个不同的字母即可
比如abcabd，后缀abd>abcabd只要d>c
快速获得约束关系用Z算法O(n)求得
只要s[i...n-1]等于前缀，任何约束都不能满足条件，此时无解
获得所有约束关系后，计算所有的拓扑序，就是答案

时间：O(n + 2^26 * 26)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    vector<int>z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++)
    {
        if (z[i-l] < r - i + 1) z[i] = z[i-l];
        else
        {
            z[i] = max(r - i + 1, 0);
            while (i + z[i] < n && s[z[i]] == s[i+z[i]]) z[i]++;
            l = i, r = i + z[i] - 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (z[i] == n - i)
        {
            cout << 0;
            return;
        }
    }
    vector<vector<int> >g(26);
    for (int i = 0; i < n; i++)
    {
        g[s[i+z[i]]-'a'].push_back(s[z[i]]-'a');
    }
    vector<int>pre(26);
    for (int i = 0; i < 26; i++)
    {
        int mask = 0;
        for (int j : g[i])
        {
            mask |= (1 << j);
        }
        pre[i] = mask;
    }
    vector<unsigned int>dp(1 << 26);
    dp[0] = 1;
    for (int i = 0; i < (1 << 26); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if ((i >> j) & 1)
            {
                if ((i & pre[j]) == pre[j])
                {
                    dp[i] += dp[i^(1<<j)];
                }
            }
        }
    }
    cout << dp[(1<<26)-1];
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