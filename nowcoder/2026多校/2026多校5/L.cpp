/*
标签：递推

思路：需要注意到可以直接算出路径数量，设有k条路径，总和为sum
sum + k * (n + m - 1) = (a[1][1] + k) * n * m
只有k一个未知量，直接解方程
接下来就是判断k条路径合不合法
每个格子可以向下和向右，通过行列约束可以递推下去，在代码中具体体现

时间：O(mn)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<ll> >a(n + 1, vector<ll>(m + 1));
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            sum += a[i][j];
        }
    }
    // 特判只有一行或一列的情况
    if (n == 1 && m == 1)
    {
        cout << 0 << '\n';
        return;
    }
    // 每条路径必经过起点和终点，这两个点必须相等
    if (a[1][1] != a[n][m])
    {
        cout << -1 << '\n';
        return;
    }
    // 一行一列必须每个格子都一样
    if (n == 1)
    {
        bool ok = true;
        for (int j = 2; j <= m; j++)
        {
            if (a[1][j] != a[1][j-1]) ok = false;
        }
        cout << (ok ? 0 : -1) << '\n';
        return;
    }
    if (m == 1)
    {
        bool ok = true;
        for (int i = 2; i <= n; i++)
        {
            if (a[i][1] != a[i-1][1]) ok = false;
        }
        cout << (ok ? 0 : -1) << '\n';
        return;
    }
    ll n1 = sum - m * n * a[1][1];
    ll n2 = m * n - n - m + 1;
    if (n1 % n2 != 0)
    {
        cout << -1 << '\n';
        return;
    }
    ll k = n1 / n2;
    if (k < 0)
    {
        cout << -1 << '\n';
        return;
    }
    ll e = k + a[1][1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // 此时a代表一格一共有多少流量
            a[i][j] = e - a[i][j];
            // 流量不能为负，即不能减少
            if (a[i][j] < 0)
            {
                cout << -1 << '\n';
                return;
            }
        }
    }
    // 每个格子分配的向右 向下的流量
    // 满足 a[i][j] = r[j] + d[j]
    vector<ll>r(m + 1), d(m + 1);
    bool ok = true;
    // 第一行特殊处理，没有从上面来的流量，向右的流量就固定了
    for (int j = 1; j < m; j++)
    {
        r[j] = a[1][j+1];
        // 从而推出向下的流量
        d[j] = a[1][j] - r[j];
        if (d[j] < 0) ok = false;
    }
    // 最后一列只有向下的
    d[m] = a[1][m];
    for (int i = 2; ok && i <= n; i++)
    {
        // 滚动数组 当前行向右的流量
        vector<ll>cr(m + 1);
        for (int j = 1; j < m; j++)
        {
            // 右边格子上面的流量已知，剩余的就是左边格子向右的流量
            cr[j] = a[i][j+1] - d[j+1];
            if (cr[j] < 0 || cr[j] > a[i][j]) ok = false;
        }
        // 第一列没有左边来的，必须等于上面来的
        if (a[i][1] != d[1]) ok = false;
        if (i == n)
        {
            for (int j = 1; ok && j < m; j++)
            {
                // 最后一行不能向下了，所有流量必须向右
                if (cr[j] != a[i][j]) ok = false;
            }
        }
        for (int j = 1; j <= m; j++)
        {
            d[j] = a[i][j] - cr[j];
            r[j] = cr[j];
        }
    }
    cout << (ok ? k : -1) << '\n';
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