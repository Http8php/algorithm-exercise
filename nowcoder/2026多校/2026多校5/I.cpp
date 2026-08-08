/*
思路：每次将最左边的两个1变成0，这样至少会少两个1
始终保证第二个1前最多只有一个1，若干次操作后，一定最多只有1个1

时间：O(n)
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
    n = (1 << n) - 1;
    int y = -1;
    for (int x = 1; x <= n; x++)
    {
        // 该位不用改
        if (s[x] == '0')
        {
            cout << 0 << " ";
            continue;
        }
        // 第一个1位，记录
        if (y == -1)
        {
            y = x;
            cout << 0 << " ";
            continue;
        }
        cout << y << " ";
        // 保证y一定是第一个
        if ((x ^ y) < x) y = (x ^ y);
        else
        {
            // 在后面需模拟翻转，最前面的1由y记录，不用模拟
            s[x^y] = ((s[x^y] == '0') ? '1' : '0');
            y = -1;
        }
    }
    cout << '\n';
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