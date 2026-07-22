/*
知识点：构造

思路：一个有效的构造，前k个数是 1 n 2 n-1 ...
这样保证k个数有k-1个不同差值，最后递增/递减差值始终是1即可

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, k;
    cin >> n >> k;
    int l = 1, r = n, cur = 0;
    for (int i = 0; i < k; i++)
    {
        cur = (i % 2 ? r-- : l++);
        cout << cur << " ";
    }
    if (cur > r)
    {
        for (int i = k; i < n; i++)
        {
            cout << r-- << " ";
        }
    }
    else
    {
        for (int i = k; i < n; i++)
        {
            cout << l++ << " ";
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