/*
思路：要让颜色相同，每次操作后要改颜色，不难发现就是交替的次数

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    string s;
    cin >> s;
    int n = s.length(), ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] != s[i+1]) ans++;
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