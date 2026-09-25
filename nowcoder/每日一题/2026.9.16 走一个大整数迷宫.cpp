/*
标签：bfs

思路：先观察c = a * p^{2^b}，由于最后要求%(p-1)为0，所以可以先把c进行取模
p % (p-1) = 1，所以c = a，到新位置直接加a%(p-1)即可

接下来考虑计算最小值，可以开一个数组dis[i][j][m]，表示到(i, j)处余数是m时的最短路
这个可以用bfs实现，由于最多只有nmp个位置，在题目的限制下可以通过

时间：O(4 * nmp)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node
{
    int x, y, d;
};
const int N = 15, M = 1e4 + 10;
int a[N][N], b[N][N], dis[N][N][M];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void solve()
{
    int n, m, p;
    cin >> n >> m >> p;
    p--;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> b[i][j];
        }
    }
    memset(dis, -1, sizeof(dis));
    queue<node>q;
    dis[1][1][a[1][1]%p] = 0;
    q.push({1, 1, a[1][1] % p});
    while (!q.empty())
    {
        auto [x, y, d] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            int nd = (d + a[nx][ny]) % p;
            if (dis[nx][ny][nd] != -1) continue;
            dis[nx][ny][nd] = dis[x][y][d] + 1;
            q.push({nx, ny, nd});
        }
    }
    cout << dis[n][m][0];
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