/*
标签：数位dp

思路：f(i)*f(i+d)相当于在i的二进制位选1个1，在i+d的二进制位选1个1
设dp[p][lim][add][b1][b2]
p代表当前搜到哪一位
lim代表当前数是否<=n，1满足/0不满足
add代表低位是否进位
b1代表是否在i里选了1
b2代表是否在i+d里选了1
转移在代码中体现

单组时间：O(60)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;
ll n, d;
ll dp[65][2][2][2][2];
ll dfs(int p, bool lim, bool add, bool b1, bool b2)
{
    if (p == 61)
    {
        // 两者都选了，这个数<=n，没有更高进位，找到1个合法数了
        return b1 && b2 && lim && !add;
    }
    if (dp[p][lim][add][b1][b2] != -1)
    {
        return dp[p][lim][add][b1][b2];
    }
    // n,d的当前位
    int pn = ((n >> p) & 1), pd = ((d >> p) & 1);
    ll res = 0;
    for (int i = 0; i < 2; i++)
    {
        // 因为从低位开始记录，lim=0/1只代表后缀是否满足，不代表i与n的直接关系
        // 若某个位选的数>当前位，不满足
        // 若某个位选的数<当前位，满足
        // 若某个位选的数=当前位，继承之前的状态
        bool nlim = false;
        if (i > pn) nlim = false;
        else if (i < pn) nlim = true;
        else nlim = lim;
        bool nadd = false;
        // 需要进位
        if (add + pd + i >= 2) nadd = true;
        // i+d的当前位
        int cp = (add + pd + i) % 2;
        // 枚举是否在p位选择i的1或i+d的1
        for (int x = 0; x < 2; x++)
        {
            for (int y = 0; y < 2; y++)
            {
                // 若要选i的1，i当前位i=1且之前没选过(b1==0)
                if (x && (i == 0 || b1)) continue;
                // 若要选i+d的1，i+d当前位cp=1且之前没选过(b2==0)
                if (y && (cp == 0 || b2)) continue;
                res = (res + dfs(p + 1, nlim, nadd, b1 | x, b2 | y)) % mod;
            }
        }
    }
    dp[p][lim][add][b1][b2] = res;
    return res;
}
void solve()
{
    cin >> n >> d;
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, true, false, false, false) << '\n';
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