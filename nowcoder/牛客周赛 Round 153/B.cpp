/*
思路：按题意模拟

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        if (i == k) continue;
        cout << k << " " << i << '\n';
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