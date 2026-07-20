/*
思路：同心圆，可以考虑两条线段的中垂线，如果不平行，一定是Yes
平行的情况，必须中垂线要重合
判平行即判断斜率是否相等，用斜率公式时交叉相乘，可以避免斜率不存在和精度问题

时间：O(1)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    vector<ll>x(4), y(4);
    for (int i = 0; i < 4; i++)
    {
        cin >> x[i] >> y[i];
    }
    if ((y[0] - y[1]) * (x[2] - x[3]) != (x[0] - x[1]) * (y[2] - y[3]))
    {
        cout << "Yes\n";
        return;
    }
    if ((y[0] - y[1]) * (y[0] + y[1] - y[2] - y[3]) == -1 * (x[0] - x[1]) * (x[0] + x[1] - x[2] - x[3]))
    {
        cout << "Yes\n";
        return;
    }
    cout << "No\n";
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