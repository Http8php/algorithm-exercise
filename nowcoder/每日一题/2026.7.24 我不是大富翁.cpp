/*
知识点：动态规划

小trick：(x % n + n) % n 保证是正数

思路：每次可以往两个方向移动，记录每回合可以到的地方，最后判断起点是否可达

时间：O(nm)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int>a(m + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
    }
    vector<int>dp(n);
    dp[0] = 1;
    for (int i = 1; i <= m; i++)
    {
        // 新回合可以到达的地方
        vector<int>ndp(n);
        for (int j = 0; j < n; j++)
        {
            if (dp[j])
            {
                // 顺时针转移 逆时针转移
                int r = (j + a[i]) % n;
                int l = ((j - a[i]) % n + n) % n;
                ndp[r] = ndp[l] = 1;
            }
        }
        dp = ndp;
    }
    cout << (dp[0] == 1 ? "Yes" : "No");
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