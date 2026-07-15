/*
知识点：滑动窗口

思路：把题目翻译过来就是找一段长为n-k的最大区间，滑动窗口解决

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll>a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int tar = n - k;
    ll sum = 0, ans = 0;
    queue<int>q;
    for (int i = 1; i <= n; i++)
    {
        sum += a[i];
        q.push(i);
        if (q.size() == tar)
        {
            ans = max(ans, sum);
            sum -= a[q.front()];
            q.pop();
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