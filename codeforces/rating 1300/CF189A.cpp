/*
知识点：背包

思路：处理出每条缎带可以装的数量01背包求解即可
似乎写麻烦了，实际上是完全背包

时间：O(3 * n^2)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 0x3f3f3f3f;
void solve()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int>w[3];
    for (int k = 1; k <= (n + a - 1) / a; k++)
    {
        w[0].push_back(k * a);
    }
    for (int k = 1; k <= (n + b - 1) / b; k++)
    {
        w[1].push_back(k * b);
    }
    for (int k = 1; k <= (n + c - 1) / c; k++)
    {
        w[2].push_back(k * c);
    }
    vector<int>dp(n + 1, -inf);
    dp[0] = 0;
    for (int k = 0; k < 3; k++)
    {
        for (int x : w[k])
        {
            for (int j = n; j >= x; j--)
            {
                if (dp[j-x] != -inf)
                {
                    int cnt = 0;
                    if (k == 0) cnt = x / a;
                    else if (k == 1) cnt = x / b;
                    else cnt = x / c;
                    dp[j] = max(dp[j], dp[j-x] + cnt);
                }
            }
        }
    }
    cout << dp[n];
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