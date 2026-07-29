/*
标签：动态规划、双指针

思路：由于途径点在起点和终点之间，且每次只能往下走，所以经过每一行时，必须经过该行的每一个点
要走遍每一个点，最后一定在列最小值或最大值处去往下一行
转移有四种情况：最小->最小、最小->最大、最大->最小、最大->最大

时间：O(nlogn)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<pair<ll, ll> >p(n + 2);
    for (int i = 0; i < 2; i++)
    {
        ll x, y;
        cin >> x >> y;
        if (i == 0) p[0] = {x, y};
        else p[n+1] = {x, y};
    }
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        p[i].first = x;
    }
    for (int i = 1; i <= n; i++)
    {
        ll y;
        cin >> y;
        p[i].second = y;
    }
    sort(p.begin() + 1, p.begin() + n + 1);
    ll mn = 0, mx = 0, pmn = 0, pmx = 0;
    // 上一行的首尾
    ll pl = p[0].second, pr = p[0].second;
    int i = 1, j = 1;
    while (i <= n + 1)
    {
        // 双指针找同一行的首尾点
        while (j <= n && p[j+1].first == p[i].first) j++;
        ll l = p[i].second, r = p[j].second;
        // 到左边
        ll t1 = abs(pl - r) + abs(r - l);
        ll t2 = abs(pr - r) + abs(r - l);
        // 到右边
        ll t3 = abs(pl - l) + abs(l - r);
        ll t4 = abs(pr - l) + abs(l - r);
        mn = min(pmn + t1, pmx + t2);
        mx = min(pmn + t3, pmx + t4);
        pmn = mn, pmx = mx;
        pl = l, pr = r;
        i = j + 1;
        j = i;
    }
    cout << min(mn, mx) + p[n+1].first - p[0].first << '\n';
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