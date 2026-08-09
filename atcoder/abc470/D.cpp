/*
思路：首先要知道p''=p，这个可以通过样例2发现
于是只要维护两个数组a,b，b=a'
操作2为偶数时，交换a[x]a[y],b[a[x]]b[a[y]]
奇数时，交换b[x]b[y],a[b[x]]a[b[y]]

时间：O(n + q)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int>a(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    int cnt = 0;
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, y;
            cin >> x >> y;
            if (cnt & 1)
            {
                swap(a[pos[x]], a[pos[y]]);
                swap(pos[x], pos[y]);
            }
            else
            {
                swap(pos[a[x]], pos[a[y]]);
                swap(a[x], a[y]);
            }
        }
        else cnt++;
    }
    if (cnt & 1)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << pos[i] << " ";
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cout << a[i] << " ";
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