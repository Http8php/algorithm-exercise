/*
标签：贪心

思路：要么花x元一次性购买，要么在ab中购买
如果在ab中购买，对于每种商品，取最小值是最优的

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<ll>a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += min(a[i], b[i]);
    }
    cout << min(sum, x);
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