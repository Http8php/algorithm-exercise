/*
思路：先统计所有灯开了几次，如果某一个开关的"1"是这个位置的唯一一个"1"，这个开关是关键开关

时间：O(nm)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string>a(n + 1);
    vector<int>cnt(m + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '1') cnt[j]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        bool ok = true;
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '1' && cnt[j] == 1) ok = false;
        }
        if (ok)
        {
            cout << "YES";
            return;
        }
    }
    cout << "NO";
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