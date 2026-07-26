#include <bits/stdc++.h>
using namespace std;
const int N = 510;
int n, m;
int g[N][N];
int p[N], vis[N];
bool match(int i)
{
    for (int j = 1; j <= m; j++)
    {
        if (g[i][j] && !vis[j])
        {
            vis[j] = 1;
            if (p[j] == 0 || match(p[j]))
            {
                p[j] = i;
                return true;
            }
        }
    }
    return false;
}
int hungarian()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof(vis));
        if (match(i)) cnt++;
    }
    return cnt;
}