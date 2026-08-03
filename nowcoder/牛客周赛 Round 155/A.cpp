/*
思路：按题意模拟

时间：O(1)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int c1 = 0;
    for (int i = 0, x; i < 3; i++)
    {
        cin >> x;
        if (x == 1) c1++;
    }
    cout << (c1 % 2 ? "ON" : "OFF");
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}