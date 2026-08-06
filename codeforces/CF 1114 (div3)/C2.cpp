/*
思路：现在要求最小操作数，从C1的分析可以知道，偶数位到偶数位，奇数位到奇数位
发现1不可能越过其他1，所以s中的1必须从左到右一一对应

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    ll ans = 0;
    string s, t;
    cin >> n >> s >> t;
    // 分别记录偶数奇数位置
    vector<ll>e1, o1, e2, o2;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            if (i & 1) o1.push_back(i);
            else e1.push_back(i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (t[i] == '1')
        {
            if (i & 1) o2.push_back(i);
            else e2.push_back(i);
        }
    }
    if (e1.size() != e2.size() || o1.size() != o2.size())
    {
        cout << -1 << '\n';
        return;
    }
    int sz1 = e1.size(), sz2 = o1.size();
    // 记录总距离
    for (int i = 0; i < sz1; i++)
    {
        ll d = abs(e1[i] - e2[i]);
        ans += d;
    }
    for (int i = 0; i < sz2; i++)
    {
        ll d = abs(o1[i] - o2[i]);
        ans += d;
    }
    // 一步长为2
    cout << ans / 2 << '\n';
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