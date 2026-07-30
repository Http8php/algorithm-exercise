/*
知识点：悬线法

思路：悬线法模板题
注意要先把l, r维护出来，不然统计答案时l, r会变更导致WA

时间：O(nm)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char> >mp(n + 2, vector<char>(m + 2));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
        }
    }
    vector<vector<int> >u(n + 2, vector<int>(m + 2));
    vector<vector<int> >l(n + 2, vector<int>(m + 2));
    vector<vector<int> >r(n + 2, vector<int>(m + 2));
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mp[i][j] == 'F')
            {
                l[i][j] = l[i][j-1] + 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--)
        {
            if (mp[i][j] == 'F')
            {
                r[i][j] = r[i][j+1] + 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mp[i][j] == 'F')
            {
                u[i][j] = u[i-1][j] + 1;
                // 这里会改变l, r
                // 所以要提前维护，不能一边维护一边修改
                if (i > 1 && mp[i-1][j] == 'F')
                {
                    l[i][j] = min(l[i][j], l[i-1][j]);
                    r[i][j] = min(r[i][j], r[i-1][j]);
                }
                int cur = (l[i][j] + r[i][j] - 1) * u[i][j];
                mx = max(mx, cur);
            }
        }
    }
    cout << mx * 3;
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