/*
标签：贪心

思路：一旦有数量>=2的数，就把它和最大值合并，这样合并出来的数一定不重复
于是操作次数就是多余的数

时间：O(nlogn)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    map<int, int>mp;
    for (int i = 0, x; i < n; i++)
    {
        cin >> x;
        mp[x]++;
    }
    int ans = 0;
    for (auto [v, c] : mp)
    {
        ans += c - 1;
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