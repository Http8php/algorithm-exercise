/*
标签：矩阵快速幂

思路：首先合法的子序列一定全0或以1结尾，设数量分别为a,b
遍历字符串，如果当前是0，只能加在0后面或单独成子序列，新数量na=a+a+1
当前是1，随意加或单独成子序列，nb=b+(a+b)+1

把转移写成矩阵，配一个3×3的矩阵
                           2 0 0     1 1 0
(na, b, 1) = (a, b, 1)  M1:0 1 0  M2:0 2 0
(a, nb, 1)                 1 0 1     0 1 1
初始矩阵v0=(a, b, 1) = (0, 0, 1)
遍历字符串时，遇到0乘上M1，1乘上M2，即v1=v0*M1*M2...
设M=M1*M2...，由于复制n次，变成M^n，用矩阵快速幂处理
最后答案就是v1的前两维

单组时间：O(L + logn) L为字符串长度
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5;
const int mod = 1e9 + 7;
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
matrix fp(matrix a, ll b)
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
void solve()
{
    ll n;
    string s;
    cin >> n >> s;
    matrix m1;
    m1.init(3);
    m1.ma[0][0] = 2, m1.ma[0][1] = 0, m1.ma[0][2] = 0;
    m1.ma[1][0] = 0, m1.ma[1][1] = 1, m1.ma[1][2] = 0;
    m1.ma[2][0] = 1, m1.ma[2][1] = 0, m1.ma[2][2] = 1;
    matrix m2;
    m2.init(3);
    m2.ma[0][0] = 1, m2.ma[0][1] = 1, m2.ma[0][2] = 0;
    m2.ma[1][0] = 0, m2.ma[1][1] = 2, m2.ma[1][2] = 0;
    m2.ma[2][0] = 0, m2.ma[2][1] = 1, m2.ma[2][2] = 1;
    matrix m, tmp;
    m.init(3), tmp.init(3);
    m.ma[0][0] = 0, m.ma[0][1] = 0, m.ma[0][2] = 1;
    tmp.reset();
    for (char c : s)
    {
        if (c == '0') tmp = tmp * m1;
        else tmp = tmp * m2;
    }
    tmp = fp(tmp, n);
    m = m * tmp;
    ll ans = (m.ma[0][0] + m.ma[0][1]) % mod;
    cout << ans << '\n';
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