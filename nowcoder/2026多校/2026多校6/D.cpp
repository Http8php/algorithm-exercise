/*
标签：奇偶最短路，bfs

思路：由于可以反复经过点边，只要点与1连通，就可以通过反复+2到达k的倍数
由于可能存在奇环，一个点可以有奇数偶数路径，通过bfs解得

开始讨论，大于k的路径d用 ceil(d/k)*k 得到
偶数路径算出来是奇数且k是奇数需要额外+k
奇数路径只有k为奇数时才可能，如果算出来是偶数需要额外+k

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 0x3f3f3f3f3f3f3f3f;
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int> >g(n + 1);
    for (int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        if (u != v) g[v].push_back(u);
    }
    vector<vector<ll> >dis(n + 1, vector<ll>(2, -1));
    queue<pair<int, int> >q;
    dis[1][0] = 0;
    q.push({1, 0});
    while (!q.empty())
    {
        auto [u, p] = q.front();
        q.pop();
        int np = p ^ 1;
        for (int v : g[u])
        {
            if (dis[v][np] == -1)
            {
                dis[v][np] = dis[u][p] + 1;
                q.push({v, np});
            }
        }
    }
    // 也可以讨论k
    // k偶数，必须有偶数路径
    // k奇数，分别算奇数偶数，取最小
    for (int i = 1; i <= n; i++)
    {
        ll ans = inf;
        if (dis[i][0] != -1)
        {
            ll res = (dis[i][0] + k - 1) / k * k;
            if ((k & 1) && (res & 1)) res += k;
            ans = min(ans, res);
        }
        if (dis[i][1] != -1)
        {
            if (k & 1)
            {
                ll res = (dis[i][1] + k - 1) / k * k;
                if ((res & 1) == 0) res += k;
                ans = min(ans, res);
            }
        }
        cout << (ans == inf ? -1 : ans) << " ";
    }
    cout << '\n';
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