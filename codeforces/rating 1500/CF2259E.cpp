/*
标签：差分、前缀和

思路：每一个没模糊的数，都会提供一个限制范围，这个范围内不能有宝藏
对所有限制区间作差分，如果数是-1或0说明没有限制，直接跳过
如果限制区间整段长度大于n，不可能满足要求

把差分用前缀和还原，如果数字大于0，说明这里不能有宝藏
再次检查非-1的每个点，距每个位置ai处必须至少有一处宝藏
都没有问题，就输出方案，数字>0不埋宝藏，反之则埋

单组时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n + 1), d(n + 2);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == -1 || a[i] == 0) continue;
        int l = i - a[i] + 1;
        int r = i + a[i] - 1;
        if (l < 1 && r > n)
        {
            cout << -1 << '\n';
            return;
        }
        l = max(1, l);
        r = min(n, r);
        d[l]++, d[r+1]--;
    }
    for (int i = 1; i <= n; i++)
    {
        d[i] += d[i-1];
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == -1) continue;
        if (a[i] == 0)
        {
            if (d[i])
            {
                cout << -1 << '\n';
                return;
            }
            else continue;
        }
        int l = max(1, i - a[i]);
        int r = min(n, i + a[i]);
        if (d[l] && d[r])
        {
            cout << -1 << '\n';
            return;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << (d[i] ? 0 : 1);
    }
    cout << '\n';
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