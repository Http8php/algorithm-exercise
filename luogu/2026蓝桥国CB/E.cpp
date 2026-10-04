/*
标签：前缀和

思路：多次询问区间内的答案，考虑前缀和
注意到r<=1e5，其实最长的子串也不会超过6位
只要一个子串首位非0，直接暴力往后找6位依次加入到cnt中即可
但是允许前导0，需要额外考虑

对于连续的一段0，对于后面第一个数贡献0的长度
比如005，第一个0自身贡献1个0，第二个0可以有00，也算作一个新的0
5也同理，但是一旦0不是连续的了，就不能产生贡献了
遍历字符串时，维护当前前导0个数pre，之后的数字x都是cnt[x]+=pre+1

时间：O(n + m)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
ll cnt[N];
void solve()
{
    int n, m;
    string s;
    cin >> n >> m >> s;
    s = " " + s;
    ll pre = 0, num = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '0')
        {
            cnt[0] += pre + 1;
            pre++;
        }
        else
        {
            // 子串的右端点不能超过n
            for (int j = i; j <= min(n, i + 5); j++)
            {
                num = num * 10 + (s[j] - '0');
                // 最大1e5，不然会RE
                if (num > 1e5) break;
                cnt[num] += pre + 1;
            }
            num = 0, pre = 0;
        }
    }
    for (int i = 1; i < N; i++)
    {
        cnt[i] += cnt[i-1];
    }
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        // 左端点是0，就不用减去[0,l-1]这段的贡献了
        if (l == 0) cout << cnt[r] << '\n';
        else cout << cnt[r] - cnt[l-1] << '\n';
    }
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