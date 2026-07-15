/*
知识点：并查集

小trick：一个连通块中的任意两点可以交换值

思路：根据这个trick，很容易想到把x并为一类，y并为一类
最终值是排序，只要连通块内的值和索引值对的上即可

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
int a[N], f[N];
int find(int x)
{
    if (x == f[x]) return x;
    return f[x] = find(f[x]);
}
void join(int c1, int c2)
{
    int f1 = find(c1), f2 = find(c2);
    if (f1 != f2) f[f1] = f2;
}
void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    bool ok = true, sorted = true;
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
        cin >> a[i];
        if (a[i] != i) sorted = false;
    }
    if (sorted)
    {
        cout << "YES\n";
        return;
    }
    // 维护连通块
    for (int i = 1; i <= n; i++)
    {
        if (i + x <= n) join(i, i + x);
        if (i + y <= n) join(i, i + y);
    }
    vector<vector<int> >cur(n + 1), tar(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int fa = find(i);
        cur[fa].push_back(a[i]);
        // 目标值是索引值集合
        tar[fa].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!cur[i].empty())
        {
            sort(cur[i].begin(), cur[i].end());
            sort(tar[i].begin(), tar[i].end());
            if (cur[i] != tar[i]) ok = false;
        }
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
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