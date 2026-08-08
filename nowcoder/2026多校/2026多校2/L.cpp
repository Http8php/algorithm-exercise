/*
标签：状压dp

思路：注意到如果pi<pj(i<j)，那么a_pi<a_pj就无影响，所以考虑p中的逆序对
如果pi>pj，如果a_pi<a_pj，那么逆序对-1，反之+1
要让逆序对数量变化最大，就让逆序对全部增加或全部减少
也就是对于每一个排列A，要么都是A_pi>A_pj，要么都是A_pi<A_pj
把小于看作有向边，问题转换为DAG拓扑序计数
由于两种情况相当于建边方向不同，求出一种直接×2即可
注意特判没有逆序对的情况，此时就是n的全排列

时间：O(n2^n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<vector<int> >g(n);
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                cnt++;
                g[j].push_back(i);
            }
        }
    }
    if (cnt == 0)
    {
        ll ans = 1;
        for (int i = 2; i <= n; i++)
        {
            ans = ans * i % mod;
        }
        cout << ans;
        return;
    }
    // i加入时，j必须已经包含
    vector<int>pre(n);
    for (int i = 0; i < n; i++)
    {
        int mask = 0;
        for (int j : g[i])
        {
            mask |= (1 << j);
        }
        pre[i] = mask;
    }
    vector<ll>dp(1 << n);
    dp[0] = 1;
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i >> j) & 1)
            {
                if ((i & pre[j]) == pre[j])
                {
                    dp[i] = (dp[i] + dp[i^(1<<j)]) % mod;
                }
            }
        }
    }
    cout << (dp[(1<<n)-1] * 2 % mod);
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