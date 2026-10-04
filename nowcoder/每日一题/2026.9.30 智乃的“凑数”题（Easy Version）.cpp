/*
标签：动态规划、方案输出

思路：首先考虑拆式子，把与j无关的ai放到外面，变成ΣaiΣaj
即把集合中的一些数分别放在a、b中，val就是a的和sa乘b的和sb

设dp[i][j]为sa=i,sb=j时放入的最后一个数，用正负区分行列，便于回溯方案
接下来就是01二维背包，每来一个数x，i,j从mx遍历到0，如果dp[i][j]!=0，进行转移
dp[i+x][j]=x (i+x<=mx, dp[i+x][j]==0)，如果dp[i+x][j]!=0，会重复使用数字
dp[i][j+x]=-x (j+x<=mx, dp[i][j+x]==0)

如果dp[i][j]!=0，说明该状态可达，val=i*j，保存i,j的值
输出时，如果val可达，就根据dp把方案回溯即可

时间：O(n*mx^2)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 110, mx = 100;
int dp[N][N];
vector<pair<int, int> >res(mx + 1);
void solve()
{
    int n, m;
    cin >> n >> m;
    dp[0][0] = 1;
    while (n--)
    {
        int x;
        cin >> x;
        for (int i = mx; i >= 0; i--)
        {
            for (int j = mx; j >= 0; j--)
            {
                if (dp[i][j])
                {
                    int ni = i + x;
                    int nj = j + x;
                    if (ni <= mx && !dp[ni][j]) dp[ni][j] = x;
                    if (nj <= mx && !dp[i][nj]) dp[i][nj] = -x;
                }
            }
        }
    }
    for (int i = 1; i <= mx; i++)
    {
        for (int j = 1; j <= mx; j++)
        {
            if (dp[i][j])
            {
                int v = i * j;
                if (v <= mx) res[v] = {i, j};
            }
        }
    }
    while (m--)
    {
        int x;
        cin >> x;
        auto [sa, sb] = res[x];
        if (sa == 0 || sb == 0)
        {
            cout << "No\n";
            continue;
        }
        vector<int>a, b;
        // 回溯方案
        while (sa || sb)
        {
            int p = dp[sa][sb];
            if (p > 0)
            {
                sa -= p;
                a.push_back(p);
            }
            else
            {
                sb += p;
                b.push_back(-p);
            }
        }
        cout << "Yes\n";
        cout << a.size() << " " << b.size() << '\n';
        for (int v : a)
        {
            cout << v << " ";
        }
        cout << '\n';
        for (int v : b)
        {
            cout << v << " ";
        }
        cout << '\n';
    }
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