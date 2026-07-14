/*
知识点：字符串哈希
思路：去重操作的答案可以在操作1中实现，如果已有字符串，计数器加一
坑点是初始也可能有重复字符串
哈希用unordered_map实现
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, q;
    cin >> n >> q;
    unordered_map<string, int>mp;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (mp.count(s)) ans++;
        else mp[s]++;
    }
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            string s;
            cin >> s;
            if (mp.count(s)) ans++;
            else mp[s]++;
        }
        else
        {
            cout << ans << '\n';
            ans = 0;
        }
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