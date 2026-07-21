/*
知识点：前缀和

思路：可以发现，对于当前数x，位置i，只要[i+1, i+k]的范围有数，x就会被消掉
快速找到范围里有没有数，用前缀和维护

时间：O(max(n, mx))
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 10;
int cnt[N];
void solve()
{
    int n, k, mx = 0;
    cin >> n >> k;
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        // 数<=1e6，用桶计数排序
        cnt[x]++;
        mx = max(mx, x);
    }
    vector<int>pre(mx + 1);
    for (int i = 1; i <= mx; i++)
    {
        pre[i] = pre[i-1];
        if (cnt[i]) pre[i]++;
    }
    int ans = 0;
    for (int i = 1; i <= mx; i++)
    {
        if (cnt[i])
        {
            int lim = min(mx, i + k);
            if (pre[lim] - pre[i] == 0) ans += cnt[i];
        }
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