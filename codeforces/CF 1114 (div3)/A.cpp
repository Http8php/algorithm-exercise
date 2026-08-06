/*
思路：排序后，在最大值减小最小值增大的过程中，有两种情况
第一种是最大值变成中间值，第二种是最小值变成中间值，取二者最小

时间：O(1)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    vector<int>a(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (a[0] == a[1] || a[1] == a[2])
    {
        cout << 0 << '\n';
        return;
    }
    cout << min(a[1] - a[0], a[2] - a[1]) << '\n';
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