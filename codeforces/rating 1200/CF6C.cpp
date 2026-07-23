/*
思路：按题意模拟，注意如果两人在吃相邻的巧克力就可以结束了

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int l = 1, r = n;
    while (l < r - 1)
    {
        if (a[l] > a[r])
        {
            a[l] -= a[r];
            r--;
        }
        else if (a[l] < a[r])
        {
            a[r] -= a[l];
            l++;
        }
        else l++, r--;
    }
    cout << l << " " << n - l;
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