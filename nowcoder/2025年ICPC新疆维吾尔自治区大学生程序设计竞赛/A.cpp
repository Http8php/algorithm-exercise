/*
知识点：枚举

思路：分别枚举a, b能增加的数量，如果成本<p，放入set中去重

时间：O((p^2/xy)log(p^2/xy))
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int a, b, x, y, p;
    cin >> a >> b >> x >> y >> p;
    set<int>ans;
    for (int da = 0; da <= (p + x - 1) / x; da++)
    {
        for (int db = 0; ; db++)
        {
            if (da * x + db * y > p) break;
            int na = a + da;
            int nb = b + db;
            ans.insert(na * nb);
        }
    }
    cout << ans.size();
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