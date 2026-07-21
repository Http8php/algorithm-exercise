/*
思路：按题意模拟

时间：O(1)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    string s;
    cin >> s;
    s.insert(1, 1, '.');
    s.insert(3, 1, '.');
    cout << s;
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