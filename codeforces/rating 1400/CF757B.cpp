/*
思路：gcd!=1翻译过来就是找最多出现的因子
所有因子开一个桶，如果数字有这个因子就丢入，最后统计最多的

时间：O(ns^{1/2} + N) s为数字总和
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
vector<vector<int> >g(N);
void solve()
{
    int n;
    cin >> n;
    for (int i = 0, x; i < n; i++)
    {
        cin >> x;
        for (int j = 1; j * j <= x; j++)
        {
            if (x % j == 0) g[j].push_back(x);
            else continue;
            if (x / j != j) g[x/j].push_back(x);
        }
    }
    // 注意ans初始化1，避免都互质的情况，这种情况最多是1
    int ans = 1;
    for (int i = 2; i < N; i++)
    {
        ans = max(ans, (int)g[i].size());
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