/*
标签：枚举、素数筛

思路：首先发现区间长度不超过1e6，可以枚举逐个判断
如果用普通的试除法，复杂度不可接受
于是使用区间筛，即用sqrt(r)内的质数标记[l, r]的合数
枚举时，如果符合要求的个数等于k，直接输出当前数，枚举结束也不到k，输出-1
有一些小细节，在代码注释中体现

时间：O(xloglogx) x为sqrt(r)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 10;
bool vis[N];
vector<ll>p;
int res[N];
void init(int n)
{
    vis[0] = vis[1] = true;
    for (ll i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            p.push_back(i);
            // 注意开ll，防止i*i爆int
            for (ll j = i * i; j <= n; j += i)
            {
                vis[j] = true;
            }
        }
    }
}
void check(ll l, ll r)
{
    // 手动标记1为合数
    if (l == 1) res[0] = 1;
    for (ll x : p)
    {
        // 起点这样写是为了防止类似x=2,l=2时把l筛掉
        for (ll i = max((l + x - 1) / x * x, x * x); i <= r; i += x)
        {
            // 加入-l的偏移量，可以在数组中储存
            res[i-l] = 1;
        }
    }
}
int calc(ll x)
{
    ll ans = 0;
    while (x)
    {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}
void solve()
{
    ll l, r;
    int k;
    cin >> l >> r >> k;
    init(ceil(sqrt(r)));
    check(l, r);
    int cnt = 0;
    for (ll i = l; i <= r; i++)
    {
        if (!res[i-l])
        {
            int x = calc(i);
            int m = sqrt(x);
            if (m * m == x) cnt++;
            if (cnt == k)
            {
                cout << i;
                return;
            }
        }
    }
    cout << -1;
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