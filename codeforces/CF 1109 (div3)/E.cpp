/*
知识点：前缀和

小trick：交替串只有0101和1010两种情况

思路：一段区间内，要把一个串改为交替串就是改与0101或1010不同的段
设当前串 00101101 模式串 01010101 则不同的地方是 01111000 只需改一次

现在题目要求查询多个区间，想到用前缀和维护区间内要改的次数是否<k
只记录连续"1"段的起点，在此基础上求前缀和即可
这样求前缀可能会少左端点在"1"段中间的情况，需要特判

时间：O(n + q)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, q;
    string s;
    cin >> n >> q >> s;
    s = " " + s;
    vector<int>d0(n + 1), d1(n + 1);
    for (int i = 1; i <= n; i++)
    {
        // 010101
        int s0 = (i % 2) ? 0 : 1;
        // 101010
        int s1 = (i % 2) ? 1 : 0;
        // 1 需要改 0 不需要改
        d0[i] = ((s[i] - '0') != s0);
        d1[i] = ((s[i] - '0') != s1);
    }
    // 记录起点，这样每段只会被记一次
    vector<int>st0(n + 1), st1(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (d0[i] && (i == 1 || !d0[i-1])) st0[i] = 1;
        if (d1[i] && (i == 1 || !d1[i-1])) st1[i] = 1;
    }
    // 前缀和
    vector<int>pre0(n + 1), pre1(n + 1);
    for (int i = 1; i <= n; i++)
    {
        pre0[i] = pre0[i-1] + st0[i];
        pre1[i] = pre1[i-1] + st1[i];
    }
    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        int c0 = pre0[r] - pre0[l-1];
        // 左边可能会在某段1的中间，需要特判一下
        if (d0[l] && l > 1 && d0[l-1]) c0++;
        int c1 = pre1[r] - pre1[l-1];
        if (d1[l] && l > 1 && d1[l-1]) c1++;
        if (min(c0, c1) <= k)
        {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
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