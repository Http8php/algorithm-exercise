/*
知识点：贪心

思路：贪心地找最长len一定更优，答案为 (len + 1) / 2

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, mx = 0;
    string s;
    cin >> n >> s;
    int cur = 0;
    for (char c : s)
    {
        if (c == '#') cur++;
        else
        {
            mx = max(mx, cur);
            cur = 0;
        }
    }
    mx = max(mx, cur);
    cout << (mx + 1) / 2 << '\n';
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