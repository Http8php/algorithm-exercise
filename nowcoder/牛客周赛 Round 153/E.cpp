/*
知识点：枚举

思路：只有100个点，可以先枚举分界线，再枚举点
设l:y + kx - b = 0 代入(x0, y0) 若>0在上方，反之下方，=0不计数
上下点数量相等答案加1

时间：O(n^3)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<ll>x(n + 1), y(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int u = 0, d = 0;
            for (int k = 1; k <= n; k++)
            {
                if (k == i || k == j) continue;
                ll l = (x[j] - x[i]) * (y[k] - y[j]);
                ll r = (y[j] - y[i]) * (x[k] - x[j]);
                if (l > r) u++;
                else if (l < r) d++;
            }
            if (u == d) ans++;
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