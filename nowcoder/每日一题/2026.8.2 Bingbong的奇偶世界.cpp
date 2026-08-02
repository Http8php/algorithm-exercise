/*
思路：一个数是偶数，它的最后一位是偶数
于是固定右端点r为偶数，每个非0左端点l能贡献2^{r-l-1}的贡献
遍历时，每往右一格就*2，维护所有非0点的贡献，如果该位是偶数，则计入答案(需加入本身)

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    ll ans = 0, cur = 0;
    for (char c : s)
    {
        ans = (ans + (cur + 1) * (((c - '0') & 1) == 0)) % mod;
        cur = ((cur << 1) + (c != '0')) % mod;
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