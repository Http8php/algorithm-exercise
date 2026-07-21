/*
知识点：前缀和

思路：分割点一定在中间，只要维护两段的和即可，用前缀和维护

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int>sum(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> sum[i];
        sum[i] += sum[i-1];
    }
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (sum[i] == sum[n] - sum[i]) ans++;
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