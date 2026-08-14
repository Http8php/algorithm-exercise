#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 110;
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