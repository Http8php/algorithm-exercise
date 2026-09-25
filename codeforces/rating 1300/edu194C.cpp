/*
标签：不变量、贪心

思路：x-1,y+1，它们的和不变
x ^ y = x + y - 2(x & y) 所以异或和不超过s=x+y，且这个答案肯定能做到
设最后x变成a，y变成b，ab的二进制应该没有交集，否则异或会变小
而答案是s，a和s的二进制也没有交集，就是找不超过x的s的子掩码
于是按位贪心，找s中的1，如果加入这个1数字仍然小于等于x，就加入，操作次数是x-a

单组时间：O(1)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int x, y, a = 0;
    cin >> x >> y;
    int k = x + y;
    for (int i = 29; i >= 0; i--)
    {
        if ((k >> i) & 1)
        {
            if ((a | (1 << i)) <= x)
            {
                a |= (1 << i);
            }
        }
    }
    cout << k << " " << x - a << '\n';
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