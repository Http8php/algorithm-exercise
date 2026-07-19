/*
思路：如果一个数前有比它大的数，这个数对答案没有贡献
从左往右遍历，如果这个数是当前最大，答案加1

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int ans = 0, mx = 0;
    for (int i = 1; i <= n; i++)
    {
        mx = max(mx, a[i]);
        if (a[i] == mx) ans++;
    }
    cout << ans << '\n';
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