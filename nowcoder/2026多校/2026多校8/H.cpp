/*
标签：贪心、模拟

思路：要让数组和最小，就让每个数尽量变成0
只有释放操作-x才能减小数组和，考虑先提前算出可释放数量，这个也代表可用增量
即增加a[i]/x的释放量，剩余a[i]%x
贪心地想，增量加在快到x的数一定更优，到x释放变成0，可以用优先队列维护
每个数还需要x-a[i]-1(操作的前半部分可以+1)次才能变成0，如果剩余次数不够了，结束模拟
最后可能会有多的次数，发现每次操作相当于让数组和-(x-1)，多的次数相当于加在一个0上后%(x-1)
如果x=1，相当于无贡献，直接算数组和即可
注意一开始的可释放数量会爆long long，需要开__int128

单组时间：O(nlogn)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int mod = 998244353;
inline void print(i128 x)
{
	if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
void solve()
{
    int n;
    ll x;
    cin >> n >> x;
    i128 ans = 0, cnt = 0;
    if (x == 1)
    {
        for (int i = 0; i < n; i++)
        {
            ll a;
            cin >> a;
            ans = (ans + a) % mod;
        }
        print(ans);
        putchar('\n');
        return;
    }
    priority_queue<ll>q;
    for (int i = 1; i <= n; i++)
    {
        ll a;
        cin >> a;
        cnt += a / x;
        a %= x;
        if (a) q.push(a);
    }
    while (!q.empty())
    {
        ll u = q.top();
        q.pop();
        ll d = x - u - 1;
        if (d <= cnt) cnt -= d;
        else
        {
            q.push(u);
            break;
        }
    }
    ans = (ans + cnt % (x - 1)) % mod;
    while (!q.empty())
    {
        ans = (ans + q.top()) % mod;
        q.pop();
    }
    print(ans);
    putchar('\n');
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