/*
思路：x能被2^20整除的条件是x的二进制位低19位没有1
题目中的两种操作对应+1和×2，在二进制下体现为第0位+1和左移一位
也就是说，最多20次就能消灭一波，远低于弹药储备，没有无解情况
枚举i=0~20，x=x+i，对于新x不断×2，计算所有情况的最小值即可

时间：O(400)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, ans = 21;
    cin >> n;
    for (int i = 0; i <= 20; i++)
    {
        int nx = n + i;
        int cur = 0;
        while (((nx >> cur) & 1) == 0 && cur <= 19) cur++;
        ans = min(ans, 20 - cur + i);
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