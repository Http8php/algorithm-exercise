/*
思路：由于初始数量未知，考虑倒推
如果half：交易前x 后x/2 前=后×2
halfplus：交易前x 后(x-1)/2 前=后×2+1
每次顾客付了当前苹果一半的钱

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, p;
    cin >> n >> p;
    // 半个苹果
    p /= 2;
    vector<string>op(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> op[i];
    }
    ll cur = 0, ans = 0;
    for (int i = n; i >= 1; i--)
    {
        cur *= 2;
        if (op[i] == "halfplus") cur++;
        // p减半了，cur就不用减半
        ans += cur * p;
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