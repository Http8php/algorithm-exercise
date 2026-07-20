/*
思路：bmi = w / (h / 100) / (h / 100) >= 25
w * 10000 >= 25 * h * h

时间：O(1)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int h, w;
    cin >> h >> w;
    int l = 100 * 100 * w;
    int r = 25 * h * h;
    cout << (l >= r ? "Yes" : "No");
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