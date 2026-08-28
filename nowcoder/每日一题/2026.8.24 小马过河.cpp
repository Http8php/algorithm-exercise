/*
标签：计算几何

思路：算出两直线的方程联立即可，注意特判斜率不存在的情况

单组时间：O(1)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    double px, py, ux, uy, vx, vy;
    cin >> px >> py >> ux >> uy >> vx >> vy;
    if (uy == vy)
    {
        cout << px << " " << uy << '\n';
        return;
    }
    double kuv = (uy - vy) / (ux - vx);
    double kpq = (vx - ux) / (uy - vy);
    double x = (py - uy + kuv * ux - kpq * px) / (kuv - kpq);
    double y = uy + kuv * (x - ux);
    cout << x << " " << y << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(10);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}