/*
标签：不变量

思路：观察每个ai，往前一格变成ai-1，往后一格变成ai+1
所以每个位置的ai-i是固定的，可以随意移动
现在要找到高度相同的一段，h-1,h-2,h-3...
于是问题转化为在排序去重后的ai-i数组中找最长的公差为1的等差数列

单组时间：O(nlogn)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    set<int>s;
    for (int i = 0, x; i < n; i++)
    {
        cin >> x;
        s.insert(x - i);
    }
    vector<int>a;
    for (int x : s)
    {
        a.push_back(x);
    }
    int sz = a.size();
    int ans = 1, len = 1;
    for (int i = 1; i < sz; i++)
    {
        if (a[i] == a[i-1] + 1) len++;
        else
        {
            ans = max(ans, len);
            len = 1;
        }
    }
    ans = max(ans, len);
    cout << ans << '\n';
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