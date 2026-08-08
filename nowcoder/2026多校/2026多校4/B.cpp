/*
思路：一种投机的做法
原式变形得 q|x1^2-p p|x2^2-q
x1^2-p = k1q
x2^2-q = k2p 不妨令 k1 = k2
即x1^2 = x2^2 p+q = x1^2
x2在[1, p)内，枚举x2，可以算出q，如果 x1<q，答案可行
这样只有2、3找不到，需要特判
会在 sqrt(p) 附近找到答案，时间复杂度可以接受

时间：O(p^{1/2})
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int p;
    cin >> p;
    if (p == 2)
    {
        cout << "12 1 71\n";
        return;
    }
    if (p == 3)
    {
        cout << "4 1 13\n";
        return;
    }
    // 直接写成 x2 = sqrt(p) 也是对的，效率更高
    int x2 = 1;
    while (x2 < p)
    {
        ll res = x2 * x2;
        if (res - p < 1)
        {
            x2++;
            continue;
        }
        int q = res - p;
        if (q > x2)
        {
            cout << x2 << " " << x2 << " " << q << '\n';
            return;
        }
        x2++;
    }
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