/*
标签：分类讨论、贪心

思路：发现一张纸中如果有6、5、4、3，剩余的位置只能填2或1了
一张纸填满一定最优，所以从大到小枚举3456，剩余的位置尽量给2
5剩余11个位置只能给1，4剩余5个2的位置
3比较特殊，4个3刚好填满，3个3剩余1个2和5个1
2个3剩余3个2和6个1，1个3剩余5个2和7个1
3456都填完后，如果数量超过s，说明不行
剩余s都给2，1个s贡献9个2，如果此时2还不够，说明不行
多的2全变成1，1个2贡献4个1，如果此时1还不够，说明不行
上述条件都满足，说明可以放下

单组时间：O(1)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll s;
    cin >> s;
    vector<ll>k(7);
    for (int i = 1; i <= 6; i++)
    {
        cin >> k[i];
    }
    ll c1 = 0, c2 = 0;
    s -= k[6];
    s -= k[5];
    c1 += k[5] * 11;
    s -= k[4];
    c2 += k[4] * 5;
    s -= k[3] / 4;
    if (k[3] % 4)
    {
        s--;
        ll r = 4 - k[3] % 4;
        if (r == 1) c2++, c1 += 5;
        else if (r == 2) c2 += 3, c1 += 6;
        else c2 += 5, c1 += 7;
    }
    if (s < 0)
    {
        cout << "No\n";
        return;
    }
    c2 += s * 9;
    if (c2 < k[2])
    {
        cout << "No\n";
        return;
    }
    c1 += (c2 - k[2]) * 4;
    if (c1 < k[1])
    {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
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