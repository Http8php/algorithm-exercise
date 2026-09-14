/*
标签：动态规划、前缀和

思路：设dp[i]为到i前能获得的最高得分
每遍历到一个新数，如果前面有一样的数，可以选择删除
记录每个数第一次出现的位置，如果删除，就加入那段区间的得分，这个用前缀和维护
如果删除不优，则不删除，即dp[i]=max(dp[i], dp[i-1])

时间：O(2n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
int a[N<<1], start[N<<1];
ll sum[N<<1], dp[N<<1];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= (n << 1); i++)
    {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
        if (start[a[i]])
        {
            dp[i] = dp[start[a[i]]-1] + sum[i] - sum[start[a[i]]-1];
        }
        else 
        {
            start[a[i]] = i;
        }
        dp[i] = max(dp[i], dp[i-1]);
    }
    cout << dp[n<<1];
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