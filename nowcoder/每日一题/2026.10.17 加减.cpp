/*
标签：二分答案，滑动窗口，前缀和

思路：发现数量作为答案具有单调性，数量越多，所需操作次数不会下降
于是考虑二分答案，对于每一个答案mid，一定选择连续的长度为mid的区间最优
维护一个长度为mid的窗口，为使窗口内的数都变成同一个数并操作次数最小，这个数必须是中位数x
用前缀和计算操作次数cnt = 左半边长度len * x - 左半边和sum + 右半边和sum - 右半边长度len * x

时间：O(nlogn)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
int n;
ll k, a[N], sum[N];
bool check(int x)
{
    ll l = 1, r = x;
    while (r <= n)
    {
        int mid = (l + r) >> 1;
        ll tar = a[mid];
        ll cnt = 0;
        cnt += (mid - l) * tar - (sum[mid-1] - sum[l-1]);
        cnt += (sum[r] - sum[mid]) - (r - mid) * tar;
        if (cnt <= k) return true;
        l++, r++;
    }
    return false;
}
void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i-1] + a[i];
    }
    int l = 0, r = n, ans = 0;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
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