/*
思路：点很多，但是点的状态很少，考虑枚举状态
对于相同的状态，对数为{cnt}C{2}，不同的状态，则是数量相乘

时间：O(nm + 2^{2m})
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll>cnt(1 << m);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int mask = 0;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '1') mask |= (1 << j);
        }
        cnt[mask]++;
    }
    ll ans = 0;
    for (int i = 0; i < (1 << m); i++)
    {
        if (cnt[i] > 1)
        {
            ans += cnt[i] * (cnt[i] - 1) / 2;
        }
        for (int j = i + 1; j < (1 << m); j++)
        {
            // 只要 i&j 不为0，一定有相同位置的1
            if (i & j) ans += cnt[i] * cnt[j];
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