/*
标签：滑动窗口、倍增

思路：首先尝试找到每一个位置一次移动到的位置
观察第k近所带来的性质，本身和第1,2,...,k近的点组成的区间一定是连续的
且这个区间长度一定是k+1，第k近在左端点或右端点处取到

用滑动窗口维护一段区间，求出每个位置的下一步nxt
初始l=1,r=k+1，如果i不在这个区间内，移动r直到r>=i
接下来尝试移动窗口，如果r+1到i距离严格小于l到i距离，则移动窗口
最后判断左右端点，哪个距离i远就是下一步的位置，以此类推得到每一个位置

接下来考虑m步，由于m巨大，可以考虑倍增
设dp[i][j]是从i出发移动2^j步的位置，dp[i][0]=nxt[i]
有转移dp[i][j]=dp[dp[j-1]][j-1]，j>=1
类似快速幂，依次检查m的每一个二进制位，如果是1，就移动一次(实际移动了2的幂次步)
用滚动数组可以优化掉第二维

时间：O(nlogm)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, k;
    ll m;
    cin >> n >> k >> m;
    vector<ll>p(n + 1);
    vector<int>nxt(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    int l = 1, r = k + 1;
    for (int i = 1; i <= n; i++)
    {
        while (r < i) l++, r++;
        // 尝试移动
        while (r + 1 <= n && p[r+1] - p[i] < p[i] - p[l]) l++, r++;
        if (p[i] - p[l] >= p[r] - p[i]) nxt[i] = l;
        else nxt[i] = r;
    }
    // s即思路中的dp
    vector<int>s(n + 1), ans(n + 1);
    for (int i = 1; i <= n; i++)
    {
        ans[i] = i;
        s[i] = nxt[i];
    }
    while (m)
    {
        if (m & 1)
        {
            for (int i = 1; i <= n; i++)
            {
                ans[i] = s[ans[i]];
            }
        }
        m >>= 1;
        vector<int>ns(n + 1);
        for (int i = 1; i <= n; i++)
        {
            ns[i] = s[s[i]];
        }
        s = ns;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
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