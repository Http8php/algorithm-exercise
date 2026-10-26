/*
标签：模拟

思路：按题意模拟

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, x;
    cin >> n >> x;
    for (int i = 0, a; i < n; i++)
    {
        cin >> a;
        if (a & 1) x--;
        else x++;
    }
    cout << x;
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