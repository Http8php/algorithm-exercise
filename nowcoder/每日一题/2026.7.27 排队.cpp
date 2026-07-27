/*
思路：每个a_i和a_j可以单独考虑贡献
在n!种情况中，有n!/2种情况对答案贡献1
统计i<j并且a_i!=a_j的数量，最后乘上n!/2

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
int cnt[N];
void solve()
{
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        cnt[x]++;
        int d = i - cnt[x];
        ans = (ans + d) % mod;
    }
    for (int i = 3; i <= n; i++)
    {
        ans = ans * i % mod;
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