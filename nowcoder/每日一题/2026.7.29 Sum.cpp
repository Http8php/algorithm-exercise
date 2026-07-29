/*
标签：贪心

思路：每次合并最大的两个，如果合并后>0，把合并后的结果累加入答案

时间：O(nlogn)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e7 + 7;
void solve()
{
    int n;
    cin >> n;
    priority_queue<ll>q;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        q.push(x);
    }
    ll n1 = q.top();
    q.pop();
    ll n2 = q.top();
    q.pop();
    if (n1 + n2 < 0)
    {
        cout << 0 << '\n';
        return;
    }
    ll sum = n1 + n2;
    ll ans = sum % mod;
    q.push(sum);
    while (q.size() >= 2)
    {
        n1 = q.top();
        q.pop();
        n2 = q.top();
        q.pop();
        ll res = n1 + n2;
        if (res > 0) ans = (ans + res) % mod;
        q.push(res);
    }
    cout << ans << '\n';
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