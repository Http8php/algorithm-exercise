/*
标签：贪心

思路：操作翻译过来就是在两个对称的位置删除一个
先看k较大的情况，由于k与n-k+1没有交集，相当于在前n-k+1和后n-k+1中选n-k+1个数
由于删除后会补齐，每次只能在i和n-i+1中选一个(1<=i<=n-k+1)，此时贪心地选择最大的最优
k较小的情况，发现[k, n-k+1]这一段无论如何都会被删，删完后变成上一种情况
k的分界线在n/2，对应数组左半边/右半边

单组时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll>a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll ans = 0;
    if (2 * k <= n)
    {
        for (int i = k; i <= n - k + 1; i++)
        {
            ans += a[i];
        }
        int l = 1, r = n;
        // 要删除n-k+1个数，已删除n-2k+2个数
        // 剩余n-k+1-n+2k-2=k-1个数
        for (int i = 0; i < k - 1; i++)
        {
            ans += max(a[l], a[r]);
            l++, r--;
        }
    }
    else
    {
        int l = 1, r = n;
        for (int i = 0; i < n - k + 1; i++)
        {
            ans += max(a[l], a[r]);
            l++, r--;
        }
    }
    cout << ans << '\n';
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