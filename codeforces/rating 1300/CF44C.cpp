/*
知识点：差分

思路：先覆盖m个区间，求前缀和，如果有一天的数量不为1，直接输出

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int>d(n + 2);
    for (int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b;
        d[a]++;
        d[b+1]--;
    }
    for (int i = 1; i <= n; i++)
    {
        d[i] += d[i-1];
        if (d[i] != 1)
        {
            cout << i << " " << d[i];
            return;
        }
    }
    cout << "OK";
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