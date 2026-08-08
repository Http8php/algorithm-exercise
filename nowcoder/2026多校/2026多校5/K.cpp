/*
思路：可以证明最后一定会进入周期为2的循环，且不超过3步一定进入循环
只要发现周期性就可以做，可以多写几步保证进入循环

时间：O(min(4, k) * n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int>a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int cnt = 0;
    while (1)
    {
        cnt++, k--;
        vector<int>b(n);
        for (int i = 0; i < n; i++)
        {
            set<int>s;
            s.insert(a[i]);
            s.insert(a[(i+1)%n]);
            s.insert(a[(i+n-1)%n]);
            int cur = 0;
            for (int x : s)
            {
                if (x == cur) cur++;
                else break;
            }
            b[i] = cur;
        }
        if (k == 0)
        {
            for (int i = 0; i < n; i++)
            {
                cout << b[i] << " ";
            }
            break;
        }
        if (cnt == 4)
        {
            if (k & 1)
            {
                for (int i = 0; i < n; i++)
                {
                    cout << a[i] << " ";
                }
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    cout << b[i] << " ";
                }
            }
            break;
        }
        a = b;
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