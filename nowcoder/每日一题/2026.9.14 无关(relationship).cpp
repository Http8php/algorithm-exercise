/*
标签：容斥原理、枚举

思路：题目大意为找[l, r]中与k个数都互质的数
找不互质的数更方便，数量为res，答案就是r-l+1-res
由于一个数可以被k中1个或多个数整除，所以需要容斥
规律是因子数为偶数时减去符合要求的数，奇数时加上符合要求的数
状压所有因子，枚举时枚举掩码即可

时间：O(2^k)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll l, r;
    int k;
    cin >> l >> r >> k;
    ll ans = 0;
    vector<int>a(k);
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
    }
    ll res = 0;
    for (int mask = 1; mask < (1 << k); mask++)
    {
        ll sum = 1;
        int c = 0;
        for (int i = 0; i < k; i++)
        {
            if ((mask >> i) & 1)
            {
                sum *= a[i];
                c++;
                if (sum > r) break;
            }
        }
        if (sum > r) continue;
        ll cnt = r / sum - (l - 1) / sum;
        if (c & 1) res += cnt;
        else res -= cnt;
    }
    ans = (r - l + 1) - res;
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