/*
思路：如果 k>m 了，k前至少有m+1个前缀，而modm意义下只有m种前缀，必有相等前缀使子数组和为m
接下来有构造方案，除了k以外的位置放1，k放m-(k-1)%m

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, k, m;
    cin >> n >> k >> m;
    if (k > m)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++)
    {
        if (i == k) cout << m - (i - 1) % m << " ";
        else cout << 1 << " ";
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