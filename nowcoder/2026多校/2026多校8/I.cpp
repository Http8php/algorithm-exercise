/*
标签：贪心，分类讨论

思路：最少人比1号大，1号初始x=a[1]+m最优
后面每组{l,r}可以分成几种情况
1.l/r初始一位比x大，m全喂l/r，比较另一个
2.m可以拆成实数，只要(x-l)+(x-r)+1>m，都比x小
3.2反之，就把m全喂一个人，只+1
最多人比1号大，1号初始x=a[1]最优
1.l/r初始一位比x大，m全喂另一个，比较
2.m可以拆成实数，只要(x-l)+(x-r)+1<=m，都比x大
3.2反之，就把m全喂一个人，+1

单组时间：O(2n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    ll m;
    cin >> n >> m;
    vector<ll>a((n << 1) + 1);
    for (int i = 1; i <= (n << 1); i++)
    {
        cin >> a[i];
    }
    ll x = a[1] + m;
    int ans = (x < a[2] ? 1 : 0);
    for (int i = 2; i <= n; i++)
    {
        int l = (i << 1) - 1, r = (i << 1);
        if (a[l] <= x)
        {
            if (a[r] > x)
            {
                ans++;
            }
            else
            {
                ll c1 = x - a[l], c2 = x - a[r];
                if (m >= c1 + c2 + 1) ans++;
            }
        }
        else
        {
            ans++;
            if (a[r] > x) ans++;
        }
    }
    cout << ans << " ";
    x = a[1];
    ans = (x < a[2] + m ? 1 : 0);
    for (int i = 2; i <= n; i++)
    {
        int l = (i << 1) - 1, r = (i << 1);
        if (a[l] <= x)
        {
            if (a[r] > x)
            {
                ans++;
                if (a[l] + m > x) ans++;
            }
            else
            {
                ll c1 = x - a[l], c2 = x - a[r];
                if (m >= c1 + c2 + 1) ans += 2;
                else if (m >= min(c1, c2) + 1) ans++;
            }
        }
        else
        {
            ans++;
            if (a[r] + m > x) ans++;
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