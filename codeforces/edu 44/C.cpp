/*
知识点：贪心

思路：桶的最大体积取决于最短长度，所以体积范围[1, a[1] + l]
有贪心策略：先从a[1]+l开始取，每次从后面拿k-1根，如果不够了，从1往后k根一组

时间：O(nlogn)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, k;
    ll l;
    cin >> n >> k >> l;
    vector<ll>a(n * k + 1);
    for (int i = 1; i <= n * k; i++)
    {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    if (a[n] - a[1] > l)
    {
        cout << 0;
        return;
    }
    int p = upper_bound(a.begin() + 1, a.end(), a[1] + l) - a.begin() - 1;
    ll ans = 0;
    int cur = p, cnt = 0;
    for (int i = n * k; i - (k - 1) > p; i -= k - 1)
    {
        ans += a[cur--];
        cnt++;
    }
    for (int i = 1; i <= p - cnt; i += k)
    {
        ans += a[i];
    }
    cout << ans;
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