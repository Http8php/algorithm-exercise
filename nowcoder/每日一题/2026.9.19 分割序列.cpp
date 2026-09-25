/*
思路：相当于把0分配给1，如果没有1就是0种方案
只有两个1之间的0是可以任意选择的，可以分配给左边或右边
其余情况只能固定选择，对答案没有贡献
有几个0就有几种方案，把所有在1间连续的0数量相乘即可

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    s = " " + s;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '1') cnt++;
    }
    if (cnt < 2)
    {
        cout << cnt;
        return;
    }
    ll ans = 1, sum = 1;
    bool ok = false;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '1')
        {
            if (!ok)
            {
                ok = true;
                sum = 1;
            }
            else
            {
                ans = ans * sum % mod;
                sum = 1;
            }
        }
        else sum++;
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