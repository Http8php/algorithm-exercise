#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<vector<int> >g(n);
    for (int i = 0; i < n; i++)
    {
        //g[].push_back();
    }
    vector<int>pre(n);
    for (int i = 0; i < n; i++)
    {
        int mask = 0;
        for (int j : g[i])
        {
            mask |= (1 << j);
        }
        pre[i] = mask;
    }
    vector<ll>dp(1 << n);
    dp[0] = 1;
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
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
}