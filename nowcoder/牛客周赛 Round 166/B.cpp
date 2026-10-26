/*
思路：抹零相当于向下取整，平摊为a*10^k/b
再转成金币即可

时间：O(k)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int a, b, k;
    cin >> a >> b >> k;
    ll res = 1;
    for (int i = 0; i < k; i++)
    {
        res *= 10;
    }
    ll ans = a * res / b;
    cout << ans / res << " " << ans % res;
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