/*
知识点：动态规划/枚举

思路：先把输入转换成二进制
初始化：dp[a[i]] = 1
枚举所有w，若存在，转移：dp[w|a[i]] = min(dp[w|a[i]], dp[w] + 1)
答案即为所有位均存在情况：dp[(1<<n)-1]

时间：O(m * (1 << n))
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 0x3f3f3f3f3f3f3f3f;
void solve()
{
    int n, m;
	cin >> n >> m;
	vector<int>a(m);
	for (int i = 0, k, x; i < m; i++)
	{
        int mask = 0;
		cin >> k;
        while (k--)
        {
            cin >> x;
            x--;
            mask |= (1 << x);
        }
        a[i] = mask;
	}
	vector<ll>dp((1 << n), inf);
    dp[0] = 0;
	for (int i = 0; i < m; i++)
	{
		dp[a[i]] = 1;
	}
    for (int i = 0; i < m; i++)
    {
        for (int w = 0; w < (1 << n); w++)
        {
            if (dp[w] != inf)
            {
                dp[w|a[i]] = min(dp[w|a[i]], dp[w] + 1);
            }
        }
    }
	cout << (dp[(1<<n)-1] == inf ? -1 : dp[(1<<n)-1]);
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