/*
思路：首先推导影长的公式
设OA=OB=OP=R, P(Rcosθ,Rsinθ), Q为P朝(-sx,-sy)方向直线与x轴交点
x(t)=Rcosθ-tsx=OQ
y(t)=Rsinθ-tsy=0 -> t=Rsinθ/sy
x(t)=Rcosθ-sx/sy*Rsinθ
=R/sy|sycosθ-sxsinθ| 代入sx=OScosθ_s, sy=OSsinθ_s
=R*OS/sy|sinθ_s*cosθ-cosθ_s*sinθ|
=R*OS/sy*sin|θ_s-θ|

答案在θ_a,θ_b,θ_s,θ_s+Π/2,θ_s-Π/2的地方取得
后面三个角代表与OS平行，垂直的线
如果角在θ_a,θ_b之间，说明可以相切，此时这个角成为备选答案

单组时间：O(1)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const double pi = acos(-1.0);
// 控制θ∈[0,2Π)
double norm(double x)
{
    while (x < 0) x += 2.0 * pi;
    while (x >= 2.0 * pi) x -= 2.0 * pi;
    return x;
}
void solve()
{
    double sx, sy, ax, ay, bx, by;
    cin >> sx >> sy >> ax >> ay >> bx >> by;
    double OS = hypot(sx, sy);
    double R = hypot(ax, ay);
    vector<double>cand;
    double th1 = norm(atan2(ay, ax));
    cand.push_back(th1);
    double th2 = norm(atan2(by, bx));
    cand.push_back(th2);
    double l = min(th1, th2), r = max(th1, th2);
    double th3 = norm(atan2(sy, sx));
    if (th3 >= l && th3 <= r) cand.push_back(th3);
    double th4 = norm(th3 + pi / 2.0);
    if (th4 >= l && th4 <= r) cand.push_back(th4);
    double th5 = norm(th3 - pi / 2.0);
    if (th5 >= l && th5 <= r) cand.push_back(th5);
    double mn = 1e18, mx = 0;
    for (double th : cand)
    {
        double len = R * OS / sy * sin(abs(th3 - th));
        mx = max(mx, len);
        mn = min(mn, len);
    }
    cout << mn << " " << mx << '\n';
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