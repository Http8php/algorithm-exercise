/*
思路：每行每列只需n个就能填满，开两个桶记录已填多少即可

时间：O(n + m)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int>r(n + 1), c(n + 1);
    for (int i = 0, x, y; i < m; i++)
    {
        cin >> x >> y;
        r[x]++, c[y]++;
    }
    int mn = 1e9;
    for (int i = 1; i <= n; i++)
    {
        mn = min({mn, n - r[i], n - c[i]});
    }
    cout << mn;
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