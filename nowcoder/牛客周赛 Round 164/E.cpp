/*
标签：构造

思路：首先无论是奇数还是偶数，至多得到ceil(n/2)分
且n无论放在什么位置，都能得分，所以k∈(0, ceil(n/2)]，区间之外输出No
分奇偶讨论，一种可行的奇数构造方案是奇数+偶数+后k个奇数，偶数同理

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, k;
    cin >> n >> k;
    if (n & 1)
    {
        if (k == 0 || k > (n + 1) / 2)
        {
            cout << "No";
            return;
        }
        cout << "Yes\n";
        int cnt = (n + 1) / 2 - k, i = 1;
        while (cnt--)
        {
            cout << i << " ";
            i += 2;
        }
        for (int j = 2; j <= n; j += 2)
        {
            cout << j << " ";
        }
        while (i <= n)
        {
            cout << i << " ";
            i += 2;
        }
    }
    else
    {
        if (k == 0 || k > n / 2)
        {
            cout << "No";
            return;
        }
        cout << "Yes\n";
        int cnt = n / 2 - k, i = 2;
        while (cnt--)
        {
            cout << i << " ";
            i += 2;
        }
        for (int j = 1; j <= n; j += 2)
        {
            cout << j << " ";
        }
        while (i <= n)
        {
            cout << i << " ";
            i += 2;
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