/*
思路：a=b^c，令b=1，c=a^b，这种构造可以应对大部分情况
特判不适用的情况：n=1，b=2，c=3
n=1e9，可以令b=去掉最低位1的数，c=最低位1

单组时间：O(1)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e9;
void solve()
{
    int a;
    cin >> a;
    if (a == 1)
    {
        cout << "2 3\n";
        return;
    }
    if (a == N)
    {
        cout << (N ^ (1 << 9)) << " " << (1 << 9) << '\n';
        return;
    }
    cout << 1 << " " << (1 ^ a) << '\n';
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