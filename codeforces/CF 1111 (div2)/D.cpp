/*
知识点：分块

思路：先研究k的作用，k = i ^ j
k = 1 [0, 1][2, 3][4, 5] 只有相邻可以交换
k = 2 [0, 1, 2, 3][4, 5]
k = 3 [0, 1, 2, 3][4, 5]
k = 4 [0, 1, 2, 3, 4 ,5]
可以发现2的幂是分界点，把数组分块，每个块内可以任意交换
设 k = 2^j，块长均为 len = 2^(j + 1)
从小到大枚举j，如果每个当前块的最小值大于前一个块的最大值，这个j合法

时间：O(nlogn)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int>a(n + 1);
    bool ok = true;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] < a[i-1]) ok = false;
    }
    if (ok)
    {
        cout << 0 << '\n';
        return;
    }
    for (int j = 0; ; j++)
    {
        int len = (1 << (j + 1));
        if (len >= n)
        {
            cout << (1 << j) << '\n';
            return;
        }
        int pre = 0;
        bool ok = true;
        for (int i = 1; i <= n; i += len)
        {
            int mn = 1e9, mx = 0;
            for (int k = i; k <= min(n, i + len - 1); k++)
            {
                if (a[k] > mx) mx = max(mx, a[k]);
                if (a[k] < mn) mn = min(mn, a[k]);
            }
            if (i > 1 && mn < pre)
            {
                ok = false;
                break;
            }
            pre = mx;
        }
        if (ok)
        {
            cout << (1 << j) << '\n';
            return;
        }
    }
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