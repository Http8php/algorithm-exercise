/*
思路：暴力删除判剩下的串是不是回文
坑点是必须从出现过的字符中删除

时间：O(nm) m为字符集数量
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool check(string s)
{
    int l = 0, r = s.length() - 1;
    while (l < r)
    {
        if (s[l] != s[r]) return false;
        l++, r--;
    }
    return true;
}
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    vector<int>vis(26);
    for (char c : s)
    {
        vis[c-'a'] = 1;
    }
    for (int i = 0; i < 26; i++)
    {
        if (!vis[i]) continue;
        string t;
        char tar = 'a' + i;
        for (char c : s)
        {
            // 跳过相当于删除
            if (c == tar) continue;
            t += c;
        }
        if (check(t)) ans++;
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