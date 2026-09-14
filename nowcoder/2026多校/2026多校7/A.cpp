/*
标签：贪心

思路：异或对所有数位独立，找出哪些位需要动，答案就是这些位的并
于是题目转化为找最小的数m，使得只动m中为1的数位，就能让数列单调不降
于是从高位到低位按位贪心，如果先前选的数加上比当前位低的所有数位不能满足题意，当前位必须是1
如果不加当前位也能满足要求，说明这一位不需要

要把数列变成单调不降，这个可以贪心
对于a_i>a_{i+1}，a_{i+1}变成比a_i大并靠近a_i的数一定更优，这样可以给a_{i+2}更大空间
a[i]&(~mask)是把所有能动的数位改成0，是最小值，同理，再|mask是最大值
如果最大值都比上一个pre小，说明当前位必须是1

再次按位贪心，找比pre大的最小的数，从最小值开始
把比当前位低的所有位中可以动的位取出，如果这些位全加入也小于pre，该位必须是1

单组时间：O(900n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
int n, a[N];
bool check(int mask)
{
    int pre = 0;
    for (int i = 1; i <= n; i++)
    {
        int mx = (a[i] & (~mask)) | mask;
        if (mx < pre)
        {
            return false;
        }
        int cur = a[i] & (~mask);
        for (int j = 30; j >= 0; j--)
        {
            if ((mask >> j) & 1)
            {
                int nmask = mask & ((1 << j) - 1);
                if ((nmask | cur) < pre)
                {
                    cur |= (1 << j);
                }
            }
        }
        pre = cur;
    }
    return true;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 30; i >= 0; i--)
    {
        // mask代表可以动的数位
        // 先前位 + 所有低位
        int mask = ans | ((1 << i) - 1);
        if (!check(mask))
        {
            ans |= (1 << i);
        }
    }
    cout << ans << '\n';
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