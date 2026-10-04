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
    int n;
    cin >> n;
    string ans;
    for (int i = n; i >= 0; i--)
    {
        int x;
        cin >> x;
        string a = to_string(x);
        if (i != 0 && x == 1) a = "";
        if (i != 0 && x == -1) a = "-";
        string temp = to_string(i);
        if (i == 1) a += "x";
        else if (i != 0) a += "x^" + temp;
        if (x == 0) continue;
        else if (x < 0) ans += a;
        else if (i != n && x > 0) ans += "+" + a;
        else ans += a;
    }
    cout << ans;
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