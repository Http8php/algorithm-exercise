/*
标签：差分，离散化

思路：差分后统计每一个结界两端覆盖结界差值
但是值域为1e9，要用map实现离散化

时间：O(nlogn)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, p;
    cin >> n >> p;
    vector<pair<int, int> >a(n);
    map<int, int>mp;
    for (int i = 0, x, y; i < n; i++)
    {
        cin >> x >> y;
        a[i] = {x, y};
        mp[x]++;
        mp[y];
        mp[y+1]--;
    }
    int sum = 0;
    for (auto &[x, c] : mp)
    {
        sum += c;
        c = sum;
    }
    int ans = 0;
    for (auto [x, y] : a)
    {
        if (abs(mp[x] - mp[y]) >= p) ans++;
    }
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