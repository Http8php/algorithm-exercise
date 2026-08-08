/*
思路：需要注意到f(x)就是统计相邻的"10"段，相邻段只有"10""11""01""00"四种情况
每次进行操作时，相邻的对会相应做出改变
可以单独维护四种情况，答案就是每个位上"10"段数量

时间：O(120 * m)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int cnt[31][2][2];
void solve()
{
    int n, m;
    cin >> n;
    vector<int>a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            int p = ((a[i] >> j) & 1), q = ((a[i] >> (j + 1)) & 1);
            cnt[j][p][q]++;
        }
    }
    cin >> m;
    while (m--)
    {
        int op, x;
        cin >> op >> x;
        for (int i = 0; i < 30; i++)
        {
            int p = ((x >> i) & 1), q = ((x >> (i + 1)) & 1);
            // 用静态数组，开销小
            int ncnt[2][2] = {0};
            for (int l = 0; l <= 1; l++)
            {
                for (int r = 0; r <= 1; r++)
                {
                    int np, nq;
                    if (op == 1)
                    {
                        np = l & p;
                        nq = r & q;
                    }
                    else if (op == 2)
                    {
                        np = l | p;
                        nq = r | q;
                    }
                    else
                    {
                        np = l ^ p;
                        nq = r ^ q;
                    }
                    ncnt[np][nq] += cnt[i][l][r];
                }
            }
            for (int l = 0; l <= 1; l++)
            {
                for (int r = 0; r <= 1; r++)
                {
                    cnt[i][l][r] = ncnt[l][r];
                }
            }
        }
        ll ans = 0;
        for (int i = 0; i < 30; i++)
        {
            ans += cnt[i][1][0];
        }
        cout << ans << '\n';
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