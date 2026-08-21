/*
思路：最优答案一定不小于最大值和ceil(sum/m)
由于k<=2×n，所以一张饼最多烙2次
一台一台烙饼机处理，一旦时间超过最优答案，立刻换下一台
可以保证这个策略下一张饼烙的次数<=2

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node
{
    int idx1, idx2;
    ll l, r;
}tmp;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll>a(n + 1);
    ll sum = 0, mx = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
        mx = max(mx, a[i]);
    }
    ll tar = max(mx, (sum + m - 1) / m);
    int i = 1, idx = 1;
    vector<ll>tot(m + 1);
    vector<node>ans;
    while (i <= n)
    {
        if (tot[idx] + a[i] < tar)
        {
            tmp.idx1 = i;
            tmp.idx2 = idx;
            tmp.l = tot[idx];
            tmp.r = tot[idx] + a[i];
            ans.push_back(tmp);
            tot[idx] += a[i];
            i++;
        }
        else if (tot[idx] + a[i] == tar)
        {
            tmp.idx1 = i;
            tmp.idx2 = idx;
            tmp.l = tot[idx];
            tmp.r = tar;
            ans.push_back(tmp);
            tot[idx] += a[i];
            i++, idx++;
        }
        else
        {
            tmp.idx1 = i;
            tmp.idx2 = idx;
            tmp.l = tot[idx];
            tmp.r = tar;
            ans.push_back(tmp);
            a[i] -= tar - tot[idx];
            idx++;
        }
    }
    cout << ans.size() << '\n';
    for (auto [idx1, idx2, l, r] : ans)
    {
        cout << idx1 << " " << idx2 << " ";
        cout << l << " " << r << '\n';
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