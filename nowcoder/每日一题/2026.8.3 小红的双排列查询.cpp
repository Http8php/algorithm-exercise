/*
标签：莫队

思路：一个区间内要是双排列，需要满足以下条件
1.区间长度len为偶数
2.区间内数字数量为2的个数cur等于len/2
3.双排列从1开始，数字必须是等差数列，即 (cur + 1) * cur / 2 = sum
其中sum为区间内不重复数字之和
变量的维护依靠莫队实现

时间：O(nsqrt(n))
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e5 + 10;
int sq;
struct node
{
    int l, r, id, bel;
    friend bool operator<(node a, node b)
    {
        if (a.bel != b.bel) return a.bel < b.bel;
        return (a.bel & 1) ? a.r < b.r : a.r > b.r;
    }
}Q[N];
ll a[N], cnt[N];
bool ans[N];
ll cur = 0, sum = 0;
int l = 1, r = 0;
inline void add(int p)
{
    ll x = a[p];
    cnt[x]++;
    if (cnt[x] == 2) cur++;
    else if (cnt[x] == 3) cur--;
    // sum中不包含重复数字
    if (cnt[x] == 1) sum += x;
}
inline void del(int p)
{
    ll x = a[p];
    cnt[x]--;
    if (cnt[x] == 2) cur++;
    else if (cnt[x] == 1) cur--;
    if (cnt[x] == 0) sum -= x;
}
void solve()
{
    int n, q;
    cin >> n >> q;
    sq = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> Q[i].l >> Q[i].r;
        Q[i].id = i;
        Q[i].bel = Q[i].l / sq;
    }
    sort(Q + 1, Q + q + 1);
    for (int i = 1; i <= q; i++)
    {
        while (l > Q[i].l) add(--l);
        while (r < Q[i].r) add(++r);
        while (l < Q[i].l) del(l++);
        while (r > Q[i].r) del(r--);
        ll len = Q[i].r - Q[i].l + 1;
        if ((len & 1) == 0 && cur * 2 == len && cur * (cur + 1) / 2 == sum)
        {
            ans[Q[i].id] = true;
        }
        else ans[Q[i].id] = false;
    }
    for (int i = 1; i <= q; i++)
    {
        cout << (ans[i] ? "Yes\n" : "No\n");
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