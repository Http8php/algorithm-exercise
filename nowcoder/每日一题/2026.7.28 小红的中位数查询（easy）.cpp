/*
标签：离线处理，对顶堆

思路：最多有1e5个等长区间，其中有大量重复，会导致暴力超时
考虑把询问离线，按左端点排序，类似滑动窗口，所有元素只会被处理一遍
求中位数使用对顶堆，下一个区间与当前区间相比会减少增加相同元素，处理新的元素
由于有删除操作，使用multiset

时间：O(nlogn)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node
{
    int l, r, id, ans;
};
bool cmp1(node a, node b)
{
    return a.l < b.l;
}
bool cmp2(node a, node b)
{
    return a.id < b.id;
}
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int>a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<node>b(q + 1);
    for (int i = 1; i <= q; i++)
    {
        cin >> b[i].l >> b[i].r;
        b[i].id = i;
    }
    sort(b.begin() + 1, b.end(), cmp1);
    // s1: 大顶堆 s2: 小顶堆，中位数在s1顶部
    // s1.size() = s2.size() + 1
    multiset<int>s1, s2;
    // 用第一次询问初始化
    int len = b[1].r - b[1].l + 1;
    int half = len / 2;
    for (int i = b[1].l; i <= b[1].r; i++)
    {
        s2.insert(a[i]);
    }
    for (int i = 0; i <= half; i++)
    {
        auto it = s2.begin();
        s1.insert(*it);
        s2.erase(it);
    }
    b[1].ans = *s1.rbegin();
    for (int i = 2; i <= q; i++)
    {
        int ol = b[i-1].l;
        int cl = b[i].l;
        int cnt = cl - ol;
        // 删除旧元素 [ol, ol + cnt - 1]
        for (int j = 0; j < cnt; j++)
        {
            int idx = ol + j;
            int x = a[idx];
            if (s1.count(x))
            {
                s1.erase(s1.find(x));
                if (!s2.empty())
                {
                    auto it = s2.begin();
                    s1.insert(*it);
                    s2.erase(it);
                }
            }
            else
            {
                s2.erase(s2.find(x));
            }
            // 添加新元素 [or + 1, nr]
            // 由于长度一致，少了几个就会多几个
            idx = b[i-1].r + 1 + j;
            x = a[idx];
            if (s1.empty() || x <= *s1.rbegin())
            {
                s1.insert(x);
            }
            else
            {
                s2.insert(x);
            }
            while ((int)s1.size() < (int)s2.size() + 1)
            {
                auto it = s2.begin();
                s1.insert(*it);
                s2.erase(it);
            }
            while ((int)s1.size() > (int)s2.size() + 1)
            {
                auto it = s1.end();
                it--;
                s2.insert(*it);
                s1.erase(it);
            }
        }
        b[i].ans = *s1.rbegin();
    }
    sort(b.begin() + 1, b.end(), cmp2);
    for (int i = 1; i <= q; i++)
    {
        cout << b[i].ans << '\n';
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