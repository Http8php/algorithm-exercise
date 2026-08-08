/*
思路：当 n>5 时，无法找到三维立体图形，只能从精度下手
题目中给出 eps=0.01，只要两点距离 dis>eps就算不同的点，且 1-eps<dis<1+eps dis可以视作1
于是出现构造方案，n个点放在 x=0 的平面中，n个点放在 x=1 的平面中，两个面的点一一对应，面内点 eps<dis<=1-eps，面间点 1-eps<dis<1+eps
面内点最远距离相等，说明在一个圆内，设圆半径为r，则直径为2r
面间点最大距离 sqrt(1 + 4r^2) < 1 + eps -> 1 + 4r^2 < 1 + 2eps + o(eps) -> r <= sqrt(eps / 2) 因为约去了无穷小，可以取到等号
在以原点为中心的面内每隔0.011放一个点，若在圆内放进符合要求的点集合
        |
        | . . .
        | x . .
——————————————————>
        | x . .
        | . . .
        |         类似这样

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const double eps = 0.01;
const double r = sqrt(eps / 2);
const double s = eps * 1.1; // 0.011 极限距离
vector<pair<double, double> >g;
int mx = ceil(r / s); // mx = 7, 14 × 14的网格
void init()
{
    for (int i = -mx; i <= mx; i++)
    {
        for (int j = -mx; j <= mx; j++)
        {
            double x = i * s, y = j * s;
            // 符合要求的点有137个，>100，够用了
            if (x * x + y * y <= r * r)
            {
                g.push_back({x, y});
            }
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    cout << 2 * n << '\n';
    for (int i = 0; i < n; i++)
    {
        auto [y, z] = g[i];
        cout << 0 << " " << y << " " << z << '\n';
    }
    for (int i = 0; i < n; i++)
    {
        auto [y, z] = g[i];
        cout << 1 << " " << y << " " << z << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(10);
    init();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}