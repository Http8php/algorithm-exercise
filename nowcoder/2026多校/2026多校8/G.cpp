/*
标签：构造、贪心

思路：前面不同相当于要进位，两组乘积差距拉大，不同的机会就更多
着重要测试c=1的情况，因为最高位最难进位
x1 100...000 y1 199...000
x2 100...999 y2 199...999 就能拉大差距

时间：O(a + b)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int len = a + b;
    // x1
    cout << 1;
    for (int i = 0; i < a - 1; i++)
    {
        cout << 0;
    }
    for (int i = 0; i < len - a; i++)
    {
        cout << 0;
    }
    // y1
    cout << " " << 1;
    for (int i = 0; i < b - 1; i++)
    {
        cout << 9;
    }
    for (int i = 0; i < len - b; i++)
    {
        cout << 0;
    }
    // x2
    cout << " " << 1;
    for (int i = 0; i < a - 1; i++)
    {
        cout << 0;
    }
    for (int i = 0; i < len - a; i++)
    {
        cout << 9;
    }
    // y2
    cout << " " << 1;
    for (int i = 0; i < b - 1; i++)
    {
        cout << 9;
    }
    for (int i = 0; i < len - b; i++)
    {
        cout << 9;
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