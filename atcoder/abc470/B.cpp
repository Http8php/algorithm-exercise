/*
标签：贪心

思路：把数全部变成众数一定最优

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int>cnt(n + 1);
    int mx = 0;
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        cnt[x]++;
        mx = max(mx, cnt[x]);
    }
    cout << n - mx;
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