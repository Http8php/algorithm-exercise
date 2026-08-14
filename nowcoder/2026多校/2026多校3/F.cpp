/*
标签：状态压缩、dp优化、矩阵快速幂

思路：列数很多，但是行数很少，且每格只能填012，意味着状态不多
相邻两格不能相同，一共3*2^{n-1}种状态
列数很多，正常递推不能接受，需要用矩阵快速幂优化
n<10，最多有728种状态，时间复杂度O(728^3logm)，会超时

发现012是等价的，一种合法方案把01互换位置也合法
于是只要固定方案的“形状”，状态数会少很多，比如固定前两个为0、1
第三个可以填0，也可以填2，假设填0
0 0 1 1 2 2
1 2 0 2 0 1
0 0 1 1 2 2 此6种情况方案数完全一样，算出一种直接×6即可

设dp[c][j]为填到第c列用j状态的情况，M[i][j]代表j接在i后面的方案数
dp[c][j] = Σ{i}(dp[c-1][i] × M[i][j])
这是矩阵乘法的定义，算出初始转移矩阵后×m-1次，累计所有格子的数就是答案

时间：O((2^{n-2})^3logm)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 130;
const int mod = 998244353;
int n, m, mx;
struct matrix
{
    int sz;
    ll ma[N][N];
    void init(int s)
    {
        sz = s;
        clear();
    }
    void clear()
    {
        memset(ma, 0, sizeof(ma));
    }
    void reset()
    {
        clear();
        for (int i = 0; i < sz; i++) ma[i][i] = 1;
    }
    matrix friend operator*(const matrix &a, const matrix &b)
    {
        matrix ans;
        ans.init(a.sz);
        ans.clear();
        for (int i = 0; i < a.sz; i++)
        {
            for (int j = 0; j < a.sz; j++)
            {
                for (int k = 0; k < a.sz; k++)
                {
                    ans.ma[i][j] = (ans.ma[i][j] + a.ma[i][k] * b.ma[k][j] % mod) % mod;
                }
            }
        }
        return ans;
    }
};
matrix mfp(matrix a, ll b)
{
    matrix ans;
    ans.init(a.sz);
    ans.reset();
    while (b > 0)
    {
        if (b & 1) ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}
ll ifp(ll a, ll b)
{
    a %= mod;
    ll ans = 1;
    while (b > 0)
    {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
vector<int> get(int a1, int a2, int k)
{
    vector<int>res(n + 1);
    res[1] = a1, res[2] = a2;
    for (int i = 3; i <= n; i++)
    {
        if ((k >> (i - 3)) & 1)
        {
            res[i] = 3 - res[i-1] - res[i-2];
        }
        else res[i] = res[i-2];
    }
    return res;
}
// 合法的状态转移计算
ll calc(int k1, int k2)
{
    ll res = 0;
    auto a = get(0, 1, k1);
    for (int b1 = 0; b1 < 3; b1++)
    {
        if (b1 == a[1]) continue;
        for (int b2 = 0; b2 < 3; b2++)
        {
            if (b1 == b2 || b2 == a[2]) continue;
            auto b = get(b1, b2, k2);
            bool ok = true;
            for (int i = 3; i <= n; i++)
            {
                if (a[i] == b[i])
                {
                    ok = false;
                    break;
                }
            }
            if (ok) res++;
        }
    }
    return res;
}
void solve()
{
    cin >> n >> m;
    if (n == 1)
    {
        cout << 3ll * ifp(2, m - 1) % mod;
        return;
    }
    // 固定首尾后，后面序列状态的掩码
    mx = 1 << (n - 2);
    matrix ans;
    ans.init(mx);
    for (int i = 0; i < mx; i++)
    {
        for (int j = 0; j < mx; j++)
        {
            ans.ma[i][j] += calc(i, j);
        }
    }
    ans = mfp(ans, m - 1);
    ll res = 0;
    for (int i = 0; i < mx; i++)
    {
        for (int j = 0; j < mx; j++)
        {
            res = (res + ans.ma[i][j]) % mod;
        }
    }
    cout << res * 6ll % mod;
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