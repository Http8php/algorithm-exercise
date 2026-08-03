/*
思路：数据不大，直接暴力比较
枚举分割点，算出左边最小，右边最小，记录相加最小值

时间：O(15n^2)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int calc(string s, string t)
{
    int res = 1010, n = s.length();
    for (int i = 0; i <= 4; i++)
    {
        int cur = 0;
        string ns = s;
        for (int j = 0; j < n; j++)
        {
            ns[j] = 'A' + (((ns[j] - 'A') + i) % 5);
        }
        for (int j = 0; j < n; j++)
        {
            if (ns[j] != t[j]) cur++;
        }
        res = min(res, cur);
    }
    return res;
}
void solve()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int ans = calc(s, t);
    for (int c = 1; c < n; c++)
    {
        int l = calc(s.substr(0, c), t.substr(0, c));
        int r = calc(s.substr(c), t.substr(c));
        ans = min(ans, l + r);
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