/*
标签：分类讨论

思路：报的数如果不一样，一定只有众数和众数-1，不在这个范围一定不对
必须满足mx+cnt(mx)=n
如果报的数x都一样，要么有多个众数，要么都是一种颜色
多个众数要保证x*2<=n，一种颜色保证x=n-1

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, mx = 0, mn = 1e9;
    cin >> n;
    vector<int>a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (mx == a[i]) cnt++;
    }
    if (mx - mn >= 2)
    {
        cout << "Lie\n";
    }
    else
    {
        if (mn == mx)
        {
            if (mn * 2 <= n || mn == n - 1)
            {
                cout << "Other\n";
                return;
            }
        }
        else
        {
            if (mx + cnt == n)
            {
                cout << "Other\n";
                return;
            }
        }
        cout << "Lie\n";
    }
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