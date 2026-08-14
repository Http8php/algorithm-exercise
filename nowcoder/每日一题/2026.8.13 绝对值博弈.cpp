/*
标签：博弈

思路：排序后，操作相当于取大数与小数的差值，看差值是否在集合中
可以发现，能取的数是有限的，奇数Alice胜利，反之Bob胜利
哪些数能被取到，就看所有数的gcd，设这个值为g
还能被取到的数为最大的数mx/g-n

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, mx = 0;
    cin >> n;
    vector<int>a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    int g = gcd(a[1], a[2]);
    for (int i = 3; i <= n; i++)
    {
        g = gcd(g, a[i]);
    }
    int cnt = (mx / g) - n;
    cout << (cnt & 1 ? "Alice" : "Bob");
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