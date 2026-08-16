/*
思路：按题意模拟

时间：O(nL)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
char yy[] = {'a', 'e', 'i', 'o', 'u'};
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        // 是不是梗语言，true代表不是
        bool ok = false;
        if (s.length() != 8) ok = true;
        for (int i = 0; !ok && i < 8; i += 2)
        {
            int c = s[i];
            for (int k = 0; k < 5; k++)
            {
                if (c == yy[k])
                {
                    ok = true;
                    break;
                }
            }
        }
        for (int i = 1; !ok && i < 8; i += 2)
        {
            int c = s[i];
            bool yes = false;
            for (int k = 0; k < 5; k++)
            {
                if (c == yy[k])
                {
                    yes = true;
                    break;
                }
            }
            if (!yes) ok = true;
        }
        cout << (ok ? "Well-Being\n" : "Suspected Virus\n");
    }
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