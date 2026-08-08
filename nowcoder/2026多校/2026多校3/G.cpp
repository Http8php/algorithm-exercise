/*
知识点：二维差分

思路：如果暴力维护矩形，由于点很多，会超时
由于不同点之间不会相互干扰，可以单独处理一种点
假设我们在i行，1~i的左界如果小于i+1~n的右界，则有一个矩形可以被标记
于是维护左界最小值和右界最大值，对于没有这个点的行，可以跳过
从最靠左上角的点开始，两行两行处理，如果左界最小值小于右界最大值，差分标记矩形
最后前缀和复原，输出答案

时间：O(nmlogK + nK) K为数值数量
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    map<int, vector<pair<int, int> > >pos;
    for (int i = 1, x; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> x;
            pos[x].push_back({i, j});
        }
    }
    vector<vector<int> >d(n + 2, vector<int>(m + 2));
    // 单独处理每个点
    for (auto [num, v] : pos)
    {
        if (v.size() < 2) continue;
        // 前缀最小值 后缀最大值
        vector<int>mn(n + 1, m + 1), mx(n + 2);
        for (auto [x, y] : v)
        {
            mn[x] = min(mn[x], y);
            mx[x] = max(mx[x], y);
        }
        // 收集出现点的行
        vector<int>r;
        for (int i = 1; i <= n; i++)
        {
            if (mn[i] != m + 1) r.push_back(i);
        }
        for (int i = 1; i <= n; i++)
        {
            mn[i] = min(mn[i], mn[i-1]);
        }
        for (int i = n; i >= 1; i--)
        {
            mx[i] = max(mx[i], mx[i+1]);
        }
        int sz = r.size();
        for (int i = 0; i < sz - 1; i++)
        {
            int r1 = r[i];
            int r2 = r[i+1];
            int L = mn[r1];
            int R = mx[r2];
            // 条件成立，矩形存在
            if (L < R)
            {
                d[r1][L]++;
                d[r1][R+1]--;
                d[r2+1][L]--;
                d[r2+1][R+1]++;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            d[i][j] += d[i-1][j] + d[i][j-1] - d[i-1][j-1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (d[i][j] > 0) cout << 1;
            else cout << 0;
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