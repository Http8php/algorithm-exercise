/*
思路：由于保证有 n/2 个棋子，只有从左往右全摆在所有奇数、偶数位上

时间：O(nlogn)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n / 2 + 1);
    for (int i = 1; i <= n / 2; i++)
    {
        cin >> a[i];
    }
    // 记得排序
    sort(a.begin() + 1, a.end());
    int ans = 1e9, id = 1, cur = 0;
    for (int i = 1; i <= n; i += 2)
    {
        cur += abs(a[id++] - i);
    }
    ans = min(ans, cur);
    id = 1, cur = 0;
    for (int i = 2; i <= n; i += 2)
    {
        cur += abs(a[id++] - i);
    }
    ans = min(ans, cur);
    cout << ans;
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