/*
知识点：贪心

思路：如果一段区间被翻了偶数次，相当于没翻
现在可以翻m个前缀，不妨从最长的前缀开始，如果直到前一个前缀这一段的总和<0，翻肯定比不翻更优
可以发现，我们总是能单独翻 (pre[m-1] + 1, pre[m]] 这些段，贪心成立
遍历每一个单独的段，若这一段的总和<0，则选择翻

时间：O(n + m)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll>a(n + 1);
    vector<int>b(m + 1);
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 1; i <= m; i++) cin >> b[i];
    sort(b.begin() + 1, b.end());
    for (int i = m; i > 1; i--)
    {
        // 正数和 复数绝对值和
        ll po = 0, ne = 0;
        // 检查每一段
        for (int j = b[i-1] + 1; j <= b[i]; j++)
        {
            if (a[j]) po += a[j];
            else ne -= a[j];
        }
        // 选择翻，sum = sum + ne - po - po + ne
        if (ne > po)
        {
            sum += (ne - po) * 2;
        }
    }
    // 检查 [1, pre[1]] 这一段
    ll po = 0, ne = 0;
    for (int j = 1; j <= b[1]; j++)
    {
        if (a[j]) po += a[j];
        else ne -= a[j];
    }
    if (ne > po)
    {
        sum += (ne - po) * 2;
    }
    cout << sum << '\n';
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