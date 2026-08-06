/*
标签：前缀和

思路：数组中的值代表比这个数小的数的和
于是肯定包含0，因为一定有最小值
0位上的值由第二小的值决定，以此类推，所以把数排序，从小到大处理
可以维护一个前缀sum，设当前值x，上一个需要填的数数量为cnt
num=(x-sum)/cnt 即为上一个数值，因为要逻辑上最小，最后的数填num+1

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
    map<ll, ll>mp, mp2;
    bool ok = false;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
        if (a[i] == 0) ok = true;
    }
    if (!ok)
    {
        cout << -1 << '\n';
        return;
    }
    vector<ll>d;
    for (auto [x, c] : mp)
    {
        d.push_back(x);
    }
    int sz = d.size();
    ll pre = 0, sum = 0;
    for (int i = 1; i < sz; i++)
    {
        // 值算出来必须是整数且递增，不然不合法
        if ((d[i] - sum) % mp[d[i-1]] != 0)
        {
            cout << -1 << '\n';
            return;
        }
        ll num = (d[i] - sum) / mp[d[i-1]];
        if (num <= pre)
        {
            cout << -1 << '\n';
            return;
        }
        mp2[d[i-1]] = num;
        pre = num;
        sum += num * mp[d[i-1]];
    }
    mp2[d[sz-1]] = pre + 1;
    for (int i = 1; i <= n; i++)
    {
        cout << mp2[a[i]] << " ";
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