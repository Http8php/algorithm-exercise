/*
思路：发动技能之间是一个循环，只需要知道循环中打了多少枪(即射速v)就是答案
设一个周期内换了q次弹，一共有(q+1)*m发子弹
完整打完所有子弹的时间是(q+1)*m+qr，如果冷却没好，只能干等
于是时间为max((q+1)*m+qr, c)，v=(q+1)*m/max((q+1)*m+qr, c)

接下来只需找到合适的q
1.(q+1)*m+qr<=c -> q<=(c-m)/(m+r)
v=(q+1)*m/c，v随q增大而增大，q选(c-m)/(m+r)
2.q>(c-m)/(m+r)，v=((q+1)*m)/((q+1)*m+qr)，上下q同次，系数分母大，q增大v减小
q选ceil/floor((c-m)/(m+r))即可

单组时间：O(1)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int m, r, c;
    cin >> m >> r >> c;
    int q1 = (c - m) / (m + r);
    int q2 = (c + r - 1) / (m + r);
    double c1 = 1.0 * ((q1 + 1) * m) / max((q1 + 1) * m + q1 * r, c);
    double c2 = 1.0 * ((q2 + 1) * m) / max((q2 + 1) * m + q2 * r, c);
    cout << max(c1, c2) << '\n';
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