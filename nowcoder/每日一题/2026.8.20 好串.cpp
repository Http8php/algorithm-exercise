/*
思路：最优的情况是一开始就有3个以上好串，修改次数0
次优的情况是形如100001，只需改1次
其他情况直接枚举所有4个位置，填1010或0101，统计最小答案

单组时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int ans = 4, cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == '0' && s[i+1] == '1') cnt++;
        if (s[i] == '1' && s[i+1] == '0') cnt++;
    }
    if (cnt >= 3)
    {
        cout << 0 << '\n';
        return;
    }
    if (cnt == 2 && n > 4)
    {
        cout << 1 << '\n';
        return;
    }
    for (int i = 0; i <= n - 4; i++)
    {
        int c1 = 0, c2 = 0;
        for (int j = i; j < i + 4; j++)
        {
            if ((j - i) & 1 && s[j] != '1') c1++;
            if (((j - i) & 1) == 0 && s[j] != '0') c1++;
        }
        for (int j = i; j < i + 4; j++)
        {
            if ((j - i) & 1 && s[j] != '0') c2++;
            if (((j - i) & 1) == 0 && s[j] != '1') c2++;
        }
        ans = min({ans, c1, c2});
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}