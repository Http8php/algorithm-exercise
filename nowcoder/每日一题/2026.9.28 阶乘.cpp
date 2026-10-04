/*
思路：要想令n!%p=0，p中的所有质因子必须包含在n!中
从i=2开始枚举，如果gcd(i, p)>1，说明p中一部分因子在i中
把这部分因子除掉后，如果p=1，说明因子除干净了，直接输出i
还有一种情况是i<p但是p只剩一个质数了，此时直接输出p

单组时间：O(n^{1/2} * logn)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool check(int x)
{
    if (x == 0 || x == 1) return false;
    if (x == 2) return true;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0) return false;
    }
    return true;
}
void solve()
{
    int n;
    cin >> n;
    if (n == 1 || check(n))
    {
        cout << n << '\n';
        return;
    }
    for (int i = 2; ; i++)
    {
        if (gcd(i, n) > 1)
        {
            n /= gcd(i, n);
            if (n == 1)
            {
                cout << i << '\n';
                return;
            }
            if (i < n && check(n))
            {
                cout << n << '\n';
                return;
            }
        }
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