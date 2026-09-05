#include <ext/pb_ds/priority_queue.hpp>
using Heap = __gnu_pbds::priority_queue<int>;

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct node
{
    int ls, rs;
    int w, d;
    friend bool operator<(node a, node b)
    {
        return a.w < b.w;
    }
}lh[N];
int merge(int a, int b)
{
    if (!a || !b) return a + b;
    if (lh[b] < lh[a]) swap(a, b);
    lh[a].rs = merge(lh[a].rs, b);
    if (lh[lh[a].ls].d < lh[lh[a].rs].d)
    {
        swap(lh[a].ls, lh[a].rs);
    }
    if (lh[a].rs) lh[a].d = lh[lh[a].rs].d + 1;
    else lh[a].d = 0;
    return a;
}