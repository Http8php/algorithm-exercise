/*
思路：和为0就是1和-1数量相同
如果哪个数数量多了，只能把相邻的这个数改掉，如果能改到相等就YES

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
    int c1 = 0, c2 = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 1) c1++;
        else c2++;
    }
    if (n % 2)
    {
        cout << "NO\n";
        return;
    } 
    if (c1 == c2)
    {
        cout << "YES\n";
        return;
    }
    int cnt = abs(c1 - c2);
    if (cnt % 2)
    {
        cout << "NO\n";
        return;
    }
    if (c1 > c2)
    {
        int mx = 1;
        for (int i = 1; i < n; i++)
        {
            if (a[i] == a[i+1] && a[i] == mx)
            {
                c1 -= 2;
                c2 += 2;
                i++;
            }
            if (c1 == c2)
            {
                cout << "YES\n";
                return;
            }
        }
    }
    else
    {
        int mx = -1;
        for (int i = 1; i < n; i++)
        {
            if (a[i] == a[i+1] && a[i] == mx)
            {
                c2 -= 2;
                c1 += 2;
                i++;
            }
            if (c1 == c2)
            {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
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