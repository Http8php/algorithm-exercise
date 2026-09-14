/*
标签：分类讨论

思路：先把所有数填满，且最少增加陡峭值
发现如果当前位是0，就把它赋值成上一个值，第一个数是0就把第一个数变成从左往右的第一个正数
如果此时数列中没有正数，直接输出11...112即可
填完后计算陡峭值d，会有三种情况
1.d>1，没有办法改变，-1
2.d=1，填好了，直接输出
3.d=0，说明数列中都是同一个数，改变不固定的首或尾，让那个数+1即可，如果改变不了首尾，就是-1

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int v = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i])
        {
            v = a[i];
            break;
        }
    }
    if (v == 0)
    {
        for (int i = 1; i < n; i++) cout << 1 << " ";
        cout << 2;
        return;
    }
    vector<int>b(n + 1);
    if (a[1] == 0) b[1] = v;
    else b[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        if (a[i]) b[i] = a[i];
        else b[i] = b[i-1];
    }
    ll d = 0;
    for (int i = 1; i < n; i++)
    {
        d += abs(b[i] - b[i+1]);
    }
    if (d > 1)
    {
        cout << -1;
        return;
    }
    else if (d == 1)
    {
        for (int i = 1; i <= n; i++) cout << b[i] << " ";
        return;
    }
    else
    {
        if (a[1] && a[n])
        {
            cout << -1;
            return;
        }
        if (a[n])
        {
            b[1] = b[2] + 1;
            for (int i = 1; i <= n; i++) cout << b[i] << " ";
        }
        else
        {
            b[n] = b[n-1] + 1;
            for (int i = 1; i <= n; i++) cout << b[i] << " ";
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