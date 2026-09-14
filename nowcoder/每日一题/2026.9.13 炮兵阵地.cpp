/*
标签：状压dp

思路：考虑dp，列数不多可以状压
设dp[i][j][k]为填到i-2行，i行状态掩码为j，i-1行状态掩码为k的最大方案数
由于每一行的炮兵间隔>2，预先处理出所有能填的情况，掩码1代表当前位有炮兵
并处理出地图的掩码，1代表不能填炮兵
转移从当前行与地图不冲突的状态开始，比较三行内无冲突的所有填法中最大的那一种进行转移

时间：O(mn + 2^m + n*sz^3)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = (1 << 10) + 10;
ll dp[110][N][N];
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int>mp(n);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int mask = 0;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == 'H') mask |= (1 << j);
        }
        mp[i] = mask;
    }
    vector<int>st;
    for (int i = 0; i < (1 << m); i++)
    {
        if ((i & (i << 1)) == 0 && (i & (i << 2)) == 0)
        {
            st.push_back(i);
        }
    }
    int sz = st.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < sz; j++)
        {
            int mask = st[j];
            if (mask & mp[i]) continue;
            int num = __builtin_popcount(mask);
            for (int c1 = 0; c1 < sz; c1++)
            {
                int m1 = st[c1];
                if (m1 & mask) continue;
                for (int c2 = 0; c2 < sz; c2++)
                {
                    int m2 = st[c2];
                    if (m2 & mask || m1 & m2) continue;
                    dp[i+2][mask][m1] = max(dp[i+2][mask][m1], dp[i+1][m1][m2] + num);
                }
            }
        }
    }
    ll ans = 0;
    for (int c1 = 0; c1 < sz; c1++)
    {
        int m1 = st[c1];
        for (int c2 = 0; c2 < sz; c2++)
        {
            int m2 = st[c2];
            ans = max(ans, dp[n+1][m1][m2]);
        }
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