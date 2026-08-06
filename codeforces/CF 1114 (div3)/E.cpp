/*
标签：贪心，前缀和

思路：b是a的差分数组，所以实际上b的前缀和就是a
题目可以翻译成在当前前缀和cur>=1的前提下，选择尽可能小的增量，这样保证字典序最小
即ai=cur+bj>=1 -> bj>=1-cur
于是有贪心策略：cur初始为0，每次二分找bj，找不到说明无解

时间：O(nlogn)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    multiset<ll>s;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        s.insert(x);
    }
    ll sum = 0;
    vector<ll>ans;
    for (int i = 0; i < n; i++)
    {
        auto it = s.lower_bound(1 - sum);
        if (it == s.end())
        {
            cout << -1 << '\n';
            return;
        }
        sum += *it;
        ans.push_back(sum);
        s.erase(it);
    }
    for (ll x : ans)
    {
        cout << x << " ";
    }
    cout << '\n';
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