/*
知识点：博弈

思路：由于高度互不相同，最高的一定能确定是后手赢
接下来是次高，如果不在最高边上，就是后手赢；在最高边上，就是先手赢
从高到低填，如果四联通内有S，先手必赢(相当于两人局面互换)，有F后手必赢，都没有先手赢

时间：O(nmlognm)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char> >mp(n + 1, vector<char>(m + 1, '?'));
    map<int, pair<int, int> >p;
    for (int i = 1, x; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> x;
            p[x] = {i, j};
        }
    }
    for (auto it = p.rbegin(); it != p.rend(); it++)
    {
        auto [num, pos] = *it;
        auto [x, y] = pos;
        bool cf = false, cs = false;
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (mp[nx][ny] == 'F') cf = true;
            else if (mp[nx][ny] == 'S') cs = true;
        }
        if (cs) mp[x][y] = 'F';
        else if (cf) mp[x][y] = 'S';
        else mp[x][y] = 'S';
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << (mp[x][y] == 'F' ? "First\n" : "Second\n"); 
    }
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