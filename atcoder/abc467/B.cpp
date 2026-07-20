/*
思路：出现keep把 b - a 统计到答案里

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 0, a, b; i < n; i++)
    {
        string s;
        cin >> a >> b >> s;
        if (s == "keep")
        {
            ans += b - a;
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