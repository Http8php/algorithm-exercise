/*
思路：暴力地把G所在的-d+d处都填成G，最后统计.的个数

时间：O(m * 2d)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int m, d;
    string s, t;
    cin >> m >> d >> s;
    t = s;
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        if (s[i] == 'G')
        {
            // 注意填在新的串，如果填在老串上，新填的G也会扩展
            for (int l = i; l >= max(0, i - d); l--) t[l] = 'G';
            for (int r = i; r <= min(m, i + d); r++) t[r] = 'G';
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (t[i] == '.') ans++;
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