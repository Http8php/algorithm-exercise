/*
标签：枚举

思路：首先两种材料都要用完，所以边数一定相同
设最后可以构造出n×m的矩形，边数为n(m+1)+m(n+1)
材料边数为p+2q，于是有方程p+2q=n(m+1)+m(n+1)
由于nm完全对称，可以假设m>=n，m=(p+2q-n)/(2n+1)

还有一个性质是p>=m-n
q材料能提供一横一竖，无法补全行列的差值，需要p材料来补
其实需要p与m-n同奇偶，但是观察p+2q=2mn+m+n，发现p与m+n同奇偶，m+n与m-n同奇偶，不用额外考虑了

因为将n作为枚举变量，所以需要求出上界，现有m>=n
p+2q=2mn+m+n>=2n^2+2n>2n^2 -> n<sqrt(p/2+q)

单组时间：O(sqrt(p/2+q))
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int p, q;
    cin >> p >> q;
    int w = ceil(sqrt(p / 2 + q));
    for (int n = 1; n <= w; n++)
    {
        if ((p + 2 * q - n) % (2 * n + 1)) continue;
        int m = (p + 2 * q - n) / (2 * n + 1);
        if (m >= n && p >= abs(m - n))
        {
            cout << n << " " << m << '\n';
            return;
        }
    }
    cout << -1 << '\n';
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