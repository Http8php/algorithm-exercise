/*
标签：前后缀最小、滑动窗口

思路：由于删除的部分是开头和结尾，只保留了中间一段连续子段，考虑滑动窗口
但是数字均不同的段可能有很多，窗口的移动不好处理
发现没必要贴着边界操作，设合法区间 [l, r]，只要操作1L>=l-1，操作2R<=r+1即可
维护把左边一段全部染红的最小代价​pre和把右边一段全部染红的最小代价suf
算出所有点代价后，从右往左维护pre最小，从左往右维护suf最小

时间：O(nlogn)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<ll>a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<ll>pre(n + 1), suf(n + 2);
    for (int i = 1; i <= n; i++)
    {
        pre[i] = a[i] * i;
        suf[i] = a[i] * (n - i + 1);
    }
    for (int i = n - 1; i >= 1; i--)
    {
        pre[i] = min(pre[i+1], pre[i]);
    }
    for (int i = 2; i <= n; i++)
    {
        suf[i] = min(suf[i-1], suf[i]);
    }
    set<int>s;
    ll ans = 1e18;
    for (int r = 1, l = 1; r <= n; r++)
    {
        while (s.count(a[r]))
        {
            s.erase(a[l]);
            l++;
        }
        s.insert(a[r]);
        ans = min(ans, pre[l-1] + suf[r+1]);
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