/*
思路：有n台机器，每台有一个初始奖金，相当于n个独立均匀随机数
一共玩k次，选中的机器会重新生成一个新的随机奖金，所以一共生成了k个新奖金，选了n-k+1个数
所以该题目等价于在n+k−1个随机变量里面选出前k大
如果有N个独立且服从[0,m]均匀分布的随机数，把它们从大到小排序
第i大期望=(N-i+1)/(N+1)*m，代入N=n+k−1
第i大是(n+k−i)/(n+k)*m，对前k大求和就是期望

时间：O(k)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    double ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += 1.0 * (n + k - i) / (n + k);
    }
    cout << ans * m;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(10);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}