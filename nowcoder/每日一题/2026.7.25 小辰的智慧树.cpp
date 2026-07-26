/*
知识点：贪心，差分

思路：收益函数 f(x) = x * (h + h - x) = 2hx - x^2
设当前树的高度为H，已经砍了t单位，那么再砍1单位的真实收益是：
Δf=f(t+1)−f(t)
=[2H(t+1)−(t+1)^2]−[2Ht−t^2]
=2H−(2t+1)
=2(H−t)−1
所以砍得越多，收益越小，但H越大，收益也越大，于是选择从高到低砍一定最优

时间：O(max(n, mx))
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 10;
int d[N];
void solve()
{
    int n, mx = 0;
    ll m;
    cin >> n >> m;
    for (int i = 0, h, c; i < n; i++)
    {
        cin >> h >> c;
        mx = max(mx, h);
        d[c+1]++;
        d[h+1]--;
    }
    // 维护可以砍的树
    for (int i = 1; i <= mx; i++)
    {
        d[i] += d[i-1];
    }
    ll ans = 0;
    for (int i = mx; i >= 1; i--)
    {
        int cnt = d[i];
        if (cnt == 0) continue;
        if (m > cnt)
        {
            // x = 1 f(1) = 2h - 1
            // cnt棵树 总收益 (2h - 1) * cnt
            ans += 2ll * i * cnt - cnt;
            m -= cnt;
        }
        else
        {
            ans += 2ll * i * m - m;
            break;
        }
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