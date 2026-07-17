/*
知识点：贪心

思路：可以发现，Bob得分最大值一定落在<a的值和>a的值之间
先统计出这两个值，把b偏向得分多的区域即可，只需 b = a + 1 或 b = a - 1

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, a;
    cin >> n >> a;
    int c1 = 0, c2 = 0;
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        if (x < a) c1++;
        else if (x > a) c2++;
    }
    if (c1 > c2) cout << a - 1 << '\n';
    // 如果c1 == c2，取a + 1和a - 1都行，最好情况只能是平局
    else cout << a + 1 << '\n';
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