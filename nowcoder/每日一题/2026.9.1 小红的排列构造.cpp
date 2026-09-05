/*
思路：从左到右遍历数组，如果p没有这个数就给p，q没有这个数就给q
如果都有了，输出-1，最后把剩余的数填入未填的格子即可

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
    vector<int>vp(n + 1), vq(n + 1);
    vector<int>p(n + 1), q(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (!vp[a[i]])
        {
            vp[a[i]] = 1;
            p[i] = a[i];
        }
        else if (!vq[a[i]])
        {
            vq[a[i]] = 1;
            q[i] = a[i];
        }
        else
        {
            cout << -1;
            return;
        }
    }
    int ip = 1, iq = 1;
    for (int i = 1; i <= n; i++)
    {
        if (p[i] == 0)
        {
            while (vp[ip] == 1) ip++;
            p[i] = ip;
            ip++;
        }
        if (q[i] == 0)
        {
            while (vq[iq] == 1) iq++;
            q[i] = iq;
            iq++;
        }
    }
    for (int i = 1; i <= n; i++) cout << p[i] << " ";
    cout << '\n';
    for (int i = 1; i <= n; i++) cout << q[i] << " ";
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