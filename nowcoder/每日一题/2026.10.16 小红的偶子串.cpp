/*
标签：双指针

思路：每次检查两个字母，如果相同就加入到当前答案

时间：O(L) L为字符串长度
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    int i = 0, j = 0;
    int ans = 0;
    while (i < n)
    {
        j = i;
        while (j + 1 < n && s[j] == s[j+1]) j += 2;
        ans = max(ans, j - i);
        i = j + 1;
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