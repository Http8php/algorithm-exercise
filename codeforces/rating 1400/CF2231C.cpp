/*
思路：注意到任意一个数最终都可以变成0，且过程中不会变成重复的数
于是可以记录每个数变成1过程中的中间数出现次数，并记录每个ai变成该数的操作次数
取所有出现次数为n的中间数中最小的操作次数即可
注意1需要特殊处理，且只需要将第一个数能变成的数作为候选值即可，不然遍历map时会超时

单组时间：O(n(logai)^2)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    map<int, ll>mp;
    map<int, int>cnt;
    vector<int>a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    //取出候选值
    int x = a[1], cur = 0;
    // 最后是2121循环，得把2加入
    if (x == 1)
    {
        cnt[1] = 1;
        cnt[2] = 1;
        mp[2] = 1;
    }
    else
    {
        // 写成x会死循环
        while (x > 1)
        {
            mp[x] = cur++;
            cnt[x]++;
            if (x & 1) x++;
            else x /= 2;
        }
        cnt[1] = 1;
        mp[1] = cur;
    }
    for (int i = 2; i <= n; i++)
    {
        cur = 0;
        if (a[i] == 1)
        {
            cnt[1]++;
            cnt[2]++;
            mp[2]++;
        }
        else
        {
            while (a[i] > 1)
            {
                if (cnt.count(a[i]))
                {
                    cnt[a[i]]++;
                    mp[a[i]] += cur;
                }
                if (a[i] & 1) a[i]++;
                else a[i] /= 2;
                cur++;
            }
            cnt[1]++;
            mp[1] += cur;
        }
    }
    ll ans = 1e18;
    for (auto [v, c] : cnt)
    {
        if (c == n)
        {
            ans = min(ans, mp[v]);
        }
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