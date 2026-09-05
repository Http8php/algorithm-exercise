#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;
int n, digit, num[20];
ll dp[20][20][2][2];
ll dfs(int p, int st, bool lim, bool lead)
{
	if (p == n)
	{
		return st;
	}
	if (dp[p][st][lim][lead] != -1)
	{
		return dp[p][st][lim][lead];
	}
	ll res = 0;
	int mx = lim ? num[p] : 9;
	for (int i = 0; i <= mx; i++)
	{
		if (lead && i == 0)
        {
            res += dfs(p + 1, st, lim && i == num[p], true);
        }
        else
        {
            res += dfs(p + 1, st + (i == digit), lim && i == num[p], false);
        }
	}
	dp[p][st][lim][lead] = res;
	return res;
}
ll f(ll x)
{
    n = 0;
    memset(dp, -1, sizeof(dp));
    memset(num, 0, sizeof(num));
    while (x)
    {
        num[n++] = x % 10;
        x /= 10;
    }
    reverse(num, num + n);
    return dfs(0, 0, true, true);
}