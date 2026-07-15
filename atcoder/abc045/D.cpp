/*
知识点：枚举

思路：首先发现棋盘很大，无法开数组，但是棋子很少
于是可以枚举棋子，难点在于如何枚举
一个棋子(x, y)，可以贡献的范围在以(x-2, y-2)至(x, y)这个矩形中的点为左上角的9个3×3矩形
用左上角的点代表整个矩形，跳过在棋盘外的点

还有一个小点是要求输出不包含棋子的矩形，想到可以计算总的矩形数量
依旧用左上角的点代表整个矩形，行可以放在(h-2)处，列可以放在(w-2)处，总数量为(h-2)×(w-2)个
不包含棋子的矩形 = 总数 - 包含棋子的矩形

时间：O(9 * nlogn)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll h, w;
    int n;
    cin >> h >> w >> n;
    // 计数器：左上角的点 棋子数量
    map<pair<int, int>, int>cnt;
    for (int i = 1, x, y; i <= n; i++)
    {
        cin >> x >> y;
        // 枚举影响范围
        for (int dx = -2; dx <= 0; dx++)
        {
            for (int dy = -2; dy <= 0; dy++)
            {
                int sx = x + dx, sy = y + dy;
                // 左上角的点在棋盘外
                if (sx < 1 || sx + 2 > h) continue;
                if (sy < 1 || sy + 2 > w) continue;
                cnt[{sx, sy}]++;
            }
        }
    }
    vector<ll>ans(10);
    for (auto [x, c] : cnt)
    {
        ans[c]++;
    }
    ll tot = (h - 2) * (w - 2);
    ll other = 0;
    for (int i = 1; i <= 9; i++)
    {
        other += ans[i];
    }
    ans[0] = tot - other;
    for (int i = 0; i <= 9; i++)
    {
        cout << ans[i] << '\n';
    }
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