/*
思路：先从1出发依次连后面的点，可以连n-1条边
m<=n-1：有m(m-1)/2个点对
m>n-1：还可以连m-(n-1)条边，每多连一条减少1个点对，有(n-1)(n-2)/2-(m-n+1)个点对

时间：O(1)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, m;
    cin >> n >> m;
    if (m < n) cout << m * (m - 1) / 2 << '\n';
    else
    {
        ll res = m - n + 1;
        cout << (n - 1) * (n - 2) / 2 - res << '\n';
    }
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