/*
知识点：贪心

思路：m=2时，a只有0, 1两种数
由于相邻两项的异或已确定，只要第一个数定下来了，整个a都确定了
答案就是两者中的最小

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int>a(n + 1), b(n);
    vector<vector<int> >ca(n + 1, vector<int>(2));
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) cin >> b[i];
    int ans = 1e9;
    for (int a1 = 0; a1 <= 1; a1++)
    {
        ca[1][a1] = a1;
        int cur = abs(ca[1][a1] - a[1]);
        for (int i = 2; i <= n; i++)
        {
            ca[i][a1] = a[i];
            if ((ca[i-1][a1] + a[i]) % m != b[i-1])
            {
                ca[i][a1]++;
                cur++;
            }
        }
        ans = min(ans, cur);
    }
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