/*
思路：x%2^k，如果k位以下的数都是0，这个表达式就是0
所以就是记录所有数中2的因子数量

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 0, x; i < n; i++)
    {
        cin >> x;
        while ((x & 1) == 0)
        {
            x >>= 1;
            ans++;
        }
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