/*
标签：枚举

思路：在兵的位置进行拓展，x,y都是正整数且没有兵的位置就可以填马
暴力记录这些点被拓展的次数，输出最大的位置
其实可以优化，每当找到一个马点，再次拓展可以算出这个位置的答案，这样可以少开一个map

时间：O(64 * nlogn)
*/

// 暴力版本 2532ms
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
void solve()
{
    int n, mx = 0;
    cin >> n;
    vector<pair<int, int> >pos(n);
    map<pair<int, int>, int>vis, cnt;
    for (int i = 0, x, y; i < n; i++)
    {
        cin >> x >> y;
        pos[i] = {x, y};
        vis[{x, y}] = 1;
    }
    int ax = -1, ay = -1;
    for (int i = 0; i < n; i++)
    {
        auto [x, y] = pos[i];
        for (int k = 0; k < 8; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx <= 0 || ny <= 0) continue;
            if (vis[{nx, ny}]) continue;
            cnt[{nx, ny}]++;
            if (cnt[{nx, ny}] > mx)
            {
                mx = cnt[{nx, ny}];
                ax = nx, ay = ny;
            }
        }
    }
    cout << ax << " " << ay;
}

// 优化版本 1343ms
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
void solve()
{
    int n, mx = 0;
    cin >> n;
    set<pair<int, int> >pos;
    for (int i = 0, x, y; i < n; i++)
    {
        cin >> x >> y;
        pos.insert({x, y});
    }
    int ax = -1, ay = -1;
    for (auto [x, y] : pos)
    {
        for (int k = 0; k < 8; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx <= 0 || ny <= 0 || pos.count({nx, ny})) continue;
            int cnt = 0;
            for (int nk = 0; nk < 8; nk++)
            {
                int nnx = nx + dx[nk];
                int nny = ny + dy[nk];
                cnt += pos.count({nnx, nny});
            }
            if (cnt > mx)
            {
                mx = cnt;
                ax = nx, ay = ny;
                if (mx == 8) goto done;
            }
        }
    }
    done: cout << ax << " " << ay;
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