/*
标签：SOSDP

思路：定义 f[S] 表示：已经将集合S中的测试安排了顺序，运行完所有这些测试所需的最小总时间
考虑S中最后被安排的测试i，要运行i时，已花费时间为f[S∖{i}]，只有S\{i}中的测试点都过了，才会开始i
记 T[U,i] 为所有通过了集合U中全部测试的程序在i上的运行时间总和
f[S]=min{f[S∖{i}]+T[S∖{i},i]} (i∈S)

难点是如何快速计算T
对于每个程序x的通过测试点集合P，可以用二进制mask描述，时间 t[mask]=Σd_{x, i}，d为题中x程序跑i测试点所耗时间
T即为所有U的超集mask之和，T[U,i]=Σt[mask]，使用SOSDP处理超集和

时间：O(mn + m^2 * 2^m)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 0x3f3f3f3f3f3f3f3f;
// T[i,U] 内存连续，常数小
ll T[25][1<<20];
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        vector<ll>d(m);
        for (int j = 0; j < m; j++)
        {
            cin >> d[j];
        }
        string s;
        cin >> s;
        int mask = 0;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == 'A') mask |= (1 << j);
        }
        for (int j = 0; j < m; j++)
        {
            T[j][mask] += d[j];
        }
    }
    // SOSDP
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < m; i++)
        {
            for (int mask = 0; mask < (1 << m); mask++)
            {
                if (((mask >> i) & 1) == 0) T[j][mask] += T[j][mask|(1<<i)];
            }
        }
    }
    // 即思路中的f[S]
    vector<ll>dp(1 << m, inf);
    dp[0] = 0;
    for (int i = 0; i < (1 << m); i++)
    {
        for (int j = 0; j < m; j++)
        {
            // 枚举当前集合最后运行的程序
            if ((i >> j) & 1)
            {
                int mask = i ^ (1 << j);
                dp[i] = min(dp[i], dp[mask] + T[j][mask]);
            }
        }
    }
    cout << dp[(1<<m)-1];
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