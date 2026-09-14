/*
思路：题目翻译过来就是找只包含02或12的最长一段
在字符串内找两次即可

单组时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    s = " " + s;
    int c1 = 0, c2 = 0, len = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '0' || s[i] == '2') len++;
        else
        {
            c1 = max(c1, len);
            len = 0;
        }
    }
    c1 = max(c1, len);
    len = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '1' || s[i] == '2') len++;
        else
        {
            c2 = max(c2, len);
            len = 0;
        }
    }
    c2 = max(c2, len);
    cout << max(c1, c2) << '\n';
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