/*
标签：枚举

思路：回忆因式分解的过程，是把a,c分别拆成a1×a2,b1×b2，a1×b2+a2×b1=b
枚举所有a1,a2和b1,b2，可以通过枚举sqrt(a)以下的因子实现
组合可以是{a1, a2},{a2, a1}与{b1, b2},{-b1, -b2}的组合，覆盖了所有情况

单组时间：O(a^{1/2} + c^{1/2})
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (c == 0)
    {
        cout << 1 << " " << 0 << " " << a << " " << b << '\n';
        return;
    }
    vector<pair<int, int> >ca, cc;
    for (int i = 1; i * i <= abs(a); i++)
    {
        if (abs(a) % i == 0)
        {
            int a1 = i, a2 = a / i;
            ca.push_back({a1, a2});
            ca.push_back({a2, a1});
        }
    }
    for (int j = 1; j * j <= abs(c); j++)
    {
        if (abs(c) % j == 0)
        {
            int b1 = j, b2 = c / j;
            cc.push_back({b1, b2});
            cc.push_back({-b1, -b2});
        }
    }
    for (auto [a1, a2] : ca)
    {
        for (auto [b1, b2] : cc)
        {
            if (a1 * b2 + a2 * b1 == b)
            {
                cout << a1 << " " << b1 << " " << a2 << " " << b2 << '\n';
                return;
            }
        }
    }
    cout << "NO\n";
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