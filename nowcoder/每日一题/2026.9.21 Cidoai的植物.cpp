/*
思路：列数不多，加入操作每次加n个，而去除操作每次减1个
所以需要大量填充的只有操作1并且是第一次访问的列，这种情况直接遍历
遇到操作2并且那个位置有植物，去除并记录那个位置，下次操作1时只需要遍历特定的几行即可
最多去除k株，再次遍历也不会超过k次

最坏时间：O(nm + k)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i32 = unsigned int;
int n, m, k;
i32 seed;
i32 rnd()
{
	i32 ret = seed;
	seed ^= (seed << 13);
	seed ^= (seed >> 17);
	seed ^= (seed << 5);
	return ret;
}
vector<int> trans()
{
    vector<int>res(3);
    int op = (rnd() % 2) + 1;
    int x, y;
    if (op == 1)
    {
        x = (rnd() % m) + 1;
        y = (rnd() % (n * m)) + 1;
    }
    else
    {
        x = (rnd() % n) + 1;
        y = (rnd() % m) + 1;
    }
    res[0] = op, res[1] = x, res[2] = y;
    return res;
}
ll calc(int i, int j)
{
    return (i - 1) * m + j;
}
void solve()
{
    cin >> n >> m >> k >> seed;
    vector<int>vis(m + 1);
    vector<vector<int> >mp(n + 1, vector<int>(m + 1)), g(m + 1);
    ll ans = 0;
    for (int i = 1; i <= k; i++)
    {
        auto v = trans();
        int op = v[0], x = v[1], y = v[2];
        if (op == 1)
        {
            if (!vis[x])
            {
                vis[x] = 1;
                for (int j = 1; j <= n; j++)
                {
                    mp[j][x] = y;
                    ans ^= y * calc(j, x);
                }
            }
            else
            {
                for (int e : g[x])
                {
                    mp[e][x] = y;
                    ans ^= y * calc(e, x);
                }
                g[x].clear();
            }
        }
        else
        {
            if (mp[x][y])
            {
                ans ^= mp[x][y] * calc(x, y);
                mp[x][y] = 0;
                g[y].push_back(x);
            }
        }
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