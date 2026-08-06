/*
思路：观察两个操作，第一个让位置改变±2，第二个让两个数移动1
不管哪一种，奇偶位置上1的数量不会被改变，即偶数/奇数位1恒定
于是分别统计s,t中1的总数量和偶数位上1的数量，如果都相等，则s可以变成t

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    string s, t;
    cin >> n >> s >> t;
    int c1 = 0, c2 = 0;
    int e1 = 0, e2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            c1++;
            if ((i & 1) == 0) e1++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (t[i] == '1')
        {
            c2++;
            if ((i & 1) == 0) e2++;
        }
    }
    if (c1 != c2 || e1 != e2)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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