/*
思路：注意到n<=1e4，可以考虑n^2做法
想到中心扩展法，从一个或两个字母开始扩，最多一对容错，里面用完了外面更不可能

时间：O(n^2)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans++;
        int cnt = 0;
        int l = i - 1, r = i + 1;
        while (l >= 0 && r < n)
        {
            if (s[l] == s[r]) ans++;
            else
            {
                if (cnt < 1)
                {
                    ans++, cnt++;
                }
                else break;
            }
            l--, r++;
        }
        l = i, r = i + 1;
        cnt = 0;
        while (l >= 0 && r < n)
        {
            if (s[l] == s[r]) ans++;
            else
            {
                if (cnt < 1)
                {
                    ans++, cnt++;
                }
                else break;
            }
            l--, r++;
        }
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