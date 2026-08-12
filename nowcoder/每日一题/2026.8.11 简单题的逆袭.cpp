/*
思路：首先判断k无穷大和无解的情况
当x=0时，y取任何数k都无穷大
当x=1时，y=0时k无解，y>1时k无穷大
当y=0时，x取任何数k都无穷大
由于2^60>10^18，最多60次就能找到答案，剩余情况直接暴力即可

时间：O(y/x)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll x, y;
    cin >> x >> y;
    if (x == 0 || x == 1 || y == 0)
    {
        cout << -1 << '\n';
        return;
    }
    int k = 0;
    ll cur = 1;
    // cur * x <= y 移项防爆ll
    while (cur <= y / x)
    {
        cur *= x;
        k++;
    }
    cout << k << '\n';
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