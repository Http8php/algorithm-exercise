/*
知识点：构造

思路：要想让图形合法，先满足01约束
发现最少填 floor(n/2)*floor(m/2) 个，此时连通块也是这个数量
需要特判只有1行或只有1列的情况，由于没有限制，k=0也合法，最多是交替串
最多是所有都为大小为1的连通块，如果k大于最大或等于0，直接No
如果k小于当前，第二行1中间先填满，再填偶数列1中间，这样保证填一个连通块数量少一个
如果k大于当前，奇数行奇数列填，这样保证填一个连通块数量多一个

时间：O(nm)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int mn = (n / 2) * (m / 2);
    int mx = (n - n / 2) * (m - m / 2) + mn;
    vector<vector<int> >a(n + 1, vector<int>(m + 1));
    if (n == 1 || m == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = (i % 2 ? 1 : 2); j <= m; j += 2)
            {
                if (k)
                {
                    a[i][j] = 1;
                    k--;
                }
            }
        }
        if (k)
        {
            cout << "No\n";
            return;
        }
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
    if (k > mx || k == 0)
    {
        cout << "No\n";
        return;
    }
    for (int i = 2; i <= n; i += 2)
    {
        for (int j = 2; j <= m; j += 2)
        {
            a[i][j] = 1;
        }
    }
    if (k <= mn)
    {
        int nk = mn - k;
        for (int j = 3; j < m; j += 2)
        {
            if (nk)
            {
                a[2][j] = 1;
                nk--;
            }
        }
        for (int i = 3; i < n; i += 2)
        {
            for (int j = 2; j <= m; j += 2)
            {
                if (nk)
                {
                    a[i][j] = 1;
                    nk--;
                }
            }
        }
        cout << "Yes\n";
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cout << a[i][j];
            }
            cout << '\n';
        }
    }
    else
    {
        int nk = k - mn;
        for (int i = 1; i <= n; i += 2)
        {
            for (int j = 1; j <= m; j += 2)
            {
                if (nk)
                {
                    a[i][j] = 1;
                    nk--;
                }
            }
        }
        cout << "Yes\n";
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cout << a[i][j];
            }
            cout << '\n';
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