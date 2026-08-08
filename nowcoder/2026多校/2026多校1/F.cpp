/*
思路：从 mod n 下手
由于 f(x) 中的形式是 a[j] - a[i]，当所有值都加上同一个数d时，会变成 (a[j] + d) - (a[i] + d) = a[j] - a[i]
要求 f(x) 不变，考虑每个值改变相同量

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, k, x;
    cin >> n >> k >> x;
    vector<int>a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // d为题目约束需要改变的值
    // 可能为负数，要加n再取模
    int d = (x - a[k] + n) % n;
    for (int i = 0; i < n; i++)
    {
        a[i] = (a[i] + d) % n;
        cout << a[i] << " ";
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