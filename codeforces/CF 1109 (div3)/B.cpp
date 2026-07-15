/*
知识点：贪心

思路：最终是递增序列，那就从1开始，让序列保持12345...，这样用最少的书达成要求
一旦有多的书，就往后搬，如果用这个策略，在某个地方书不够了，直接NO

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<ll>a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] > i)
        {
            a[i+1] += a[i] - i;
        }
        // 值至少等于索引值
        if (a[i] < i)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << (a[n] >= n ? "YES\n" : "NO\n");
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