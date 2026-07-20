/*
思路：四种模式
1 2 3 4
0 0 1 1
0 1 0 1
A.有2
1.有3：看3数量的奇偶性，a[i]=0对和无贡献，3奇数1次，偶数2次
2.有1、4：
0 1 0 -> 1 0 1 -> 0 1 1 2次
0 1 1
3.其他情况无解
B.无2
1.无3：0次
2.有3：同A1

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    int cnt = 0;
    bool ok01 = false, ok00 = false, ok11 = false;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 0 && b[i] == 1) ok01 = true;
        if (a[i] == 1 && b[i] == 0) cnt++;
        if (a[i] == 0 && b[i] == 0) ok00 = true;
        if (a[i] == 1 && b[i] == 1) ok11 = true;
    }
    if (cnt == 0 && ok01)
    {
        if (ok00 && ok11)
        {
            cout << 2 << '\n';
            return;
        }
        else
        {
            cout << -1 << '\n';
            return;
        }
    }
    if (!ok01 && cnt == 0)
    {
        cout << 0 << '\n';
        return;
    }
    cout << (cnt % 2 ? 1 : 2) << '\n';
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