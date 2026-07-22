/*
思路：为了使拼接后的字符串仍然正则，只有两种情况
第一种：左右本身均正则，可以随意拼，数量cnt，贡献cnt*cnt
第二种：左边缺右括号，右边缺左括号，数量l, r，贡献l*r

时间：O(L + nlogn) L为字符串总长度
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    map<int, ll>pre, suf;
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int l = 0, r = 0;
        for (char c : s)
        {
            if (c == '(') l++;
            else
            {
                if (l > 0) l--;
                else r++;
            }
        }
        if (l == 0 && r == 0) cnt++;
        // 左右两边都缺，不可能
        else if (l > 0 && r > 0) continue;
        else
        {
            if (l > 0) suf[l]++;
            if (r > 0) pre[r]++;
        }
    }
    ll ans = cnt * cnt;
    for (auto [x, c1] : pre)
    {
        if (suf.count(x))
        {
            int c2 = suf[x];
            ans += c1 * c2;
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