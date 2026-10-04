/*
标签：素数筛、动态规划

思路：如果数组中有数>k，就要把这个数x拆分
拆分方式是找一个x的质因子p，加入p个x/p
由于x/p一定变小，并且值域<=n，所以可以从1到n处理
设dp[i]为i到<=k所需要的最小操作次数，显然当i<=k时，dp[i]=0
如果i>k，遍历i的每一个质因子，转移dp[i]=dp[i/p]*p+1，取所有质因子中操作次数最小的
答案是Σdp[x]，x属于原数组

预处理时间：O(nloglogn)
单组时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
bool vis[N];
vector<vector<ll> >p(N);
void init()
{
    vis[0] = vis[1] = true;
    for (int i = 2; i < N; i++)
    {
        if (!vis[i])
        {
            for (ll j = (i << 1); j < N; j += i)
            {
                p[j].push_back(i);
                vis[j] = true;
            }
            p[i].push_back(i);
        }
    }
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll>dp(n + 1, 1e18);
    for (int i = 1; i <= n; i++)
    {
        if (i <= k)
        {
            dp[i] = 0;
            continue;
        }
        for (ll x : p[i])
        {
            dp[i] = min(dp[i], dp[i/x] * x + 1);
        }
    }
    ll ans = 0;
    for (int i = 0, x; i < n; i++)
    {
        cin >> x;
        ans += dp[x];
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}