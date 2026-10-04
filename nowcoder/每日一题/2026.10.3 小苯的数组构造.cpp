/*
标签：构造、贪心

思路：要构造不递减数组，贪心地构造，如果a[i]>a[i+1]，把a[i+1]变成a[i]是最优的
如果a[i]<=a[i+1]，那么a[i]不需要变，b[i]=0
这样构造，极差就是差距最大的a[i],a[i+1]，记作d
由于需要改变a数组数字的差距，构造出来的b的最大极差只能是d

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<ll>a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cout << 0 << " ";
    for (int i = 2; i <= n; i++)
    {
        if (a[i] >= a[i-1]) cout << 0 << " ";
        else
        {
            ll d = a[i-1] - a[i];
            cout << d << " ";
            a[i] += d;
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