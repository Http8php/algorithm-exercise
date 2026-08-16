/*
标签：并查集

思路：题目的重要性质是从小到大放鱼，这意味着后放的鱼一定可以吃掉先放的鱼
假设操作1放了一条鱼，它能吃掉的鱼就是它所在连通块的大小

把一个连通块中的最大值节点称作根，只要这个连通块内的鱼增大到和根一样，就能吃掉所有鱼
当前鱼在去往根的路上，可以通过吃掉其他鱼减少要额外增大的值
问题转化为增大后不小于通往根路径上的最大点权
当前在v，吃完v子树的鱼，大小为val_v+sz_v-1
要移动到父节点u，val_v+sz_v-1>=val_u -> val_v>=val_u-sz_v+1
对于所有点，维护mx，代表通往根路径上的最大val_u-sz_v+1，需要增加的大小就是mx_v-val_v

时间：O(mn + q)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2.5e5 + 10;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m, q;
int f[N], sz[N], mx[N], val[N];
void init()
{
    for (int i = 1; i <= n * m; i++)
    {
        f[i] = i;
        sz[i] = 1;
    }
}
// 在find、join中维护mx
int find(int x)
{
    if (f[x] == x) return x;
    int fa = find(f[x]);
    mx[x] = max(mx[x], mx[f[x]]);
    return f[x] = fa;
}
void join(int c1, int c2)
{
    int f1 = find(c1), f2 = find(c2);
    if (f1 == f2) return;
    f[f1] = f2;
    sz[f2] += sz[f1];
    mx[f1] = val[c2] - sz[f1] + 1;
}
// 给节点编号
inline int get(int x, int y)
{
    x--;
    return x * m + y;
}
void solve()
{
    cin >> n >> m >> q;
    init();
    int l = 0;
    while (q--)
    {
        int op, x, y, v;
        cin >> op;
        if (op == 1)
        {
            cin >> x >> y >> v;
            x ^= l, y ^= l;
            int u = get(x, y);
            val[u] = v;
            // 上下左右寻找连通块
            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];
                int nxt = get(nx, ny);
                if (nx < 1 || nx > n || ny < 1 || ny > m || val[nxt] == 0) continue;
                join(nxt, u);
            }
            // 从小到大加入，后加入的节点一定是连通块的根
            l = sz[u] - 1;
        }
        else
        {
            cin >> x >> y;
            x ^= l, y ^= l;
            int u = get(x, y);
            find(u);
            l = max(0, mx[u] - val[u]);
        }
        cout << l << '\n';
    }
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