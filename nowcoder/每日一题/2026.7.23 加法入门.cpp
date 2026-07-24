/*
知识点：二分

思路：如果区间在同一行是Yes
还有一种情况，区间在两行但是左端点底下的值没有被换
形式上，设左端点在cur行，l+cur>r就是Yes，找cur可以二分
其余情况都是No

时间：O(logn)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    ll l, r;
    cin >> n >> l >> r;
    ll L = 0, R = n, cur = 0;
    while (L <= R)
    {
        ll mid = (L + R) >> 1;
        if (mid * (mid + 1) / 2 >= l)
        {
            cur = mid;
            R = mid - 1;
        }
        else L = mid + 1;
    }
    if (l + cur > r)
    {
        cout << "Yes\n";
        return;
    }
    cout << "No\n";
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