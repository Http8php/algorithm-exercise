/*
标签：不变量、找规律

思路：x=u+v，改变x,u,v三个数，x+u+v=2x，所以数组和奇偶性不变
由于拆分是把大数拆成小数，所以最后的单元素集合的元素一定<=mx
和奇偶性不变，最终只能取到与和同奇偶的
具体实现可以用x=2+(x-2)，2=1+1可以无影响地消去
于是有以下规律：
floor((mx+1)/2), sum是奇数
floor(mx/2), sum是偶数

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<ll>a(n + 1);
    ll sum = 0, mx = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
        mx = max(mx, a[i]);
    }
    if (sum & 1) cout << (mx + 1) / 2;
    else cout << mx / 2;
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