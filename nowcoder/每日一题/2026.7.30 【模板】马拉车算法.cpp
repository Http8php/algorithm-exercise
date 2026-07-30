/*
标签：manachar

思路：manachar模板题

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// 因为对字符串改造，需要两倍空间
const int N = 2e6 + 10;
string s, t;
int n, m, p[N], ans;
void build()
{
    t.push_back('$');
    t.push_back('#');
    for (int i = 0; i < n; i++)
    {
        t.push_back(s[i]);
        t.push_back('#');
    }
    m = t.length();
}
void mlc()
{
    int mid = 0, r = 0;
    for (int i = 2; i <= m; i++)
    {
        if (i <= r) p[i] = min(p[mid*2-i], r - i + 1);
        else p[i] = 1;
        while (i - p[i] >= 1 && i + p[i] <= m && t[i-p[i]] == t[i+p[i]]) p[i]++;
        if (i + p[i] - 1 > r)
        {
            mid = i;
            r = i + p[i] - 1;
        }
        ans = max(ans, p[i] - 1);
    }
}
void solve()
{
    cin >> s;
    n = s.length();
    build();
    mlc();
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