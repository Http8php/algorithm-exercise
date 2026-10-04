/*
标签：双指针

小trick：用a[i+n]=a[i]把环状的数组变成线性的

思路：在环状的数组中取连续一段，先拆大小为n的环成大小为2n的链
这样方便满足题目中任意切口的要求
然后就是找最长的一段满足相邻绝对值>k的数量不超过m对的区间
用双指针实现，初始l=1,r=1，维护一个cur代表当前区间有多少个>k的对
r每次右移一格，如果abs(a[r+1]-a[r])>k，cur加1
然后右移l，直到cur<=m，这时就是合法区间，记录此时的区间长度

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll>a(2 * n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i+n] = a[i];
    }
    int ans = 0, cur = 0;
    int l = 1, r = 1;
    while (r + 1 <= 2 * n)
    {
        if (abs(a[r+1] - a[r]) > k) cur++;
        r++;
        while (cur > m)
        {
            l++;
            if (abs(a[l] - a[l-1]) > k) cur--;
        }
        ans = max(ans, r - l + 1);
    }
    // 注意答案不能超过n
    if (ans > n) ans = n;
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