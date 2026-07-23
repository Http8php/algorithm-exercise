/*
知识点：枚举

思路：i * j = a[i] * a[j] <= 2n
i从1-n枚举，j从i+1-2n/i枚举，不会超过n^2

时间：O(nlogn)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
ll cnt[N];
void solve()
{
    memset(cnt, 0, sizeof(cnt));
    ll n;
    cin >> n;
    vector<ll>a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        // 桶记录索引，方便排序
        cnt[a[i]] = i;
    }
    // i < j只是不能取自身，可以排序
    sort(a.begin() + 1, a.end());
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n && a[i] * a[j] <= 2 * n; j++)
        {
            if (a[i] * a[j] == cnt[a[i]] + cnt[a[j]]) ans++;
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