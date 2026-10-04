/*
思路：打表即可发现只有0、3的倍数和5的倍数能做到异或上3的倍数后还是3的倍数
最后需要最大化3的倍数，即把5的倍数变成3的倍数
因为5异或上所有3的倍数都能变成3的倍数，所以即使旁边有两个3的倍数，也能让答案加1
单点修改操作只要看被修改的那一位
原本不是3、5倍数，改后变成倍数 -> 答案加1
原本是3、5倍数，改后不是倍数 -> 答案减1

单组时间：O(n + q)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, q;
    cin >> n >> q;
    int ans = 0;
    vector<int>a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] % 3 == 0 || a[i] % 5 == 0) ans++;
    }
    cout << ans << " ";
    while (q--)
    {
        int p, x;
        cin >> p >> x;
        if (a[p] % 3 && a[p] % 5)
        {
            if (x % 3 == 0 || x % 5 == 0) ans++;
        }
        else if (a[p] % 3 == 0 || a[p] % 5 == 0)
        {
            if (x % 3 && x % 5) ans--;
        }
        a[p] = x;
        cout << ans << " ";
    }
    cout << '\n';
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