/*
标签：构造、贪心、可并堆

思路：如果没有约束，所有节点直接连在1号点下面，深度一定最小
现一个节点可能有多个父亲，发现接在编号最大的父节点下最优
每完成一次这样的操作，把该点连的父节点的约束删除，并把剩余的需求转移到连的父节点身上
这个可以用pbds库中的可并堆实现

时间：O(nlogn)
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using ll = long long;
using Heap = __gnu_pbds::priority_queue<int>;
void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0, x; i < n - 1; i++)
    {
        cin >> x;
    }
    vector<Heap>h(n + 1);
    for (int i = 0, u, v; i < q; i++)
    {
        cin >> u >> v;
        h[u].push(v);
    }
    vector<int>fa(n + 1);
    // 倒序处理，保证处理i时，它的父亲的深度已经确定，转移约束时不会影响已确定的结构
    for (int i = n; i >= 1; i--)
    {
        // 没有约束，挂在1号点下最优
        if (h[i].empty())
        {
            fa[i] = 1;
            continue;
        }
        int f = h[i].top();
        fa[i] = f;
        // 去重
        while (!h[i].empty() && h[i].top() == f) h[i].pop();
        if (!h[i].empty()) h[f].join(h[i]);
    }
    vector<int>dep(n + 1);
    ll ans = 0;
    for (int i = 2; i <= n; i++)
    {
        dep[i] = dep[fa[i]] + 1;
        ans += dep[i];
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