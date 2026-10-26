/*
思路：每次除以一个数大于1最小的因数a是最优的，ans+=n/a
最后剩余一个质数，说明只能取1了，此时游戏结束

时间：O(n^{1/2})
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    int ans = n;
    while (1)
    {
        int nxt = -1;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                nxt = i;
                break;
            }
        }
        if (nxt == -1)
        {
            ans++;
            break;
        }
        n /= nxt;
        ans += n;
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