/*
知识点：构造

思路：要想让图形合法，先满足01约束
发现最少填 floor(n/2)*floor(m/2) 个，如果1或0小于这个数就不行
哪个数字多就用哪个当基底，接下来先填入必需，有多的塞入奇数列
由于只有1行或只有1列的情况没有2×2约束，不用特判

时间：O(nm)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    if (k < (n / 2) * (m / 2))
    {
        cout << "No\n";
        return;
    }
    if (k > n * m - (n / 2) * (m / 2))
    {
        cout << "No\n";
        return;
    }
    int c1 = k, c0 = n * m - k;
    if (c1 < c0)
    {
        vector<vector<int> >a(n + 1, vector<int>(m + 1));
        for (int i = 2; i <= n; i += 2)
        {
            for (int j = 2; j <= m; j += 2)
            {
                a[i][j] = 1;
                c1--;
            }
        }
        if (c1 == 0)
        {
            cout << "Yes\n";
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    cout << a[i][j];
                }
                cout << '\n';
            }
            return;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j += 2)
            {
                a[i][j] = 1;
                c1--;
                if (c1 == 0)
                {
                    cout << "Yes\n";
                    for (int i = 1; i <= n; i++)
                    {
                        for (int j = 1; j <= m; j++)
                        {
                            cout << a[i][j];
                        }
                        cout << '\n';
                    }
                    return;
                }
            }
        }
    }
    else
    {
        vector<vector<int> >a(n + 1, vector<int>(m + 1, 1));
        for (int i = 2; i <= n; i += 2)
        {
            for (int j = 2; j <= m; j += 2)
            {
                a[i][j] = 0;
                c0--;
            }
        }
        if (c0 == 0)
        {
            cout << "Yes\n";
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    cout << a[i][j];
                }
                cout << '\n';
            }
            return;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j += 2)
            {
                a[i][j] = 0;
                c0--;
                if (c0 == 0)
                {
                    cout << "Yes\n";
                    for (int i = 1; i <= n; i++)
                    {
                        for (int j = 1; j <= m; j++)
                        {
                            cout << a[i][j];
                        }
                        cout << '\n';
                    }
                    return;
                }
            }
        }
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