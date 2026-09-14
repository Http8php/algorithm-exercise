/*
标签：珂朵莉树

思路：由于每个区间的数相同，可以维护区间信息
最后询问数字种类数量，用map维护
推平时，把老区间的数减去，新区间的数加上
注意数组无限长，0一定存在

时间：O(qlogq)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node
{
    int l, r;
    mutable int v;
    node(int l, int r = 0, int v = 0): l(l), r(r), v(v) {}
    friend bool operator<(node a, node b)
    {
        return a.l < b.l;
    }
};
set<node>odt;
map<int, ll>cnt;
auto split(int p)
{
    auto it = odt.lower_bound(node(p));
    if (it != odt.end() && it->l == p) return it;
    it--;
    if (p > it->r) return odt.end();
    int l = it->l, r = it->r, v = it->v;
    odt.erase(it);
    odt.insert(node(l, p - 1, v));
    return odt.insert(node(p, r, v)).first;
}
void assign(int l, int r, int v)
{
    auto itr = split(r + 1);
    auto itl = split(l);
    vector<int>val;
    for (auto it = itl; it != itr; it++)
    {
        cnt[it->v] -= it->r - it->l + 1;
        val.push_back(it->v);
    }
    odt.erase(itl, itr);
    odt.insert(node(l, r, v));
    cnt[v] += r - l + 1;
    // 输出cnt.size()，把归零的数删除，不然影响答案
    for (int x : val)
    {
        auto it = cnt.find(x);
        if (it != cnt.end() && it->second == 0) cnt.erase(it);
    }
}
void solve()
{
    odt.insert(node(1, 1e9));
    cnt[0] = 1e9;
    int q;
    cin >> q;
    while (q--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        assign(l, r, x);
        cout << cnt.size() << '\n';
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