/*
思路：如果n<=3，操作2是最优的
而一个数要到这个范围，操作次数是log级别的
所以模拟log次，直到操作2更优，减去剩余的次数即可

单组时间：O(logn)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    while (m)
    {
        int c1 = sqrt(n);
        if (c1 * c1 != n) c1++;
        int c2 = (n + 1) / 2;
        if (n - 1 <= min(c1, c2)) break;
        n = min(c1, c2);
        m--;
    }
    cout << n - m << '\n';
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