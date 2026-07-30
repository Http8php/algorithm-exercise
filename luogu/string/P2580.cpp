/*
知识点：字典树

思路：字典树模板题

时间：O((n + m) * L) L为字符串长度
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
int tot = 1, tr[N][26];
bool vis[N], exist[N];
void insert(string s)
{
    int cur = 1;
    for (char c : s)
    {
        if (!tr[cur][c-'a']) tr[cur][c-'a'] = ++tot;
        cur = tr[cur][c-'a'];
    }
    exist[cur] = true;
}
// 只需要改这个函数
// 0 未找到 1 初次找到 2 已找到
int find(string s)
{
    
    int cur = 1;
    for (char c : s)
    {
        if (!tr[cur][c-'a']) return 0;
        cur = tr[cur][c-'a'];
    }
    if (!exist[cur]) return 0;
    if (!vis[cur])
    {
        vis[cur] = 1;
        return 1;
    }
    return 2;
}
void solve()
{
    int n, m;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        insert(s);
    }
    cin >> m;
    while (m--)
    {
        string s;
        cin >> s;
        int op = find(s);
        if (op == 0) cout << "WRONG\n";
        else if (op == 1) cout << "OK\n";
        else cout << "REPEAT\n";
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